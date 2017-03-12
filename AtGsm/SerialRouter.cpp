//
//  SerialRouter.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "SerialRouter.hpp"

#define ERROR_EXCEED_BUFFER_SIZE 3
#define ERROR_UNPREDICTABLE_INPUT_END 4


#define CR 13
#define LF 10


SerialRouter::SerialRouter(SoftwareSerial *softwareSerial){
    s = softwareSerial;
}

byte SerialRouter::readInput(){
//    Serial.print("->");
    while (s->available()) {
        if (lineCursor>=LINE_BUFFER_SIZE) {
            lineCursor = 0;
            return ERROR_EXCEED_BUFFER_SIZE; //exceed buffer size return error code
        }
//        Serial.print(s->available());
//        Serial.print('[');
        char c = s->read();
//        Serial.print((int)c);
//        Serial.print('-');
//        Serial.print(lineCursor);
//        Serial.print(']');
        if (lineCursor==0 && (c==CR||c==LF)) {Serial.print(',');continue;} //skip empty new lines
        if (c==LF){
            if (lineBuffer[lineCursor-1] == CR) {
                lineBuffer[lineCursor-1] = '\0';
                byte r = analyzeLine();
                lineCursor = 0;
                return r;
            }
            else return ERROR_UNPREDICTABLE_INPUT_END; //unpredictable state. This is not impossible
        }else {
            lineBuffer[lineCursor++] = c;
        }
    }
//    Serial.println();
    return 0; //this means that we read whole input buffer buffer, and not find answer end yet.
    // Temporarly buffer is empty and we waiting for continue to reading input
}

byte SerialRouter::analyzeLine(){
    if (executingCmd) Serial.print(F("Analyze[CmdQ LISTENER]"));
    else Serial.print(F("Analyze[Events LISTENER]"));
    Serial.print(lineBuffer);
    Serial.println(";");
    static InputListener *currentListener;
    if (executingCmd) currentListener = (InputListener *)executingCmd;
    else currentListener = &eventsListener;
    
    if (strcmp(lineBuffer, "OK")==0) {
        if(currentListener->successEvent(this)) resetExecutingCmd();
        return 1;
    }
    if (strcmp(lineBuffer, "ERROR")==0) {
        if(currentListener->failureEvent(this)) resetExecutingCmd();
        return 1;
    }
    currentListener->newLineEvent(this); //Line with some data
    return 0; //just skip it and continue listening new lines
}

void SerialRouter::resetExecutingCmd(){
    Serial.println(F("Reset ECQ"));
    delete executingCmd;
    executingCmd = NULL;
}

