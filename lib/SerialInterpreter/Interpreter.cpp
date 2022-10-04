#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef Interpreter_h
#include "Interpreter.h"
#endif

#ifndef functions_ - h
#include "functions.h"
#endif

PIN *PinConfiguration[PINCOUNT];
STATES state = STATES::End;
int ChangeDetected = 0;
int count = 0;
PIN *selectedPin = nullptr;

void InitializeInterpreter()
{
  Serial.setTimeout(5);
  PIN *p;
  for (int i = PINCOUNT - 1; i >= 0; i--)
  {
    p = new PIN;
    p->delay = 0;
    p->enabled = 0;
    p->group = 0;
    p->lastSwitch = 0;
    PinConfiguration[i] = p;
  }
}

void handleMessage()
{
  int inp = Serial.readString().toInt();
  if (state == STATES::End)
  {
    state = (STATES)inp;
    Serial.println(STATES::next);
    return;
  }

  count++;
  switch (state)
  {
  case setPIN:
    Serial.println(setPin(inp));
    break;

  default:
    Serial.println(STATES::UnkownCommand);
    break;
  }
}

STATES setPin(int inp)
{
  switch (count)
  {
  case 1:
    if (inp < 0 || inp >= PINCOUNT)
    {
      end();
      return STATES::UnkownCommand;
    }
    selectedPin = PinConfiguration[inp];
    return STATES::next;

  case 2:
    selectedPin->enabled = inp;
    return STATES::next;

  case 3:
    selectedPin->delay = inp;
    return end();

  default:
    return STATES::WrongArguments;
  }
}

void execute()
{
  for (int i = PINCOUNT - 1; i >= 0; i--)
  {
    PIN *d = PinConfiguration[i];
    if (d->delay > 0)
      blink(i, d->delay, &d->enabled, &d->lastSwitch);
    digitalWrite(i, d->enabled ? HIGH : LOW);
  }
}

STATES end()
{
  count = 0;
  state = STATES::End;
  ChangeDetected = true;
  return STATES::End;
}