#ifndef Arduino_h
#include <Arduino.h>
#endif

#define MBC_DataModell

struct PIN
{
  boolean enabled;
  int PINnumber;
  unsigned long lastSwitch;
};

struct Group
{
  int delay;
  int lastpin;
  PIN *pins;
  unsigned long lastSwitch;
};

struct Configuration
{
  PIN *pins;
  Group *groups;
};