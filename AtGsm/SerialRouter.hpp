//
//  SerialRouter.hpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#ifndef SerialRouter_hpp
#define SerialRouter_hpp

#include "SoftwareSerialEcho.hpp"
#include "EventsListener.hpp"

#ifndef LINE_BUFFER_SIZE
//maximum is 255 because lineCursor is byte type
#define LINE_BUFFER_SIZE 32
#endif



//class SoftwareSerial;

//char okLine[] = "OK";
//char errorLine[] = "Error";

class SerialRouter {
private:
    EventsListener eventsListener;
public:
    CmdsQueue *executingCmd = NULL;
    
    //TODO for save global memory can be placed to heap
    char lineBuffer[LINE_BUFFER_SIZE];
    byte lineCursor = 0;
    
    SoftwareSerial *s;
    SerialRouter(SoftwareSerial *s);
    
    byte readInput();
    byte analyzeLine();
};


#endif /* SerialRouter_hpp */

