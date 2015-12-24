//
//  input_control.cpp
//  impt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>
#include "error.h"
#include "input_control.hpp"

using namespace std;

const struct option CommandOptions[] =
{
    {"version",       no_argument,       0, 'v'},
    {"help",          no_argument,       0, 'h'},
    {"count",         no_argument,       0, 'n'},
    {"index",         no_argument,       0, 'i'},
    {"search",        no_argument,       0, 's'},
    {"pattern",       required_argument, 0, 'p'}, // pattern text file
    {"compression",   required_argument, 0, 'c'}, // integer type
    {"index_type",    required_argument, 0, 't'}, // integer type
    { 0,              0,                 0,  0 },
};

CommandModel InputControl::SetCommand(int argc, const char* argv[]){
    InputControl::index =  argc;
    int n_option;
    const char* option_string = "vhnisp:c:t:";

    while((n_option = getopt_long(argc,(char**)argv, option_string, CommandOptions, NULL)) > 0)
    {
        switch (n_option)
        {
            case 'v':
                printf("ipmt version %s", VERSION_CODE) ;
                break ;
                
            case 'h':
                InputControl::ShowHelp() ;
                break ;
                
            case 'n':
                command_model.SetHasNumberTotalPattern(true);
                break ;
                
            case 's':
                command_model.SetCommandType(InputControl::CommandType::SEARCH);
                break;
                
            case 'i':
                command_model.SetCommandType(InputControl::CommandType::INDEX);
                break;

            case 'p':
                command_model.SetPatternFile(optarg);
                break ;
                
            case 'c':
                if(atoi(optarg) == command_model.CompressionType::LZ77){
                    command_model.SetCompressioType(command_model.CompressionType::LZ77);
                    
                }else if(atoi(optarg) == command_model.CompressionType::LZ78){
                    command_model.SetCompressioType(command_model.CompressionType::LZ78);
                    
                }else{
                    ShowException("A opção --compression, requer um argumento do tipo 0 para LZ77 ou 1 para LZ78.\n Mais informações cheque $impt --help.");
                    
                }
                break ;
                
            case 't':
                if(atoi(optarg) == command_model.IndexType::suffix_array){
                    command_model.SetIndexType(command_model.IndexType::suffix_array);
                    
                }else if(atoi(optarg) == command_model.IndexType::suffix_tree){
                    command_model.SetIndexType(command_model.IndexType::suffix_tree);
                    
                }else{
                    ShowException("A opção --index, requer um argumento do tipo 0 para suffixtree ou 1 para arraysuffix.\n Mais informações cheque $impt --help.");
                }
                break ;

            case '?':
                if (optopt == 'c'){
                    ShowException("A opção --compression, requer um argumento do tipo 0 para LZ77 ou 1 para LZ78.\n Mais informações cheque $impt --help.");
                
                }else if (optopt == 't'){
                    ShowException("A opção --index, requer um argumento do tipo 0 para suffixtree ou 1 para arraysuffix.\n Mais informações cheque $impt --help.");
                
                }else if(optopt == 'p'){
                    ShowException("A opção -p ou --pattern, requer um argumento do tipo arquivo de texto.\n Mais informações cheque $impt --help.");
                    
                }else{
                    ShowException("Comando inválido. Cheque $impt --help.");
                
                }
                break ;

            default:
                abort();
        }
    }
    
    InputControl::GetExtraArguments(argv);
    return command_model;
}


void InputControl::GetExtraArguments(const char* argv[])
{
    std::vector<std::string> v_result_args;
    for (int i = optind; i < InputControl::index; i++)
    {
        v_result_args.push_back(argv[i]);
    }
    
    long extra_arguments_size = v_result_args.size();
    InputControl::CommandType command_type;
    
    switch (command_type) {
        case InputControl::SEARCH:
            if (extra_arguments_size > 1) {
                command_model.SetPatternFile(v_result_args[0]);
                command_model.SetFileName(v_result_args[1]);
                
            }else{
                ShowException("Arquivo para manipulação não informado.");
                
            }
            break;
            
        case InputControl::INDEX:
            if (extra_arguments_size == 1){
                command_model.SetFileName(v_result_args[0]);
                
            }else{
                ShowException("Arquivo para manipulação não informado.");
                
            }
            break;
            
        default:
            break;
    }
}


void InputControl::ShowHelp()
{
    fprintf(stdout, "ipmt version %s \n\
            \n\
            --------- command structure ---------\n\
            $ ipmt index [options] textfile\n\
            $ ipmt search pattern indexfile\n\\n\
            --------- command <options> ---------\n\
            -v, --version            :   Exibi a versão atual do programa.\n\\n\
            -h, --help               :   Print a help message briefly summarizing command-line options, and exit\n\\n\
            -p, --pattern patternfile:   Busca no arquivo de texto o ou os padrões em cada linha de código do arquivo de padrão(patternfile)\n\\n\
            --compression            :   Recebe como argumento os valores 0 referente ao algoritmo LZ77 e 1 referente ao algoritmo LZ78;\n\n\
            patternfile              :   Arquivo de texto contendo um ou mais padrões. Cada padrão é estruturado em uma linha do arquivo;\n\\n\
            indexfile                :   Arquivo com conteúdo de busca após sofrer indexação;\n\\n\
            pattern                  :   String contendo padrão para busca;", VERSION_CODE);
    exit(-1) ;

}

