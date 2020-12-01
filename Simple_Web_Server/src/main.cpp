// Ref http://randomnerdtutorials.com
#include <M5StickC.h>
#include <WiFi.h>
#include "secrets.h"

// Replace with your network credentials
int LED_BUILTIN = 10; // m5stickc use GPIO10

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String ledState = "off";

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 3000ms = 3s)
const long timeoutTime = 3000;

void dump(String s)
{
  Serial.println(s);
  M5.Lcd.fillScreen(0x0000ff);
  M5.Lcd.setCursor(5, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(s);
}

void setup()
{
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Axp.ScreenBreath(10); // 7-12
  M5.Lcd.fillScreen(0x0000ff);
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(LED_BUILTIN, OUTPUT);

  // Set outputs to LOW
  digitalWrite(LED_BUILTIN, HIGH);

  String s = ssid;
  // Connect to Wi-Fi network with SSID and password
  dump("Connecting to " + s + " ...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    dump(".");
    delay(150);
    dump("..");
    delay(150);
    dump("...");
    delay(150);
  }

  String localIp = WiFi.localIP().toString().c_str();

  dump("Connected! LocalIP:" + localIp);

  server.begin();
}

void loop()
{
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    dump("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /led/on") >= 0)
            {
              ledState = "on";
              digitalWrite(LED_BUILTIN, LOW);
            }
            else if (header.indexOf("GET /led/off") >= 0)
            {
              ledState = "off";
              digitalWrite(LED_BUILTIN, HIGH);
            }

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
            client.println("<link href=\"https://unpkg.com/tailwindcss@^2/dist/tailwind.min.css\" rel=\"stylesheet\">");

            client.println("<body>");
            client.println("<div class='flex flex-col py-4 items-center'>");
            client.println("<h1 class='text-4xl'>ESP32/M5StickC Web Server</h1>");

            client.println("<p class='mt-4'>");
            String powerIcon = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\" fill=\"black\" width=\"48px\" height=\"48px\"><path d=\"M0 0h24v24H0z\" fill=\"none\"/><path d=\"M13 3h-2v10h2V3zm4.83 2.17l-1.42 1.42C17.99 7.86 19 9.81 19 12c0 3.87-3.13 7-7 7s-7-3.13-7-7c0-2.19 1.01-4.14 2.58-5.42L6.17 5.17C4.23 6.82 3 9.26 3 12c0 4.97 4.03 9 9 9s9-4.03 9-9c0-2.74-1.23-5.18-3.17-6.83z\"/></svg>";

            if (ledState == "off") {
              client.println("<p><a href=\"/led/on\"><button class=\"p-5 bg-green-500 rounded\">"+powerIcon+"</button></a></p>");
            } else {
              client.println("<p><a href=\"/led/off\"><button class=\"p-5 bg-red-500 rounded\">"+powerIcon+"</button></a></p>");
            }

            client.println("</p>");

            client.println("</div></body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    dump("Client disconnected.");
  }
}