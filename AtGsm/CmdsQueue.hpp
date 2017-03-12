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
    boolean execute(SerialRouter *);
    
    virtual const char * getNext(int index);
    
    virtual void newLineEvent(SerialRouter *) override;
    virtual boolean successEvent(SerialRouter *) override;
    virtual boolean failureEvent(SerialRouter *) override;
    
    virtual boolean success(SerialRouter *);
    virtual boolean failure(SerialRouter *);
};





#endif /* CmdsQueue_hpp */


