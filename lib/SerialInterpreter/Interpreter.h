#ifndef Arduino_h
#include <Arduino.h>
#endif

const int PINCOUNT = 20;

struct PIN
{
  int enabled;
  int delay;
  int group;
};

enum States
{
  setPIN,
  End = 1024,
  Error = 2048,
  next = 4096,
};

class Interpreter
{
public:
  Interpreter();
  void handleMessage();
  void execute();

private:
  States setPin(int inp);
  States end();

  bool change = false;
  PIN *m_pins[PINCOUNT];
  bool Next = false;
  PIN *data = nullptr;

  int count = 0;

  States state = States::End;
};
