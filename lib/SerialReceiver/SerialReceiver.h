#ifndef Arduino_h
#include <Arduino.h>
#endif

struct Data
{
  int PIN;
  int ENABLED;
};

class SerialReceiver
{
public:
  SerialReceiver();
  ~SerialReceiver();
  void checkForReceive();

private:
  void execute(Data *);
};