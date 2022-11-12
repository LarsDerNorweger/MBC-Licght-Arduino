#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef Interpreter_h
#include "Interpreter.h"
#endif

STATE checkCommand(SerialData *data, STATE mode)
{

  switch (mode)
  {
  case STATE::setGroup:
    if ((int)data->data[1] + 4 == data->dataLength)
      return STATE::OK;
    return STATE ::inkonsitentCommand;

  default:
    return STATE::unkown;
  }
}

SerialResponse *handleMessage(Group *conf, SerialData *data, int pinCount)
{
  STATE mode = (STATE)data->data[0];
  // Group g;
  STATE res = checkCommand(data, mode);

  if (res != STATE::OK)
  {
    SerialResponse *r = new SerialResponse;
    r->state = res;
    r->dataLenght = 0;
    return r;
  }

  switch (mode)
  {
  case STATE::setGroup:
    return handleGroupSet(conf, data, pinCount);

  default:
    SerialResponse *r = new SerialResponse;
    r->state = STATE::unkown;
    r->dataLenght = 0;
    return r;
  }
}

SerialResponse *handleGroupSet(Group *conf, SerialData *data, int pinCount)
{
  SerialResponse *r = new SerialResponse;
  r->state = STATE::OK;
  r->dataLenght = data->dataLength;
  r->data = data->data;
  return r;
}

void execute(Group *conf, int pincount){};