//
//  Cmds.hpp
//  AtGsm
//
//  Created by Nail on 12/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#ifndef Cmds_h
#define Cmds_h

#include "CmdsQueue.hpp"

class EchoOffCQ : public CmdsQueue{
    const char *cmds[1] = {"ATE0"};
    const char * getNext(int index) override{
        if (index >= 1) return NULL;
        return cmds[index];
    }
};

class ConfigureCQ : public CmdsQueue{
    const char *cmds[2] = {"ATI","AT+CPAS?"};
    const char * getNext(int index) override{
        if (index >= 2) return NULL;
        return cmds[index];
    }
};


#endif /* Cmds_h */
