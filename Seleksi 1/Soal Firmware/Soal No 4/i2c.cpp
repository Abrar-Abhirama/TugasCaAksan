#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(0x08);
  Wire.write("TES 1");
  Wire.endTransmission();
  Wire.beginTransmission(0x09);
  Wire.write("TES 2");
  Wire.endTransmission();
}

void loop() {
 
}
