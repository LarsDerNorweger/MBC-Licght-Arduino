
#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef functions_h
#include "functions.h"
#endif

boolean blink(int pin, int period, int *enabled, unsigned long *lasttime)
{
  unsigned long now = millis();
  if (now - *lasttime < (unsigned long)period)
    return false;
  *enabled = *enabled ? 0 : 1;
  *lasttime = now;
  return true
}

void switchThroughArray(int **pins, int lastpin, int count,int lasttime, int delay)
{
  if (lastpin + 1 >)
}