//
//  main.cpp
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>

#include "input_factory.hpp"
#include "input_parser.hpp"

int main(int argc, const char * argv[]) {
    
    InputParser input_parser;
    Command command;
    command = InputFactory::GetCommand(input_parser.SetCommand(argc,argv));
    command.Execute();
    
    return 0;
}
