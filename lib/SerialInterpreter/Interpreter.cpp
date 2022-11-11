#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef Interpreter_h
#include "Interpreter.h"
#endif

#ifndef functions_ - h
#include "functions.h"
#endif

Group *InitializeInterpreter(int pincount)
{
  Group *res = new Group[pincount];
  Group *g;
  for (int i = 0; i < pincount; i++)
  {
    g = new Group();
    g->delay = 0;
    g->lastSwitch = 0;
    g->lastpin = -1;
    g->pins = generatePinList(i + 1);
    res[i] = *g;
  }
  return res;
}

PIN *generatePinList(int count)
{
  PIN *res = new PIN[count];
  PIN *p;
  for (int i = 0; i < count; i++)
  {
    p = new PIN();
    p->enabled = 0;
    p->PINnumber = -1;
    res[i] = *p;
  }
  return res;
};

Group *Reset(Group *group, int count)
{
  for (int i = 0; i < count; i++)
  {
    group->pins[i].enabled = 0;
    group->pins[i].PINnumber = -1;
  }
};

void SetPin(Group *conf, int grpNum, int pinNum){

};

void togglePIN(PIN *pin)
{
}
void handleMessage(Group *conf, char *inp, int count, int pinCount) {}
void execute(Group *conf, int pincount){};