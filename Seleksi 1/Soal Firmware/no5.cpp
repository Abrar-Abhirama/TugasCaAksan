const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

unsigned long previousMillis = 0;
const long interval = 1000;

int currentColor = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    
    switch(currentColor) {
      case 0:
        PORTB |= (1 << 1);
        break;
      case 1:
        PORTB |= (1 << 2);
        break;
      case 2:
        PORTB |= (1 << 3);
        break;
    }
    
    currentColor = (currentColor + 1) % 3;
  }
  
  for(int i = 0; i < 255; i++) {
    if(i < 128) {
      switch(currentColor) {
        case 0:
          PORTB |= (1 << 1);
          break;
        case 1:
          PORTB |= (1 << 2);
          break;
        case 2:
          PORTB |= (1 << 3);
          break;
      }
    } else {
      PORTB &= ~((1 << 1) | (1 << 2) | (1 << 3));
    }
    delayMicroseconds(100);
  }
}
