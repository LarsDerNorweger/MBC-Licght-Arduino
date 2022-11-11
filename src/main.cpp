#include <Arduino.h>

void setup()
{
  for (int i = 0; i < 22; i++)
    pinMode(i, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  int l = Serial.available();
  if (l)
  {
    char *inp = new char[l];

    Serial.readBytes(inp, l);
    Serial.write(inp, l);
  }
}
