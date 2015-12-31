//
//  input_control.cpp
//  impt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
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
    {"pattern",       required_argument, 0, 'p'},
    {"compression",   required_argument, 0, 'c'},
    {"index_type",    required_argument, 0, 'i'},
    { 0,              0,                 0,  0 },
};

InputParser::InputParser(int argc, const char* argv[])
{
    m_argc = argc;
    m_args = (char**)argv;
}

InputModel InputParser::SetCommand()
{
    InputParser::GetOptionsArguments();
    InputParser::GetExtraArguments();
    
    return input_model;
}


void InputParser::GetOptionsArguments()
{
    const char* option_string = "vhnp:c:i:";
    int n_option = getopt_long(m_argc, m_args, option_string, CommandOptions, NULL);

    while(n_option > 0)
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
    
}



void InputParser::GetExtraArguments()
{
    if (optind < m_argc){
        std::vector<std::string> v_result_args;

        for (int i = optind; i < m_argc; i++)
        {
            v_result_args.push_back(m_args[i]);
        }
    
        long extra_arguments_size = v_result_args.size();
    
        if (v_result_args[0] == "search") {
            input_model.SetCommandType(InputModel::InputType::search);

            if (extra_arguments_size > 2) {
                input_model.SetPatternFile(v_result_args[1]);
                input_model.SetFileName(v_result_args[2]);
                
            }else{
                Error::ShowException("Comamdo mal formatado. Siga os exemplos via -h ou -help.");
                
            }
            
        } else if (v_result_args[0] == "index"){
            input_model.SetCommandType(InputModel::InputType::index);

            if (extra_arguments_size > 1){
                input_model.SetFileName(v_result_args[1]);
                
            }else{
                Error::ShowException("Comamdo mal formatado. Siga os exemplos via -h ou -help.");
                
            }
        }
    }else{
        Error::ShowException("Argumentos não especificados. Siga os exemplos via -h ou -help.");

    }
}


void InputParser::ShowHelp()
{
    fprintf(stdout, "ipmt version %s \n\
            \n\
            -v, --version            :   Exibe a versão atual do programa; \n\\n\
            -h, --help               :   Exibe texto com opções e exemplos de comando; \n\\n\\n\
            --------- index command structure ---------\n\
            $ ipmt index [options] textfile\n\
            --------- command <options> ---------\n\
            --compression            :   Recebe como argumento os valores 0 referente ao algoritmo LZ77 e 1 referente ao algoritmo LZ78;\n\n\
            --indextype              :   Recebe como argumento 0 referente a array de sufixo e 1 referente a árvore de sufixo; \n\\n\
            textfile                 : Arquivo em formato txt contendo texto para indexação\n\\n\\n\
            --------- search command structure ---------\n\
            $ ipmt search pattern indexfile\n\
            --------- command <options> ---------\n\
            -p, --pattern patternfile:   Busca no arquivo de texto o ou os padrões em cada linha de código do arquivo de padrão(patternfile);\n\\n\
            -c, --cout               :   Imprime uma linha com o total de ocorrências do padrão no arquivo; \n\\n\
            patternfile              :   Arquivo de texto contendo um ou mais padrões. Cada padrão é estruturado em uma linha do arquivo;\n\\n\
            indexfile                :   Arquivo com conteúdo de busca após sofrer indexação;\n\\n\
            pattern                  :   String contendo padrão para busca;", VERSION_CODE);
    exit(-1) ;

}

