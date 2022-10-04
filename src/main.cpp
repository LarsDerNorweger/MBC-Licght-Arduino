#include <Arduino.h>

#ifndef Interpreter
#include "Interpreter.h"
#endif

struct SerialData
{
  int PIN;
  int MODE;
  int VALUE;
};

Interpreter *inter = nullptr;

void setup()
{
  for (int i = 0; i < 22; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
  inter = new Interpreter();
}

void loop()
{
  if (Serial.available())
    inter->handleMessage();
  inter->execute();
}
