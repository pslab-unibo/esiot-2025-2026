#ifndef __SWEEPING_TASK__
#define __SWEEPING_TASK__

#include "kernel/Task.h"
#include "devices/ServoMotor.h"
#include "devices/Button.h"
#include "model/Context.h"
#include <Arduino.h>

class SweepingTask: public Task {

public:
  SweepingTask(Button* pButton, ServoMotor* pMotor, Context* pContext); 
  void tick();

private:  
  void setState(int state);
  long elapsedTimeInState();
  void log(const String& msg);
  
  bool checkAndSetJustEntered();
  
  enum { IDLE, STARTING, SWEEPING_FWD, SWEEPING_BWD, RESETTING } state;
  long stateTimestamp;
  bool justEntered;

  Button* pButton;
  ServoMotor* pMotor;
  Context* pContext;

  int currentPos;
  bool toBeStopped;
};

#endif