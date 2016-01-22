/*
  @file: InputFactory.cpp
  @brief: arquivo de implementação do método do método GetCommand.
  ipmt

*/

#include "command_factory.hpp"
/*
 @brief: função responsável por retorna o objeto referente ao comando informado via argumentos.
 */
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
