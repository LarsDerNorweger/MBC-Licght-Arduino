#ifndef SerialHelper_h
#include "SerialHelper.h"
#endif

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef States_h
#include "States.h"
#endif

#ifndef MBC_DataModell
#include "DataModell.h"
#endif

#define Interpreter_h

const int PINCOUNT = 20;

STATE checkCommand(SerialData *data, STATE mode);
SerialResponse *handleMessage(Group *conf, SerialData *data, int pinCount);
SerialResponse *handleGroupSet(Group *conf, SerialData *data, int pinCount);
