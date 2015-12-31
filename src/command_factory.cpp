//
//  InputFactory.cpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "search_file.hpp"
#include "indexing_file.hpp"
#include "command_factory.hpp"

Command *CommandFactory::GetCommand(InputModel input_model)
{
    Command *command = NULL;
    
    switch (input_model.GetCommandType())
    {
        case InputModel::search:
        {
            command = new Search(input_model);
            break;
        }
        case InputModel::index:
        {
            command = new Indexing(input_model);
            break;
        }
        default:
            break;
    }

    return command;
}
