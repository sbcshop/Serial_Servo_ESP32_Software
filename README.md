# Serial_Servo_ESP32_Software
<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/esp32_banner.png?v=1718796728" />
The ESP32 S3 based Serial Servo Board is designed for precise control of up to 253 Serial Bus Servos. It features built-in Wi-Fi, Bluetooth. Ideal choice for ESP32 based community interested to build robotics projects like hexapod walkers and robotic arms, its compact design ensures compatibility with space-constrained projects.

This Github provides getting started guide for Serial Servo based on ESP32.

### Features
- Serial Servo powered by ESP32 S3 
- In build WiFi/BLE capabilities makes it perfect choice for IoT based projects
- TFT 1.14” display for user interactions
- Two slot to connect Serial Servo Motors, and easily cascade servo to connect more number of motor*
- Three Programmable Buttons to add additional control features to your project 
- Type C interface with Reset and Boot buttons available for programming purpose
- Standard 2.54” Header and DC jack options to connect 6-8.4V adapter with onboard regulator 
- Power status LED to indicate board power
- GPIOs breakout for additional peripheral interfacing
- Compact and space-saving design
- Compatible Servo Motors =>
    - [SB-SS023](https://shop.sb-components.co.uk/products/sb-serial-servo-sb-ss023-powerful-multi-purpose-digital-servo-motor?_pos=1&_sid=5cba75e00&_ss=r) - For Lightweight Projects
    - [SB-SS15](https://shop.sb-components.co.uk/products/sb-serial-servo-sb-ss15-powerful-multi-purpose-digital-servo-motor?_pos=2&_sid=5cba75e00&_ss=r) - For Heavier Applications
    - Servo Motor Key Features:
      - Real-Time Position, Load, Temperature, Speed, and Voltage feedback.
      - Servo/Motor Mode Switchable
      - High Precision And Large Torque
      - ID Range 1~253
      - 38400 bps ~ 1Mbps (1Mbps by default)

***NOTE:  Avoid Connecting More Than 6 Servos At A Time, Not Recommended Due To High Current Demand By Servos.**

For more details about Serial Servo Motor checkout [Manual](https://github.com/sbcshop/Serial_Servo_Breakout_Software/blob/main/Documents/SB_Servo_User_Manual.pdf).  

## Specification:
- **Microcontroller**: ESP32-S3 series of SoCs having Xtensa® dual-core 32-bit LX7 microprocessor
- **Connectivity**: 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE)
- **Memory**: Flash up to 16 MB, PSRAM up to 8 MB
- **Board Supply Voltage**: 5V 
- **Operating Pin Voltage**: 3.3V 
- **Operating Servo voltage**: 6~8.4V 
- **Display Size**: 1.14” 
- **Display Resolution** : 240x320 pixels
- **Display Driver**: ST7789 
- **Display Appearance**: RGB, 65K/262K
- **Temperature Range**: -20°C ~ +70°C

## Getting Started with Serial Servo Based on ESP32
### Pinout
<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/esp32_Pin.png?v=1718797005" />

- (1) Serial Servo connector
- (2) Header 2.5” input (6~8.4V DC) 
- (3) DC Jack Input (6~8.4V DC)
- (4),(5), (6) Programmable Buttons 
- (7) Boot Button
- (8) Type C for Programming/Power
- (9) Reset Button
- (10) TFT 1.14” Display
- (11) ESP32 S3 microcontroller module
- (12) Power Status LED
- (13) & (14) GPIOs and Power breakout

  
### Interfacing Details

 - _Serial Servo Bus Pins:_
   * Servo connector having +ve[6~8.4VDC], -ve[GND] and Signal pin. 
   * Serial Servo Signal pins breakout into UART RXD and TXD to connect with ESP32 UART pins,
     
     | ESP32 | Servo | Description | 
     |---|---|---|
     | TXD0/GPIO43 | Servo Bus RXD | UART communication pin |
     | RXD0/GPIO44 | Servo Bus TXD | UART communication pin |
  
- _Display interfacing with ESP32_
    | ESP32 | Display | Function |
    |---|---|---|
    | IO12 | LCD_CLK | Clock pin of SPI interface for Display|
    | IO11 | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO10 | LCD_CS | Chip Select pin of SPI interface|
    | IO13 | LCD_DC| Data/Command (MISO) pin of SPI interface|
    | IO14 | LCD_RST | Display Reset pin |
    | IO9  | BL | Backlight of display|
  
- _Buttons Interfacing_
    | ESP32 | Hardware | Function |
    |---|---|---|
    |IO0 | BOOT |Boot button |
    |IO4 | BT1 | Programmable Button |
    |IO5 | BT2 | Programmable Button |
    |IO6 | BT3 | Programmable Button |
  
- _GPIOs Breakout_
  
  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |DM   | I/O/T | RTC_GPIO20, GPIO20, U1CTS, ADC2_CH9, CLK_OUT1, _**USB_D+**_ |
  |DP   | I/O/T | RTC_GPIO19, GPIO19, U1RTS, ADC2_CH8, CLK_OUT2, _**USB_D-**_ |
  |GND  | P     | Supply Ground |
  |5V   | P     | Positive Supply, 5V |
  |3V3  | P     | Positive Supply, 3.3V |
  |GP8  | I/O/T | RTC_GPIO8, _**GPIO8**_ , TOUCH8, ADC1_CH7, SUBSPICS1  |  

  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |GP1  | I/O/T | RTC_GPIO1, _**GPIO1**_, TOUCH1, ADC1_CH0  |
  |GP2  | I/O/T | RTC_GPIO2, _**GPIO2**_, TOUCH2, ADC1_CH1  |
  |GP42 | I/O/T | _**MTMS**_ , GPIO42  |
  |GP41 | I/O/T | _**MTDI**_ , GPIO41, CLK_OUT1 |
  |GP39 | I/O/T | _**MTCK**_ , GPIO39, CLK_OUT3, SUBSPICS1 |
  |GP38 | I/O/T | _**GPIO38**_ , FSPIWP, SUBSPIWP  |

  *I-INPUT, O-OUTPUT, P-POWER & T-HIGH IMPEDENCE
  
### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
     
### 2. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/Serial_Servo_ESP32_Software/blob/main/libraries.zip) provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/Serial_Servo_ESP32_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on Serial Servo ESP32.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">
   - Checkout other examples below and build your own custom program codes using those references.

## Resources
  * [Schematic](https://github.com/sbcshop/Serial_Servo_ESP32_Hardware/blob/main/Design%20Data/SCH%20Servo%20for%20esp32.pdf)
  * [Hardware Files](https://github.com/sbcshop/Serial_Servo_ESP32_Hardware)
  * [Step File](https://github.com/sbcshop/Serial_Servo_ESP32_Hardware/blob/main/Mechanical%20Data/SERVO%20ESP32.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)
       
## Related Products  
  * [Serial Servo Pico HAT](https://shop.sb-components.co.uk/products/serial-servo-pico-hat?_pos=5&_sid=1178c9361&_ss=r)

    ![Serial_Servo_Pico_HAT](https://shop.sb-components.co.uk/cdn/shop/files/Artboard2_1.png?v=1718781807&width=150)
    
  * [Serial Servo Arduino Shield](https://shop.sb-components.co.uk/products/serial-servo-arduino-shield-1?_pos=4&_sid=1178c9361&_ss=r)

    ![Serial_Servo_Arduino_Shield](https://shop.sb-components.co.uk/cdn/shop/files/Artboard2_3.png?v=1718793718&width=150)

  * [Serial Servo Raspberry Pi HAT](https://shop.sb-components.co.uk/products/serial-servo-raspberry-pi-hat?_pos=2&_sid=c593a9981&_ss=r)

    ![Serial_Servo_Raspberry Pi_HAT](https://shop.sb-components.co.uk/cdn/shop/files/Artboard2_2.png?v=1718788805&width=150)
  
  * [Serial Servo Breakout](https://shop.sb-components.co.uk/products/serial-servo-breakout-1?_pos=3&_sid=5d47c0d83&_ss=r)

    ![Serial_Servo_Breakout](https://shop.sb-components.co.uk/cdn/shop/files/Artboard2.png?v=1718780131&width=150)


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
