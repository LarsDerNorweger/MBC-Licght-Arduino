#ifndef Arduino_h
#include <Arduino.h>
#endif

#define Interpreter_h

const int PINCOUNT = 20;

struct Group
{
  int delay;
  int lastpin;
  PIN *pins;
  unsigned long lastSwitch;
};

struct PIN
{
  boolean enabled;
  int PINnumber;
};

enum MODES
{
  setPin = 0x01,
  setGroup = 0x02,
};
Group *InitializeInterpreter(int);
PIN *generatePinList(int count);

void SetPin(Group *, int, int);
Group *Reset(Group *, int);
void togglePIN(PIN *pin);

void handleMessage(Group *, char *, int, int);
void execute(Group *);
