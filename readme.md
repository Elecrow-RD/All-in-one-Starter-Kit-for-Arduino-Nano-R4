## Menu
### 1, Product picture
### 2, Product version number
### 3, product information
### 4, Use the driver module
### 5,Quick Start
### 6,Folder structure.
### 7,Pin definition

### 1, Product picture

![Crowpanel Advance ESP32 HMI AI Display](https://media-cdn.elecrow.com/media/webp_image/catalog/product/cache/b6b9577937e6a96f50e53ddc42983628/a/l/all-in-one_starter_kit_for_arduino_nano_r4_1.webp)

#### 2, Product version number

|      | Hardware | Software | Remark |
| ---- | -------- | -------- | ------ |
| 1    | V1.0     | V1.0     | latest |


### 3, product information

| Main Processor        | Arduino NANO R4                                        |
| --------------------- | ------------------------------------------------------ |
| CPU/SoC               | RA4M1(Arm® Cortex-M4®)                                 |
| System memory         | RAM32KB                                                |
| Storage               | Flash 256 kB                                           |
| Bluetooth             | None                                                   |
| WiFi                  | None                                                   |
| Interface             | TYPE-C interface, I/O pins/sockets, Crowtail interface |
| Button                | Reset                                                  |
| LED indicator light   | Reset indicator light, power indicator light           |
| Power input           | 5V input charging                                      |
| Shell material        | PP (non-toxic)                                         |
| Size                  | 195\*170*46（mm）                                      |
| Net Weight            | 415g                                                      |
| Operating temperature | 0°C to 60°C                                            |
| Storage temperature   | 0°C to 60°C                                            |



### 4, Use the driver module

| Name     | dependency library                           |
| -------- | -------------------------------------------- |
| IRremote | Arduino-IRremote-master <br />version: 4.5.0 |
| LSM6DS3  | Arduino_LSM6DS3-master<br />version=1.0.3    |
| BH1750   | BH1750<br />version: 1.3.0                   |

### 5,Quick Start
### Arduino IDE starts

1.Download the library files used by this product to the 'libraries' folder.

C:\Users\Documents\Arduino\libraries\

![2](https://github.com/user-attachments/assets/86c568bb-3921-4a07-ae91-62d7ce752e50)



2.Install the NANO R4 development board and open the program files

<img width="431" height="424" alt="Arduino_NANO_R4-2" src="https://github.com/user-attachments/assets/f746a37b-eed5-49c6-8ed2-bb3b76686284" />


3.Open the code configuration environment and burn it

<img width="848" height="598" alt="Arduino_NANO_R4-4" src="https://github.com/user-attachments/assets/9e75a2bc-2c0c-403b-af7c-47aaf147e987" />






### 6,Folder structure.

|--Eagle_SCH&PCB: Contains **Eagle CAD** schematic (`.sch`) and PCB layout (`.brd`) files. These are used for circuit design and PCB manufacturing.

|--lesson_code: Provides  code and projects to demonstrate how to use the hardware and libraries. These examples help users get started quickly.

|--libraries: Includes necessary libraries required for compiling and running the project. These libraries provide drivers and additional functionalities for the hardware.

### 7,Pin definition

#### Sensor / Module List

| No.  | Sensor / Module Name          | Quantity | Notes                            | nano pin                                                     |
| ---- | ----------------------------- | -------- | -------------------------------- | ------------------------------------------------------------ |
| 1    | Temperature & Humidity Sensor | 1        |                                  | A4/SDA<br />A5/SCL<br />I2C  ADDRESS:0X38                    |
| 2    | Button                        | 3        |                                  | A3_KEY                                                       |
| 3    | Ultrasonic Ranging Sensor     | 1        |                                  | D7_US_ECHO<br />D6_US_TRIG                                   |
| 4    | Light Sensor                  | 1        |                                  | A4/SDA<br />A5/SCL<br />I2C  ADDRESS:0X5C                    |
| 5    | Linear Potentiometer          | 1        |                                  | A0_ROTARY                                                    |
| 6    | LED (Red + Yellow + Green)    | 3        | Red + Yellow + Green             | ~D5_LED_R<br />~D10_LED_Y<br />~D11_LED_G                    |
| 7    | Buzzer                        | 1        |                                  | D3_BUZZER                                                    |
| 8    | LCD Display                   | 1        |                                  | A4/SDA<br />A5/SCL<br />I2C  ADDRESS:0X27                    |
| 9    | Infrared Remote               | 1        | Includes remote controller       | D2_IR_R                                                      |
| 10   | Relay Module                  | 1        |                                  | D4_RELAY                                                     |
| 11   | Servo Motor                   | 1        |                                  | D9_SERVO                                                     |
| 12   | Sound Sensor                  | 1        |                                  | A1_SOUND                                                     |
| 13   | 3-Axis Accelerometer          | 1        |                                  | A4/SDA<br />A5/SCL<br />I2C  ADDRESS:0x6B (pin SDO is logic High) |
| 14   | PIR Motion Sensor             | 1        |                                  | A2_PIR                                                       |
| 15   | Soil Moisture Sensor          | 1        | Separate probe, 4-wire connector | A7                                                           |
| 16   | 4-Digit Display               | 1        |                                  | A4/SDA<br />A5/SCL<br />I2C  ADDRESS:0X70                    |

