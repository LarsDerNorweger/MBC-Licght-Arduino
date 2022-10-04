#include <Arduino.h>

#ifndef Interpreter_h
#include "Interpreter.h"
#endif

#ifndef functions_h
#include "functions.h"
#endif

int e = 0;
unsigned long last = 0;

void setup()
{
  for (int i = 0; i < 22; i++)
    pinMode(i, OUTPUT);
  Serial.begin(115200);
  InitializeInterpreter();
}

void loop()
{
  if (Serial.available())
    handleMessage();
  execute();
}
