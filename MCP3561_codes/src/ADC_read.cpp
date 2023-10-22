#include "ADC_read.h"

ADCReader::ADCReader() {

}

void ADCReader::begin() {
  // Inicializa el bus SPI personalizado
  SPI.begin(SCK, MISO, MOSI);

  // 25 kHz, MSB primero, Modo 1
  SPI.beginTransaction(SPISettings(25000, MSBFIRST, SPI_MODE0));
  
  Serial.begin(9600);
  
  pinMode (CS, OUTPUT);
  digitalWrite(CS, HIGH); // Deseleccionar el MCP3561 inicialmente
}

void ADCReader::configureRegisters() {
  //Configuraciones de registros:
  config0=0x23; //reg add: 0x1 //reg. value: 0010 0011
  config1=0x0C; //reg add: 0x2 //reg. value: 0000 1100
  config2=0x8B; //reg add: 0x3 //reg. value: 1000 1011
  config3=0xF0; //reg add: 0x4 //reg. value: 1111 0000
  IRQ=0x00; //reg add: 0x5 //reg. value: 0000 0000
  SCAN1=0xC0; //reg add: 0x7
  SCAN2=0x00;
  //SCAN3=0x02; //Lea solo canal 1
  SCAN3=0x01; //Lea solo canal 0
  //SCAN3=0x03; //Lea ambos canales
  TIMER1=0x00; //reg. add: 0x8
  TIMER2=0x00;
  TIMER3=0x80;
  //Se configuran los registros congig0-IRQ
  digitalWrite(CS, LOW);
  buffer_w[0] = 0x46;     // Asigna 0x46 al primer elemento del arreglo
  buffer_w[1] = config0; // Asigna el valor de config0 al segundo elemento del arreglo
  buffer_w[2] = config1; // Asigna el valor de config1 al tercer elemento del arreglo
  buffer_w[3] = config2; // Asigna el valor de config2 al cuarto elemento del arreglo
  buffer_w[4] = config3; // Asigna el valor de config3 al quinto elemento del arreglo
  buffer_w[5] = IRQ;
  Serial.print("Instruction Write: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_w, 6); //Se mandan 6 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Write answer: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se leen los registros config0-IRQ que se acaban de configurar
  digitalWrite(CS, LOW);
  buffer_r[0] = 0x47;     // Asigna 0x47 al primer elemento del arreglo
  buffer_r[1] = 0;
  buffer_r[2] = 0;
  buffer_r[3] = 0;
  buffer_r[4] = 0;
  buffer_r[5] = 0;
  buffer_r[6] = 0;
  Serial.print("Instruction Read: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_r, 6); //Se leen 6 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Read answer: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se configuran los registros SCAN1-TIMER3 
  digitalWrite(CS, LOW);
  buffer_w[0] = 0b01011110;
  buffer_w[1] = SCAN1;
  buffer_w[2] = SCAN2;
  buffer_w[3] = SCAN3;
  buffer_w[4] = TIMER1;
  buffer_w[5] = TIMER2;
  buffer_w[6] = TIMER3;
  Serial.print("Instruction Write: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_w, 7); //Se escriben 7 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Write answer: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se leen los registros SCAN1-TIMER3 que se acaban de configurar
  digitalWrite(CS, LOW);
  buffer_r[0] = 0x5F;
  buffer_r[1] = 0;
  buffer_r[2] = 0;
  buffer_r[3] = 0;
  buffer_r[4] = 0;
  buffer_r[5] = 0;
  buffer_r[6] = 0;
  Serial.print("Instruction Read: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_r, 7); //Se leen 7 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Read answer: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  //Esta lectura no la hace bien, pero cuando se miran los bits de datos de transmisión, sí se lee correctamente el registro
  
  delay(5000);

}

void ADCReader::lockConfig(){
  //Se lee el registro, deberá ser 0xA5 si se desea desbloquear los registros de configuración
  digitalWrite(CS, LOW);
  buffer_r[0] = 0x75;
  buffer_r[1] = 0;
  Serial.print("Instruction Read: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_r, 2); //Se leen 2 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Read answer: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se escribe en 0x00
  digitalWrite(CS, LOW);
  buffer_w[0] = 0x76;
  buffer_w[1] = 0;
  Serial.print("Instruction Write: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_w, 2); //Se escriben 2 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Write answer: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se lee el registro como quedó configurado
  digitalWrite(CS, LOW);
  buffer_r[0] = 0x75;
  buffer_r[1] = 0;
  Serial.print("Instruction Read: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_r, 2); //Se leen 2 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Read answer: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");

  delay(5000);
}

void ADCReader::unlockConfig(){
  //Se escribe en 0xA5
  digitalWrite(CS, LOW);
  buffer_w[0] = 0x76;
  buffer_w[1] = 0xA5;
  Serial.print("Instruction Write: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_w, 2); //Se escriben 2 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Write answer: ");
  for (int i = 0; i < sizeof(buffer_w); i++) {
    Serial.print(buffer_w[i], HEX);
  }
  Serial.println("");

  delay(10);

  //Se lee el registro como quedó configurado
  digitalWrite(CS, LOW);
  buffer_r[0] = 0x75;
  buffer_r[1] = 0;
  Serial.print("Instruction Read: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");
  SPI.transfer(&buffer_r, 2); //Se leen 2 bytes de datos
  digitalWrite(CS, HIGH);
  Serial.print("Read answer: ");
  for (int i = 0; i < sizeof(buffer_r); i++) {
    Serial.print(buffer_r[i], HEX);
  }
  Serial.println("");

  delay(1000);
}

void ADCReader::readADC(uint8_t &channelID, double &adcConversion) {
  //Se lee el registro que guarda la data del ADC en un loop
  digitalWrite(CS, LOW);
  buffer_adc[0]=0x43;
  buffer_adc[1]=0;
  buffer_adc[2]=0;
  buffer_adc[3]=0;
  buffer_adc[4]=0;
  SPI.transfer(&buffer_adc, 5); //Se leen 5 bytes de datos
  digitalWrite(CS, HIGH);
  for (int i = 2; i < 5; i++) {
    if (i==2){
      adc_conversion = (adc_conversion << 8) | 00;
      adc_conversion = (adc_conversion << 8) | buffer_adc[i];}
    else{adc_conversion = (adc_conversion << 8) | buffer_adc[i];}
  }
  channelID = buffer_adc[1] & 0xF0;
  channelID = channelID / 16;
  adcConversion = adc_conversion*(3.3/8388608);
}




