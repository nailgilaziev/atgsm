//
//  EventsListener.hpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#ifndef EventsListener_hpp
#define EventsListener_hpp

#include "InputListener.hpp"
#include "CmdsQueue.hpp"

#include "EventsListener.hpp"

class SerialRouter;

struct EventAction{
    const char *event;
    CmdsQueue* (*actionCmd)();
};

class EventsListener: public InputListener  {
public:
    virtual void newLineEvent(SerialRouter *) override;
};

#endif /* EventsListener_hpp */

