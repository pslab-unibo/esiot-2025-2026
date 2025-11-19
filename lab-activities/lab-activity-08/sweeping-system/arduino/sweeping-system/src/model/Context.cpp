#include "Context.h"

Context::Context(){
  started = false;
  stopped = false;
}

bool Context::isStarted(){
  return started;
}

bool Context::isStopped(){
  return stopped;
}

void Context::setStarted(){
  started = true;
  stopped = false;
}

void Context::setStopped(){
  stopped = true;
  started = false;
}

void Context::reset(){
  started = false;
  stopped = false;
}

