//
//  Cmds.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "CmdsQueue.hpp"
#include "SerialRouter.hpp"

void CmdsQueue::execute(SerialRouter *sr){
    const char *cmd = getNext(++executingCmd);
    if (cmd == NULL) success();
    else{
        Serial.print(F("<-"));
        Serial.println(cmd);
        for (int i = 0; true; i++) {
            char c = cmd[i];
            if (c == '\0') break;
            sr->s->write(c);
        }
    }
}

const char * CmdsQueue::getNext(int index){
    return NULL;
}

void CmdsQueue::newLineEvent(SerialRouter *sr){
    //just ignore data lines. If you need save them - override
}

void CmdsQueue::successEvent(SerialRouter *sr){
    execute(sr);
}

void CmdsQueue::failureEvent(SerialRouter *sr){
    failure();
}

void CmdsQueue::success(){}
void CmdsQueue::failure(){}



