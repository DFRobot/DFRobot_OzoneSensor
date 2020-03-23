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
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */
#ifndef __DFRobot_OzoneSensor_H__
#define __DFRobot_OzoneSensor_H__

#define           ADDRESS_0                 0x70           // iic slave Address
#define           ADDRESS_1                 0x71
#define           ADDRESS_2                 0x72
#define           ADDRESS_3                 0x73

#define           MEASURE_MODE_AUTOMATIC    0x00           // active  mode
#define           MEASURE_MODE_PASSIVE      0x01           // passive mode

#define           AUTO_READ_DATA            0x00           // auto read ozone data
#define           PASSIVE_READ_DATA         0x01           // passive read ozone data


#define           MODE_REGISTER             0x03           // mode register
#define           SET_PASSIVE_REGISTER      0x04           // read ozone data register

#define           AUTO_DATA_HIGE_REGISTER   0x09           // AUTO data high eight bits
#define           AUTO_DATA_LOW_REGISTER    0x0A           // AUTO data Low  eight bits

#define           PASS_DATA_HIGE_REGISTER   0x07           // AUTO data high eight bits
#define           PASS_DATA_LOW_REGISTER    0x08           // AUTO data Low  eight bits

#define           OCOUNT                    100             // Ozone Count Value

class DFRobot_OzoneSensor{
public:
  DFRobot_OzoneSensor();
  ~DFRobot_OzoneSensor();
  bool     begin(uint8_t addr = ADDRESS_0);
  void     SetModes(uint8_t Mode);
  int16_t  ReadOzoneData(uint8_t CollectNum = 20);
  
private:
  void     i2cWrite(uint8_t Reg , uint8_t pdata);
  int16_t  i2cReadOzoneData(uint8_t Reg);
  int      OzoneData[OCOUNT] = {0x00};
  int      getAverageNum(int bArray[], int iFilterLen);
  uint8_t  _addr;                               // IIC Slave number
  uint8_t  _M_Flag = 0;                         // Mode flag
};
#endif