#include <Arduino.h>
#include "SerialReceiver.h"

struct SerialData
{
  int PIN;
  int MODE;
  int VALUE;
};
SerialReceiver *ser;

void setup()
{
  for (int i = 0; i < 14; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
    ser = new SerialReceiver();
  }
  Serial.begin(9600);
}

void loop()
{
  ser->checkForReceive();
  // put your main code here, to run repeatedly:
}
