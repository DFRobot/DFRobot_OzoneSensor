# DFRobot_OzoneSensor
DFRobot's OzoneSensor

## DFRobot_OzoneSensor Library for Arduino
---------------------------------------------------------
Arduino library is provided for reading ozone concentrations through I2C and gas sensors.
Used to read the ozone and oxygen concentrations of the current module


## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_OzoneSensor.
Download the zip file first to use this library and uncompress it to a folder named DFRobot_OzoneSensor.

## Methods

```C++
class DFRobot_OzoneSensor{  
public:

 /*
  * @brief initialization parameters for i2c.
  *
  * @param addr is I2c device number.
  *     iic slave Address, The default is ADDRESS 3.
  *     ADDRESS_0               0x70           // iic slave Address
  *     ADDRESS_1               0x71
  *     ADDRESS_2               0x72
  *     ADDRESS_3               0x73
  *
  * @return true and false.
  */
   bool begin(uint8_t addr);

 /*
  * @brief Set mode Active or passive measurement.
  *
  * @param Mode is Active or passive.
  *    MEASURE_MODE_AUTOMATIC                 // active  mode
  *    MEASURE_MODE_PASSIVE                   // passive mode
  */
   void SetModes(uint8_t Mode);


 /*
  * @brief read Ozone data.
  *
  * @param CollectNum is the number of data collected,(The default value is 20)
  *    COLLECT_NUMBER                         // The collection range is 1-100
  *
  * @return Ozone concentration: one part per billion (PPB).
  */
   int16_t  ReadOzoneData(uint8_t CollectNum = 20);
 
};

```
## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266|      √       |              |             | 
ATMEGA2560  |      √       |             |            | 
Arduino uno |       √      |             |            | 
Leonardo  |      √       |              |             | 

## History

- October 10, 2019 - Version 0.2 released.


## Credits

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))