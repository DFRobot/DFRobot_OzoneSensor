 /*!
  * @file  ReadOzoneData.ino
  * @brief Reading ozone concentration, A concentration of one part per billion (PPB).
  * @n step: we must first determine the iic device address, will dial the code switch A0, A1 (ADDRESS_0 for [0 0]), (ADDRESS_1 for [1 0]), (ADDRESS_2 for [0 1]), (ADDRESS_3 for [1 1]).
  * @n       Then configure the mode of active and passive acquisition, Finally, ozone data can be read.
  * @n note: it takes time to stable oxygen concentration, about 3 minutes.
  *
  * @n The experimental phenomenon is to print one billionth of the ozone concentration on the serial port.
  * @n Because the value measured by the sensor is less than 10000, the value obtained will not be greater than 10000
  *
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     V0.2
  * @date        2019-10-10
  * @get         from https://www.dfrobot.com
  * @url   */
#include "DFRobot_OzoneSensor.h"

#define COLLECT_NUMBER   20              // collect number, the collection range is 1-100
#define Ozone_IICAddress ADDRESS_3
/*   iic slave Address, The default is ADDRESS_0
       ADDRESS_0               0x70      // iic device address
       ADDRESS_1               0x71
       ADDRESS_2               0x72
       ADDRESS_3               0x73
*/
DFRobot_OzoneSensor Ozone;
void setup() 
{
  Serial.begin(9600);
  while(!Ozone.begin(Ozone_IICAddress)) {
    Serial.println("I2c device number error !");
    delay(1000);
  }  Serial.println("I2c connect success !");
/*   Set iic mode, active mode or passive mode
       MEASURE_MODE_AUTOMATIC            // active  mode
       MEASURE_MODE_PASSIVE              // passive mode
*/
    Ozone.SetModes(MEASURE_MODE_PASSIVE);
}


void loop() 
{
/*   Smooth data collection
       COLLECT_NUMBER                    // The collection range is 1-100
*/
  int16_t ozoneConcentration = Ozone.ReadOzoneData(COLLECT_NUMBER);
  Serial.print("Ozone concentration is ");
  Serial.print(ozoneConcentration);
  Serial.println(" PPB.");
  delay(1000);
}