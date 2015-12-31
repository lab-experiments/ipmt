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
#include "input_model.hpp"

#define VERSION_CODE "1.0"

class InputParser
{
    
private:
    
    int m_index;
    int m_argc;
    char** m_args;
    
    InputModel input_model;
    void GetExtraArguments();
    void GetOptionsArguments();
    void ShowHelp();
    
public:
    InputParser(int argc, const char* argv[]);
    InputModel SetCommand();

};
#endif /* input_control_hpp */
