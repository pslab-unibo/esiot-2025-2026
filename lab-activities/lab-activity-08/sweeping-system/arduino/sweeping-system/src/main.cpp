#include <Arduino.h>
#include "config.h"
#include "kernel/Scheduler.h"
#include "kernel/Logger.h"
#include "kernel/MsgService.h"
#include "model/HWPlatform.h"
#include "tasks/TestHWTask.h"
#include "tasks/SweepingTask.h"
#include "tasks/BlinkingTask.h"

// #define __TESTING_HW__

Scheduler sched;

HWPlatform* pHWPlatform;
Context* pContext;

void setup() {
  MsgService.init();
  sched.init(50);

  Logger.log(":::::: Sweeping System ::::::");
  
  pHWPlatform = new HWPlatform();
  pHWPlatform->init();

#ifndef __TESTING_HW__
  pContext = new Context();

  Task* pSweepingTask = new SweepingTask(pHWPlatform->getButton(), pHWPlatform->getMotor(), pContext);
  pSweepingTask->init(50);

  Task* pBlinkingTask = new BlinkingTask(pHWPlatform->getLed(), pContext);
  pBlinkingTask->init(100);

  sched.addTask(pSweepingTask);
  sched.addTask(pBlinkingTask);
#endif

#ifdef __TESTING_HW__
  /* Testing */
  Task* pTestHWTask = new TestHWTask(pHWPlatform);
  pTestHWTask->init(2000);
  sched.addTask(pTestHWTask);
#endif
}

void loop() {
    sched.schedule();
}