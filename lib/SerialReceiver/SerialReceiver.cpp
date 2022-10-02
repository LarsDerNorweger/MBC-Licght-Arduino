#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef SerialReceiver
#include "SerialReceiver.h"
#endif

SerialReceiver::SerialReceiver() {}
SerialReceiver::~SerialReceiver() {}

void SerialReceiver::checkForReceive()
{
  if (!Serial.available())
    return;
  String Serbuf = Serial.readString();
  int lenght = Serbuf.length();
  int start = 0;
  int count = 0;

  Data *res = new Data;

  for (int i = 0; i < lenght; i++)
  {
    char c = Serbuf[i];
    if (c == ',')
    {
      if (count == 0)
        res->PIN = Serbuf.substring(start, i).toInt();
      else if (count == 1)
        res->ENABLED = Serbuf.substring(start, i).toInt();
      count++;
      start = i + 1;
    }
  }
  execute(res);
}

void SerialReceiver::execute(Data *inp)
{
  digitalWrite(inp->PIN, inp->ENABLED ? HIGH : LOW);
  delete inp;
};