#ifndef Arduino_h
#include <Arduino.h>
#endif

#define Interpreter_h

const int PINCOUNT = 20;

struct PIN
{
  int enabled;
  int delay;
  int group;
  unsigned long lastSwitch;
};

enum STATES
{
  setPIN,
  End = 1024,
  UnkownCommand = 2048,
  WrongArguments = 2049,
  next = 4096,
};

void InitializeInterpreter();

void handleMessage();
void execute();

STATES setPin(int inp);
STATES end();
