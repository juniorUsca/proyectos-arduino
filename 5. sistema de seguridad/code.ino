#include <Keypad.h>
#include <Servo.h>

Servo servo_10;

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols]= {5,4,3,2};

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

char codigoSecreto[4] = {'2','2','0','6'};
int posicion = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    Serial.println(keypressed);
    if (keypressed == codigoSecreto[posicion])
    {
      posicion += 1;
    }
    
    if (keypressed == 'A')
    {
      if (posicion == 4) {
        servo_10.attach(10);
        servo_10.write(180);
      } else {
        tone(11, 1000);
      }
      posicion = 0;
    }
    
  }
  delay(200);
}

