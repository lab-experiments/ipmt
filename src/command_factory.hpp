//
//  InputFactory.hpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef InputFactory_hpp
#define InputFactory_hpp

#include <stdio.h>
#include "command.hpp"

class CommandFactory
{
    
public:
    
     static Command *GetCommand(InputModel input_model);

};
#endif /* InputFactory_hpp */
