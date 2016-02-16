/*
  @file: main.cpp
  @brief: classe principal responsável por obter os parâmetros do comando informado
  e executar a ação.
*/

#include <stdio.h>
#include "command.hpp"
#include "command_factory.hpp"
#include "input_parser.hpp"

#include "benchmark.hpp"

int main(int argc, const char * argv[]) {
    
/*Inputparser cria um objeto do tipo InputModel com os argumentos de comando
informados e seleciona qual o tipo de comando deverá ser executado.*/
    
    InputParser input_parser = InputParser(argc, argv);
    Command *command = CommandFactory::GetCommand(input_parser.SetCommand());
    command->Execute();
    
    //RunHuffmanEncode();
    return 0;
}
