//
//  Cmds.hpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#ifndef CmdsQueue_hpp
#define CmdsQueue_hpp

#include "InputListener.hpp"

class CmdsQueue : InputListener {
private:
    byte executingCmd=-1;
public:
    void execute(SerialRouter *);
    
    virtual const char * getNext(int index);
    
    virtual void newLineEvent(SerialRouter *) override;
    virtual void successEvent(SerialRouter *) override;
    virtual void failureEvent(SerialRouter *) override;
    
    virtual void success();
    virtual void failure();
};





#endif /* CmdsQueue_hpp */


