#ifndef ADC_READ_H
#define ADC_READ_H

#include <Arduino.h>
#include <SPI.h>

#define CS 27
#define MOSI 12
#define MISO 13
#define SCK 14

class ADCReader {
public:
  ADCReader(); //Constructor de la clase

  void begin(); //Inicializa configuración SPI

  void configureRegisters();

  void lockConfig();

  void unlockConfig();

  void readADC(uint8_t &channelID, double &adcConversion);

private:
  //Registros para configurar ADC
  u_int8_t config0;
  u_int8_t config1;
  u_int8_t config2;
  u_int8_t config3;
  u_int8_t IRQ;
  u_int8_t SCAN1;
  u_int8_t SCAN2;
  u_int8_t SCAN3;
  u_int8_t TIMER1;
  u_int8_t TIMER2;
  u_int8_t TIMER3;
  uint8_t buffer_w[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t buffer_r[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t buffer_adc[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint32_t adc_conversion=0x000000;
  uint8_t channel_ID;
};

#endif