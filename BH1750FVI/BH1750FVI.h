

/* This library for Digital Light sensor BH1750FVI

 use I2C Communication protocal , SDA,SCL Are required 
 
  to interface with this sensor
  
  pin configuration :
  
  VCC >>> 3.3V
  SDA >>> A4 
  SCL >>> A5
  ADDR >> A3 "Optional"
  GND >>> gnd
  
  written By : Mohannad Rawashdeh
  www.genotronex.com
  */
  
#ifndef BH1750FVI_h
#define BH1750FVI_h

#include "Arduino.h"

#include "Wire.h"

#define Device_Address_L 0x23 // Device address when address pin LOW
#define Device_Address_H 0x5C // Device address when address pin LOW
//all command here taken from Data sheet OPECODE Table page 5
#define Power_Down 0x00

#define Power_On 0x01

#define reset 0x07

#define Continuous_H_resolution_Mode  0x10

#define Continuous_H_resolution_Mode2  0x11

#define Continuous_L_resolution_Mode  0x13

#define OneTime_H_resolution_Mode  0x20

#define OneTime_H_resolution_Mode2  0x21

#define OneTime_L_resolution_Mode  0x23//As well as address value

#define AddrPin 17 // Address pin enable
  class BH1750FVI {    
    public:
    BH1750FVI();
    void begin(void);
    void Sleep(void); 
    void SetMode(uint8_t MODE);
    void Reset(void);
    void SetAddress(uint8_t add);
    uint16_t GetLightIntensity(void);
    
    private:
    void I2CWriteTo(uint8_t DataToSend);  
    byte address_value;
    boolean state;
  };
  #endif



