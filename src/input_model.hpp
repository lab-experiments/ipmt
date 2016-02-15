/*
 @file: command_model.hpp
 @brief: Classe de modelo responsável por conter todos os atributos(e métodos de acesso
 desse atributo) de uma comando.
*/

#ifndef command_model_hpp
#define command_model_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

class InputModel {
    
public:
    
    void SetPatternFileName(string pattern_file_name);
    void SetTextFileName(string text_file_name);
    void SetShowNumberPatternOccurrences(bool status);
    void SetCompressioType(int compression_type);
    void SetCommandType(int command_type);
    
    string GetPatternFileName();
    string GetTextFileName();
    bool ShowNumberPatternOccurrences();
    int GetCompressionType();
    int GetCommandType();
    
    enum CompressionType
    {
        lz78
    };
    
    enum InputType
    {
        index,
        search
    };
    
private:
    
    string m_pattern_file_name;
    string m_text_file_name;
    bool m_show_number_pattern_occurrences;
    int m_compression_type;
    int m_command_type;

};
#endif /* command_model_hpp */
