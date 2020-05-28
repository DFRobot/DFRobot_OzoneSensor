# DFRobot Ozone concentration sensor

This RaspberryPi ozone sensor board can communicate with RaspberryPi via IIC.<br>
ozone sensor can measure data from 0-10 PPM.<br>
ozone sensor Long service life.<br>
ozone sensor Excellent stability and anti-interference.<br>
ozone sensor High sensitivity and low power consumption.<br>
ozone sensor  Temperature compensation, excellent linear output.<br>

## DFRobot Ozone Library for RaspberryPi

Provide the Raspberry Pi library for the DFRobot_Ozone module.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)
* [History](#history)
* [Credits](#credits)

## Summary

Ozone module.

## Feature

1. The module has two modes, one is active data acquisition and the other is passive data acquisition. <br>
2. You can measure the concentration of ozone in the air. <br>

## Installation

This Sensor should work with DFRobot_Ozone on RaspberryPi. <br>
Run the program:

```
$> python get_ozone_data.py
```

## Methods

```py

  def set_mode(self ,mode):
    '''
      @brief Set mode active or passive
      @param mode: MEASURE_MODE_AUTOMATIC or MEASURE_MODE_PASSIVE(active or passive)
    '''

  def get_ozone_data(self ,collectnum):
    '''
      @brief get the ozone data,units of PPB
      @param collectnum: Collect the number
      @return  Ozone concentration, (PPB)
    '''

```
## History

May 27, 2020 - Version 1.0 released.

## Credits

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2020. (Welcome to our website)