#include "SweepingTask.h"
#include <Arduino.h>
#include "config.h"
#include "kernel/Logger.h"

#define FWD_TIME 2000
#define BWD_TIME 1000
#define START_TIME 100
#define RESET_TIME 500


SweepingTask::SweepingTask(Button* pButton, ServoMotor* pMotor, Context* pContext): 
    pMotor(pMotor), pButton(pButton), pContext(pContext){
    setState(IDLE);
}
  
void SweepingTask::tick(){
    switch (state){    
    case IDLE: {
        if (this->checkAndSetJustEntered()){
            Logger.log(F("[SWT] IDLE"));
        }
        if (pButton->isPressed()){
            pContext->setStarted();
            pMotor->on();
            currentPos = 0;
            toBeStopped = false;
            setState(SWEEPING_FWD);
        }
        break;
    }
    case SWEEPING_FWD: {        
        if (this->checkAndSetJustEntered()){
            Logger.log(F("[SWT] SWEEPING_FWD"));
        }
        
        /* update motor pos*/

        long dt = elapsedTimeInState();
        currentPos = (((float) dt)/FWD_TIME)*180;
        pMotor->setPosition(currentPos);

        if (pButton->isPressed()){
            pContext->setStopped();
            Logger.log(F("[SWT] STOPPED!"));
            setState(RESETTING);
        } else if (dt > FWD_TIME){
            setState(SWEEPING_BWD);
        }
        break;       
    }
    case SWEEPING_BWD: {        
        if (this->checkAndSetJustEntered()){
            Logger.log(F("[SWT] SWEEPING_BWD"));
        }

        /* update motor pos*/
        
        long dt = elapsedTimeInState();
        currentPos = (((float) dt)/BWD_TIME)*180;
        pMotor->setPosition(currentPos);

        if (pButton->isPressed()){
            Logger.log(F("[SWT] STOPPED!"));
            pContext->setStopped();
            toBeStopped = true;
        } 
        
        if (dt > BWD_TIME){
            if (!toBeStopped){
                setState(SWEEPING_FWD);
            } else {
                setState(RESETTING);    
            }
        }
        break;       
    }
    /*
    case STARTING: {
        if (this->checkAndSetJustEntered()){
            Logger.log(F("[SWT] STARTING"));
        }
        if (elapsedTimeInState() > START_TIME){
            setState(SWEEPING_FWD);
        }
        break;
    }*/
    case RESETTING: {
        if (this->checkAndSetJustEntered()){
            Logger.log(F("[SWT] RESETTING"));
        }
        pMotor->setPosition(0);
        if (elapsedTimeInState() > RESET_TIME){
            pMotor->off();
            setState(IDLE);
        }
    }
    }
}

void SweepingTask::setState(int s){
    state = s;
    stateTimestamp = millis();
    justEntered = true;
}

long SweepingTask::elapsedTimeInState(){
    return millis() - stateTimestamp;
}

bool SweepingTask::checkAndSetJustEntered(){
    bool bak = justEntered;
    if (justEntered){
      justEntered = false;
    }
    return bak;
}
