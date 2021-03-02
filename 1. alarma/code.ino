int encendido = false;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  int boton = digitalRead(4);
  if ( boton == HIGH ) // boton presionado
  {
    encendido = !encendido; // activamos o desactivamos el sistema
  }

  if (encendido == true)
  {
    digitalWrite(13, HIGH); // enciende led
  }
  else {
    digitalWrite(13, LOW); // apaga led
  }

  
  int pir = digitalRead(2);
  // si el sistema esta activo y detecta movimiento suena
  if (encendido == true && pir == HIGH)
  {
    tone(9, 1000);
  }
  else {
    noTone(9);
  }
  delay(200);
}
