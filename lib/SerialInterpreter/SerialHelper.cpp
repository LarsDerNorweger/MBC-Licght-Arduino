#ifndef States_h
#include "States.h"
#endif

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef SerialHelper_h
#include "SerialHelper.h"
#endif

SerialData *readSerial()
{
  SerialData *res = new SerialData;
  int l = Serial.available();
  res->dataLength = l;
  res->data = new char[l];
  Serial.readBytes(res->data, l);
  return res;
}

// Convert

SerialData *convertResponse(SerialResponse *response)
{
  SerialData *res = new SerialData;
  int l = response->dataLenght + 1;
  res->data = new char[l];
  res->data[0] = (char)response->state;
  for (int i = 1; i < l; i++)
    res->data[i] = response->data[i - 1];
  res->dataLength = l;
  return res;
}

// send
void sendSerial(SerialData *data)
{
  Serial.write(data->data, data->dataLength);
}

void sendSerialAndDelete(SerialData *data)
{
  sendSerial(data);
  deleteSerialData(data);
}

// For Cleanup

void deleteSerialData(SerialData *data)
{
  delete data->data;
  delete data;
}

void deleteSerialResponse(SerialResponse *data)
{
  delete data->data;
  delete data;
}
