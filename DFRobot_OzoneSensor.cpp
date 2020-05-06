/*

  MIT License

  Copyright (C) <2019> <@DFRobot ZhiXinLiu>


  Permission is hereby granted, free of charge, to any person obtaining a copy of this

  software and associated documentation files (the "Software"), to deal in the Software

  without restriction, including without limitation the rights to use, copy, modify,

  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to

  permit persons to whom the Software is furnished to do so.



  The above copyright notice and this permission notice shall be included in all copies or

  substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,

  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR

  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE

  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,

  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */
#include <Arduino.h>
#include <Wire.h>
#include "DFRobot_OzoneSensor.h"

DFRobot_OzoneSensor::DFRobot_OzoneSensor()
{
}
DFRobot_OzoneSensor::~DFRobot_OzoneSensor()
{
}


/* join i2c bus (address optional for master) */
bool DFRobot_OzoneSensor::begin(uint8_t addr)
{
  this->_addr = addr;              // Set the host address 
  Wire.begin();                     // connecting the i2c bus 
  Wire.beginTransmission(_addr);
  if(Wire.endTransmission() == 0) {
    delay(100); return true;
  }
  delay(100);
  return false;
}


/* Write data to the i2c register  */
void DFRobot_OzoneSensor::i2cWrite(uint8_t Reg , uint8_t pdata)
{
  Wire.beginTransmission(_addr);
  Wire.write(Reg);
  Wire.write(pdata);
  Wire.endTransmission();
}


/* i2c Read ozone concentration data */
int16_t DFRobot_OzoneSensor::i2cReadOzoneData(uint8_t Reg)
{
  uint8_t i = 0;
  uint8_t rxbuf[10]={0};
  Wire.beginTransmission(_addr);
  Wire.write(Reg);
  Wire.endTransmission();
  delay(100);
  Wire.requestFrom(_addr, (uint8_t)2);
    while (Wire.available())
     rxbuf[i++] = Wire.read();
  return ((int16_t)rxbuf[0] << 8) + rxbuf[1];
}


/* Set active and passive mode */
void DFRobot_OzoneSensor::SetModes(uint8_t Mode)
{
  if(Mode == MEASURE_MODE_AUTOMATIC) {                            // configure to active mode
    i2cWrite(MODE_REGISTER , MEASURE_MODE_AUTOMATIC);
    delay(100);   _M_Flag = 0;                                    // Active mode flag bit
  }else if (Mode == MEASURE_MODE_PASSIVE){                        // Configure to passive mode
    i2cWrite(MODE_REGISTER , MEASURE_MODE_PASSIVE); 
    delay(100);   _M_Flag = 1;                                    // Passive mode flag bit
  }else {
    return;
  }
}


/* Reading ozone concentration */
int16_t DFRobot_OzoneSensor::ReadOzoneData(uint8_t CollectNum)
{
  static uint8_t i = 0 ,j = 0;
  if (CollectNum > 0) {
    for(j = CollectNum - 1;  j > 0; j--) {  OzoneData[j] = OzoneData[j-1]; }
    if(_M_Flag == 0) {        
      i2cWrite(SET_PASSIVE_REGISTER , AUTO_READ_DATA);      delay(100);    // read active data in active mode
      OzoneData[0] = i2cReadOzoneData(AUTO_DATA_HIGE_REGISTER);
    }else if(_M_Flag == 1) {
      i2cWrite(SET_PASSIVE_REGISTER , PASSIVE_READ_DATA);   delay(100);    // read passive data in passive mode, first request once, then read the data
      OzoneData[0] = i2cReadOzoneData(PASS_DATA_HIGE_REGISTER);
    }
    if(i < CollectNum) i++;
    return getAverageNum(OzoneData, i);
  }else if(CollectNum <= 0 || CollectNum > 100){
   return -1;
  }
}


/* Get the average data */
int DFRobot_OzoneSensor::getAverageNum(int bArray[], int iFilterLen) 
{
  uint8_t i = 0;
  unsigned long bTemp = 0;
  for(i = 0; i < iFilterLen; i++) {
    bTemp += bArray[i];
  }
  return bTemp / iFilterLen;
}


