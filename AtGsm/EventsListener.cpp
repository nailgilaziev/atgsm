//
//  EventsListener.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "EventsListener.hpp"
#include "SerialRouter.hpp"
#include "CmdsQueue.hpp"
#include "Cmds.hpp"

CmdsQueue* echoOff(){
    return new EchoOffCQ();
}

CmdsQueue* configereSms(){
    return new ConfigureCQ();
}

static const byte eventsCount = 3;
EventAction events[eventsCount]={
    {"MODEM:STARTUP",&echoOff},
    {"+PBREADY",&configereSms}
};

void EventsListener::newLineEvent(SerialRouter *sr){
    Serial.print(F("->"));
    Serial.println(sr->lineBuffer);
    for (byte i=0; i<eventsCount; i++) {
        if(strcmp(events[i].event,sr->lineBuffer)==0){
            delete sr->executingCmd;
            sr->executingCmd = events[i].actionCmd();
            sr->executingCmd->execute(sr);
            break;
        }
    }
}
