#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char fbuff[10];

void setup() {
  lcd.begin(16, 2);
  
  pinMode(9, OUTPUT);
}

void loop() {
  float temperatura = ((analogRead(A0) * 5.0 / 1024.0) - 0.5) * 100.0;
  lcd.setCursor(0, 0);
  lcd.write("T\262:");
  lcd.print(temperatura);
  
  lcd.setCursor(0, 1);
  if (temperatura > 25) {
    analogWrite(9, 255);
    lcd.print("encendido");
  } else {
    analogWrite(9, 0);
    lcd.print("apagado");
  }
  
  delay(200);
}
 
