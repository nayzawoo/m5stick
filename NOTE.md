# Note


## Device Specification

| Resources | Parameter |
|---|---|
| ESP32 | 240MHz dual core, 600 DMIPS, 520KB SRAM, Wi-Fi, dual mode Bluetooth |
| Flash Memory | 4MB |
| Power Input | 5V @ 500mA |
| Port | TypeC x 1, GROVE(I2C+I/0+UART) x 1 |
| LCD screen | 0.96 inch, 80*160 Colorful TFT LCD, ST7735S |
| Button | Custom button x 2 |
| LED | RED LED |
| MEMS | MPU6886 |
| IR | Infrared transmission |
| MIC | SPM1423 |
| RTC | BM8563 |
| PMU | AXP192 |
| Battery | 95 mAh @ 3.7V |
| Antenna | 2.4G 3D Antenna |
| PIN port | G0, G26, G36 |
| Operating Temperature | 32°F to 104°F ( 0°C to 40°C ) |
| Net weight | 15.1g |
| Gross weight | 33g |
| Product Size | 48.2*25.5*13.7mm |
| Package Size | 55*55*20mm |
| Case Material | Plastic ( PC ) |

## Schematic

![M5StickC Schematic](assets/Schematic_m5stickc.webp)


## PinMap
**Red LED & IR transmitter & BUTTON A & BUTTON B**

<table>
 <tr><td>ESP32 chip</td><td>GPIO10</td><td>GPIO9</td><td>GPIO37</td><td>GPIO39</td></tr>
 <tr><td>Red LED</td><td>LED pin</td><td> </td><td> </td><td> </td></tr>
 <tr><td>IR transmitter</td><td> </td><td>transmitter pin</td><td> </td><td> </td></tr>
<tr><td>BUTTON A</td><td> </td><td> </td><td>button pin</td><td> </td></tr>
<tr><td>BUTTON B</td><td> </td><td> </td><td> </td><td>button pin</td></tr>
</table>

![M5StickC PinMap](assets/pinmap.png)


**TFT Screen**

*Driver IC: [ST7735S](https://github.com/m5stack/M5-Schematic/blob/master/Core/ST7735S_v1.1.pdf)*

*Resolution: 80 * 160*

<table>
 <tr><td>ESP32 chip</td><td>GPIO15</td><td>GPIO13</td><td>GPIO23</td><td>GPIO18</td><td>GPIO5</td></tr>
 <tr><td>TFT Screen</td><td>TFT_MOSI</td><td>TFT_CLK</td><td>TFT_DC</td><td>TFT_RST</td><td>TFT_CS</td></tr>
</table>

**GROVE interface**

<table>
 <tr><td>ESP32 chip</td><td>GPIO33</td><td>GPIO32</td><td>5V</td><td>GND</td></tr>
 <tr><td>GROVE interface</td><td>SCL</td><td>SDA</td><td>5V</td><td>GND</td></tr>
</table>

**Microphone ([SPM1423](https://github.com/m5stack/M5-Schematic/blob/master/Core/SPM1423HM4H-B.pdf))**

<table>
 <tr><td>ESP32 chip</td><td>GPIO0</td><td>GPIO34</td></tr>
 <tr><td>Microphone</td><td>SCL</td><td>SDA</td></tr>
</table>

**6-axis IMU ([SH200Q](https://github.com/m5stack/M5-Schematic/blob/master/Core/SH200Q.pdf)) & Power Mangement IC ([AXP192](https://github.com/m5stack/M5-Schematic/blob/master/Core/AXP192%20Datasheet%20v1.13_cn.pdf))**

<table>
 <tr><td>ESP32 chip</td><td>GPIO22</td><td>GPIO21</td>
 <tr><td>6-axis IMU (SH200Q)</td><td>SCL</td><td>SDA</td>
 <tr><td>Power Mangement IC (AXP192)</td><td>SCL</td><td>SDA</td>
</table>
