
#ifndef MBC_DataHelper
#include "DataHelper.h"
#endif

#ifndef MBC_DataModell
#include "DataModell.h"
#endif

Configuration *InitializeConfiguration(int pincount)
{
}

PIN *generatePinList(int count)
{
  PIN *res = new PIN[count];
  PIN *p;
  for (int i = 0; i < count; i++)
  {
    p = new PIN();
    p->enabled = 0;
    p->PINnumber = -1;
    res[i] = *p;
  }
  return res;
}

Group *generateGroupList(int pincount)
{
  Group *res = new Group[pincount];
  Group *g;
  for (int i = 0; i < pincount; i++)
  {
    g = new Group();
    g->delay = 0;
    g->lastSwitch = 0;
    g->lastpin = -1;
    g->pins = generatePinList(i + 1);
    res[i] = *g;
  }
  return res;
}

void Reset(Group *group, int count)
{
  // for (int i = 0; i < count; i++)
  // {
  //   group->pins[i].enabled = 0;
  //   group->pins[i].PINnumber = -1;
  // }
}

void SetPin(Group *conf, int grpNum, int pinNum)
{
  Group g = conf[grpNum - 1];
  PIN p;
  for (int i = 0; i < grpNum; i++)
  {
    p = g.pins[i];
    if (p.PINnumber <= 0)
      break;
  }
  p.enabled = 1;
  p.PINnumber = pinNum;
}

void togglePIN(PIN *pin)
{
}
