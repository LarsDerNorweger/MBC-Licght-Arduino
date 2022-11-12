#include <Arduino.h>

#include "Interpreter.h"
#include "DataHelper.h"

Group *conf;

SerialData *data;
SerialResponse *res;

char *convertMode(STATE mode)
{
  return new char[1]{(char)mode};
}

void setup()
{
  for (int i = 0; i < 22; i++)
    pinMode(i, OUTPUT);
  Serial.begin(115200);
  conf = nullptr;
}

void loop()
{
  if (Serial.available())
  {
    deleteSerialResponse(res);
    deleteSerialData(data);
    data = readSerial();
    res = handleMessage(conf, data, 20);
    sendSerialAndDelete(convertResponse(res));
  }
}
