int const PIN_GAS = A1;
int LED_VERDE = 7;
int LED_AMARILLO = 6;
int LED_PELIGRO1 = 5;
int LED_PELIGRO2 = 4;
void setup(){
  	pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_PELIGRO1, OUTPUT);
    pinMode(LED_PELIGRO2, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    int valor = analogRead(PIN_GAS);
    Serial.println("valor real:" + String(valor));
    valor = map(valor, 85, 300, 0, 100);
    Serial.println("porcentaje: " + String(valor));
    digitalWrite(LED_VERDE, HIGH);
  	digitalWrite(LED_AMARILLO, valor >= 10 ? HIGH : LOW);
    digitalWrite(LED_PELIGRO1, valor >= 40 ? HIGH : LOW);
    digitalWrite(LED_PELIGRO2, valor >= 80 ? HIGH : LOW);
    delay(250);
}
