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
  int length = Serial.available();
  char *buf = (char *)malloc(sizeof(char) * length);

  for (int i = 0; i < length; i++)
  {
    char c = Serial.read();
    Serial.print(c);
    buf[i] = c == '\n' ? '\0' : c;
  }
  Serial.println(buf);
}