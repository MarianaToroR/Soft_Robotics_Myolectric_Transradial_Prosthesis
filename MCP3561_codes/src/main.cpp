#include "ADC_read.h"

uint8_t ChannelID;
double ADCConversion;
ADCReader ADC;

//const int IRQ = 26;
//uint8_t newData=0;

// void IRQ_data() {
//   newData=1;
// }

void setup() { //Corre una sola vez
  ADC.begin();
  ADC.configureRegisters();
  delay(50);
  //pinMode(IRQ, INPUT);
  //attachInterrupt(digitalPinToInterrupt(IRQ), IRQ_data, FALLING); // Configura la interrupción en el flanco de bajada
  //ADC.lockConfig();
  //ADC.unlockConfig();
}

void loop() {
  
  //ADC.readADC(ChannelID, ADCConversion);
  //Serial.print("ChannelID: ");
  //Serial.println(ChannelID);
  //Serial.print("ADCConversion: ");
  //Serial.println(ADCConversion);
  //delay(1);
  
}
