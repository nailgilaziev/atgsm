//
//  Cmds.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "CmdsQueue.hpp"
#include "SerialRouter.hpp"

boolean CmdsQueue::execute(SerialRouter *sr){
    const char *cmd = getNext(++executingCmd);
    if (cmd == NULL)  return success(sr);
    else{
        Serial.print(F("<-"));
        Serial.println(cmd);
        for (int i = 0; true; i++) {
            char c = cmd[i];
            if (c == '\0') break;
            sr->s->write(c);
        }
        return false;
    }
}

const char * CmdsQueue::getNext(int index){
    return NULL;
}

void CmdsQueue::newLineEvent(SerialRouter *sr){
    //just ignore data lines. If you need save them - override
    Serial.print(F("-->"));
    Serial.println(sr->lineBuffer);
}

boolean CmdsQueue::successEvent(SerialRouter *sr){
    return execute(sr);
}

boolean CmdsQueue::failureEvent(SerialRouter *sr){
    return failure(sr);
}

boolean CmdsQueue::success(SerialRouter *sr){
    return true;
}
boolean CmdsQueue::failure(SerialRouter *sr){
    return true;
}



