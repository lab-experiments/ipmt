/*
  @file: input_control.hpp
  @brief: classe responsável por criar um parser do comando. Obtem cada argumento da linha de comando e retorna um objeto do tipo InputModel.
*/

#ifndef input_control_hpp
#define input_control_hpp

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "error.hpp"
#include "manipulation_file.hpp"
#include "input_model.hpp"

#define VERSION_CODE "1.0"

class InputParser
{
    
private:
    
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
