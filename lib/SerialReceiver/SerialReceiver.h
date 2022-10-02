#ifndef Arduino_h
#include <Arduino.h>
#endif

class SerialReceiver
{
public:
  SerialReceiver();
  ~SerialReceiver();
  void checkForReceive();

private:
};