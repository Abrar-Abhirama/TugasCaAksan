#include <SPI.h>

#define CS1 10 
#define CS2 9   

void setup() {
  // Memulai komunikasi SPI
  SPI.begin();
  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  Serial.begin(9600);


  digitalWrite(CS1, LOW);  
  SPI.transfer("TES");
  digitalWrite(CS1, HIGH); 

  // Mengirimkan data ke perangkat SPI kedua
  digitalWrite(CS2, LOW); 
  SPI.transfer("TES 2");
  digitalWrite(CS2, HIGH); 
}

void loop() {

}
