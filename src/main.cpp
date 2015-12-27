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

#include "command_model.hpp"
#include "input_control.hpp"
#include "search_file.hpp"
#include "indexing_file.hpp"

int main(int argc, const char * argv[]) {
    
    InputControl input_control;
    CommandModel command_model = input_control.SetCommand(argc, argv);
    
    InputControl::CommandType command_type;
    switch (command_type)
    {
        case InputControl::SEARCH:
        {
            Search search = Search(command_model);
            search.Execute();
            break;
        }
        case InputControl::INDEX:
        {
            Indexing index = Indexing(command_model);
            index.Execute();
            break;
        }
        default:
            break;
    }

    return 0;
}
