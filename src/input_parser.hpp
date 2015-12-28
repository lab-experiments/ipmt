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
      InputModel input_model;
      void GetExtraArguments(const char* argv[]);
      void ShowHelp();
    
public:
    
      InputModel SetCommand(int argc, const char* args[]);

};
#endif /* input_control_hpp */
