//
//  main.cpp
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdio.h>
#include "command.hpp"
#include "command_factory.hpp"
#include "input_parser.hpp"

int main(int argc, const char * argv[]) {
    
    InputParser input_parser;
    Command *command = CommandFactory::GetCommand(input_parser.SetCommand(argc,argv));
    command->Execute();
    
    return 0;
}
