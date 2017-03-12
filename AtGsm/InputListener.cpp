//
//  InputListener.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "InputListener.hpp"
#include "SerialRouter.hpp"


void InputListener::newLineEvent(SerialRouter *sr){
    Serial.print(F("->"));
    Serial.println(sr->lineBuffer);
}
boolean InputListener::successEvent(SerialRouter *sr){
    Serial.println(F("OK finded"));
}
boolean InputListener::failureEvent(SerialRouter *sr){
    Serial.println(F("Error Finded"));
}

