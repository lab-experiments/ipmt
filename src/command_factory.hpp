/*
  @file: InputFactory.hpp
  @brief: Classe utilizando padrão Factory para abstração do tipo de comando a ser executada(searching ou indexing);
*/

#ifndef InputFactory_hpp
#define InputFactory_hpp

#include <stdio.h>
#include "command.hpp"
#include "search_file.hpp"
#include "indexing_file.hpp"

class CommandFactory
{
    
public:
    
     static Command* GetCommand(InputModel input_model);

};
#endif /* InputFactory_hpp */
