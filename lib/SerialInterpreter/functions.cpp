
#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef functions_h
#include "functions.h"
#endif

void blink(int pin, int period, int *enabled, unsigned long *lasttime)
{
  unsigned long now = millis();
  if (now - *lasttime < (unsigned long)period)
    return;
  *enabled = *enabled ? 0 : 1;
  *lasttime = now;
}