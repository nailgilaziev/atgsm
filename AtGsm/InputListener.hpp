//
//  InputListener.hpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "Arduino.h"


#ifndef InputListener_hpp
#define InputListener_hpp


class SerialRouter;

class InputListener{
public:
    virtual void newLineEvent(SerialRouter *);
    virtual boolean successEvent(SerialRouter *);
    virtual boolean failureEvent(SerialRouter *);
};

#endif /* InputListener_hpp */



