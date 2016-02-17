/*
 @file: input_control.cpp
 @brief: arquivo com método de manipulação de arguementos para consolidação em um objeto InputModel.
 */

#include "input_parser.hpp"

using namespace std;

const struct option CommandOptions[] =
{
    {"help",               no_argument,       0, 'h'},
    {"count",              no_argument,       0, 'c'},
    {"pattern",            required_argument, 0, 'p'},
    { 0,                   0,                 0,  0 },
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
    const char* option_string = "hcp:";
    int n_option;
    
    while ( (n_option = getopt_long(m_argc, m_args, option_string, CommandOptions, NULL)) > 0 )
    {
        switch (n_option)
        {
            case 'h':
                InputParser::ShowHelp() ;
                break ;
                
            case 'c':
                input_model.SetShowNumberPatternOccurrences(true);
                break ;
                
            case 'p':
                {
                    if (!ManipulationFile::IsFile(optarg)) {
                        Error::ShowException( "O arquivo não pode ser aberto. Adicione outro arquivo de padrão ");
                    }else{
                        input_model.SetPatternFileName(optarg);
                    }
                }
                break ;
                
            case '?':
                if(optopt == 'p'){
                    Error::ShowException("A opção -p ou --pattern requer um argumento do tipo arquivo de texto.\n Mais informações cheque $impt --help.");
                    
                }else{
                    Error::ShowException("Comando inválido. Cheque $impt --help.");
                    
                }
                break ;
                
            default:
                exit(-1);
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
        
        if (v_result_args[0] == "search") {
            input_model.SetCommandType(InputModel::search);
            string input_file_name;
            
            if(input_model.GetPatternFileName().empty() && v_result_args.size() >= 2)
            {
                input_model.SetPatternFileName(v_result_args[1]);
                input_file_name = v_result_args[2];
            }else{
                input_file_name = v_result_args[1];

            }
            
            if(!ManipulationFile::IsIndexFile(input_file_name))
            {
                Error::ShowException("Extensão do arquivo não é do tipo idx. Informar arquivo de index com essa extensão.");
            }else{
                
                if (!ManipulationFile::IsFile(input_file_name.c_str())) {
                    Error::ShowException( "Arquivo inválido. Insira um arquivo de texto.");
                }else{
                    input_model.SetTextFileName(input_file_name);
                }
            }
            
        } else if (v_result_args[0] == "index" && v_result_args.size() > 1){
            input_model.SetCommandType(InputModel::index);
            input_model.SetTextFileName(v_result_args[1]);
            
        }else{
            Error::ShowException("Comamdo mal formatado. Siga os exemplos via -h ou --help.");
        }
    }else{
        Error::ShowException("Argumentos não especificados. Siga os exemplos via -h ou --help.");
        
    }
}


void InputParser::ShowHelp()
{
    fprintf(stdout, "ipmt version %s \n\
            \n\
            -h, --help               :   Exibe texto com opções e exemplos de comando; \n\\n\\n\
            --------- index command structure ---------\n\
            $ ipmt index [options] textfile\n\
            --------- command ---------\n\
            textfile                 : Arquivo em formato com extensão txt contendo o texto para indexação;\n\\n\\n\
            --------- search command structure ---------\n\
            $ ipmt search [options] pattern indexfile\n\
            --------- command <options> ---------\n\
            -p, --pattern            :   Opção referente a utilização de um arquivo de padrões, onde é realizada a leitura em cada linha desse arquivo. Essa opção necessita de uma arquivo com extensão txt(patternfile);\n\\n\
            -c, --cout               :   Imprime uma linha com o total de ocorrências do padrão no arquivo e exclui a exibição das linhas das ocorrências; \n\\n\
            patternfile              :   Arquivo de texto contendo um ou mais padrões. Cada padrão é estruturado em uma linha do arquivo;\n\\n\
            indexfile                :   Arquivo indexado para realização de busca;\n\\n\
            pattern                  :   String contendo padrão para busca;", VERSION_CODE);
    exit(-1);
}

