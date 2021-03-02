

int dia = false;
int contador = 0;

void setup()
{
  pinMode(A0, INPUT);

  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  int luz = analogRead(A0);
  if (luz > 850)
  {
    dia = true;
  } else {
    dia = false;
    contador = 0;
  }
  
  if (dia == true && contador == 0) {
    contador = millis();
  }
  
  if (dia == true && contador != 0) {
    int actual = millis();
    //Serial.println(actual-contador);
    if (actual - contador > 3000) {
      digitalWrite(7, LOW);
    }
    else {
      digitalWrite(7, HIGH);
    }
    
    if (actual - contador > 5000) {
      digitalWrite(12, LOW);
    }
    else {
      digitalWrite(12, HIGH);
    }
    
    if (actual - contador > 5000) {
      tone(9, 1000);
    }
    else {
      noTone(9);
    }
    
  }
  

//  delay(20);
}
