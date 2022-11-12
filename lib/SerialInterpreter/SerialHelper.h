#ifndef States_h
#include "States.h"
#endif

#define SerialHelper_h

struct SerialData
{
  char *data;
  int dataLength;
};

struct SerialResponse
{
  STATE state;
  char *data;
  int dataLenght;
};

SerialData *convertResponse(SerialResponse *response);
SerialData *readSerial();

void sendSerial(SerialData *data);
void sendSerialAndDelete(SerialData *data);

// for Cleanup
void deleteSerialData(SerialData *data);
void deleteSerialResponse(SerialResponse *data);