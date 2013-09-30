#include "BH1750FVI.h"
#include "Arduino.h"

BH1750FVI::BH1750FVI(){  
  
 }
  
  void BH1750FVI::begin(void){
   Wire.begin(); 
   I2CWriteTo(Power_On ); //Turn it On 
   pinMode(AddrPin,OUTPUT);
   digitalWrite(AddrPin,HIGH);
      
  }
  void BH1750FVI::Sleep(void){
    I2CWriteTo(Power_Down ); //Turn it off , Reset operator won't work in this mode
  }
  void BH1750FVI::Reset(void){
    I2CWriteTo(Power_On ); //Turn it on again
    I2CWriteTo(reset ); //Reset
    
  }
  void BH1750FVI::SetAddress(uint8_t add){
    switch (add){
      case Device_Address_L:
      address_value=Device_Address_L;
      digitalWrite(AddrPin,LOW);
      state=false;
      break;
      case Device_Address_H:
      address_value=Device_Address_H;
      digitalWrite(AddrPin,HIGH);
      state=true;
      break;
    }
    
  }
  void BH1750FVI::SetMode(uint8_t MODE){
    switch(MODE){
        case Continuous_H_resolution_Mode:
        break;
        case Continuous_H_resolution_Mode2:
        break;
        case Continuous_L_resolution_Mode:       
        break;
        case OneTime_H_resolution_Mode:
        break;
        case OneTime_H_resolution_Mode2:
        break;
        case OneTime_L_resolution_Mode:  
        break;
    }
    delay(10);
    I2CWriteTo(MODE);
  }
  
  uint16_t BH1750FVI::GetLightIntensity(void){
  uint16_t Intensity_value;
  if(state ==true){
  Wire.beginTransmission(Device_Address_H);
  Wire.requestFrom(Device_Address_H, 2);
  }
  if(state ==false){
  Wire.beginTransmission(Device_Address_L);
  Wire.requestFrom(Device_Address_L, 2);
  }
  Intensity_value = Wire.read();
  Intensity_value <<= 8;
  Intensity_value |= Wire.read();
  Wire.endTransmission();
  Intensity_value=Intensity_value/1.2;
  return Intensity_value;
    
  }
  
  void BH1750FVI::I2CWriteTo(uint8_t DataToSend){
    Wire.beginTransmission(address_value);
    Wire.write(DataToSend);
    Wire.endTransmission();
  }
