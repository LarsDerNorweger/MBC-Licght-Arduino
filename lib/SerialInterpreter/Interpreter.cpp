#ifndef Arduino_h
#include <Arduino.h>
#endif
#ifndef Interpreter
#include "Interpreter.h"
#endif

Interpreter::Interpreter()
{
  PIN *p;
  for (int i = PINCOUNT - 1; i >= 0; i--)
  {
    p = new PIN;
    p->delay = 0;
    p->enabled = 0;
    p->group = 0;
    m_pins[i] = p;
  }
}

void Interpreter::handleMessage()
{
  int inp = Serial.readString().toInt();
  if (Next)
  {
    count++;
    switch (state)
    {
    case setPIN:
      Serial.println(setPin(inp));
      break;

    default:
      Serial.println(States::Error);
      break;
    }
  }
  else
  {

    state = (States)inp;
    Next = true;
    Serial.println(States::next);
  }
}

States Interpreter::setPin(int inp)
{
  switch (count)
  {
  case 1:
    if (inp < 0 || inp >= PINCOUNT)
    {
      end();
      return States::Error;
    }
    data = m_pins[inp];
    return States::next;

  case 2:
    data->enabled = inp;
    return States::next;

  case 3:
    data->delay = inp;
    return end();

  default:
    return States::Error;
  }
}

void Interpreter::execute()
{
  if (!change)
    return;
  for (int i = PINCOUNT - 1; i >= 0; i--)
  {
    PIN *d = m_pins[i];
    digitalWrite(i, d->enabled ? HIGH : LOW);
  }
}

States Interpreter::end()
{
  count = 0;
  state = End;
  Next = false;
  change = true;
  return States::End;
}