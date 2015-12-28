//
//  input_control.cpp
//  impt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "error.hpp"
#include "input_model.hpp"
#include "input_parser.hpp"

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

InputModel InputParser::SetCommand(int argc, const char* argv[])
{
    m_index =  argc;
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
                InputParser::ShowHelp() ;
                break ;
                
            case 'n':
                input_model.SetHasNumberTotalPattern(true);
                break ;
                
            case 's':
                input_model.SetCommandType(InputModel::InputType::search);
                break;
                
            case 'i':
                input_model.SetCommandType(InputModel::InputType::index);
                break;

            case 'p':
                input_model.SetPatternFile(optarg);
                break ;
                
            case 'c':
                if(atoi(optarg) == input_model.CompressionType::LZ77){
                    input_model.SetCompressioType(input_model.CompressionType::LZ77);
                    
                }else if(atoi(optarg) == input_model.CompressionType::LZ78){
                    input_model.SetCompressioType(input_model.CompressionType::LZ78);
                    
                }else{
                    Error::ShowException("A opção --compression, requer um argumento do tipo 0 para LZ77 ou 1 para LZ78.\n Mais informações cheque $impt --help.");
                    
                }
                break ;
                
            case 't':
                if(atoi(optarg) == input_model.IndexType::suffix_array){
                    input_model.SetIndexType(input_model.IndexType::suffix_array);
                    
                }else if(atoi(optarg) == input_model.IndexType::suffix_tree){
                    input_model.SetIndexType(input_model.IndexType::suffix_tree);
                    
                }else{
                    Error::ShowException("A opção --index, requer um argumento do tipo 0 para suffixtree ou 1 para arraysuffix.\n Mais informações cheque $impt --help.");
                }
                break ;

            case '?':
                if (optopt == 'c'){
                    Error::ShowException("A opção --compression, requer um argumento do tipo 0 para LZ77 ou 1 para LZ78.\n Mais informações cheque $impt --help.");
                
                }else if (optopt == 't'){
                    Error::ShowException("A opção --index, requer um argumento do tipo 0 para suffixtree ou 1 para arraysuffix.\n Mais informações cheque $impt --help.");
                
                }else if(optopt == 'p'){
                    Error::ShowException("A opção -p ou --pattern, requer um argumento do tipo arquivo de texto.\n Mais informações cheque $impt --help.");
                    
                }else{
                    Error::ShowException("Comando inválido. Cheque $impt --help.");
                
                }
                break ;

            default:
                abort();
        }
    }
    
    GetExtraArguments(argv);
    return input_model;
}


void InputParser::GetExtraArguments(const char* argv[])
{
    std::vector<std::string> v_result_args;
    for (int i = optind; i < m_index; i++)
    {
        v_result_args.push_back(argv[i]);
    }
    
    long extra_arguments_size = v_result_args.size();
    InputModel::InputType input_type;
    
    switch (input_type) {
        case InputModel::search:
            if (extra_arguments_size > 1) {
                input_model.SetPatternFile(v_result_args[0]);
                input_model.SetFileName(v_result_args[1]);
                
            }else{
                Error::ShowException("Arquivo para manipulação não informado.");
                
            }
            break;
            
        case InputModel::index:
            if (extra_arguments_size == 1){
                input_model.SetFileName(v_result_args[0]);
                
            }else{
                Error::ShowException("Arquivo para manipulação não informado.");
                
            }
            break;
            
        default:
            break;
    }
}


void InputParser::ShowHelp()
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

