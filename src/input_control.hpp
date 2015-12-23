//
//  input_control.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef __pmt_project__inputControl__
#define __pmt_project__inputControl__

#include <stdio.h>
#include "command_model.hpp"
#include "search_file.hpp"

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
        Index,Search
    };

};
#endif /* defined(__pmt_project__inputControl__) */
