#define MBC_DataHelper

#ifndef MBC_DataModell
#include "DataModell.h"
#endif

void SetPin(Configuration *conf, int grpNum, int pinNum);
void Reset(Configuration *conf, int grpNum);
void togglePIN(PIN *pin);

void execute(Group *);

Configuration *InitializeConfiguration(int pincount);
PIN *generatePinList(int pincount);
Group *generateGroupList(int pincount);