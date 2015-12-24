//
//  input_control.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef input_control_hpp
#define input_control_hpp

#include <stdio.h>
#include "command_model.hpp"

#define VERSION_CODE "1.0"

class InputControl{
    
private:
    int index;
    CommandModel command_model;
    void GetExtraArguments(const char* argv[]);
    void ShowHelp();
    void ShowException(const char * message);
    
public:
    CommandModel SetCommand(int argc, const char* args[]);
    
    enum CommandType
    {
        INDEX, SEARCH
    };

};
#endif /* input_control_hpp */
