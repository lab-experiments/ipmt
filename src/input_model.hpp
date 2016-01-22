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
    
    void SetPatternFile(string pattern_file);
    void SetFileName(string file_name);
    void SetHasNumberTotalPattern(bool status);
    void SetCompressioType(int compression_type);
    void SetIndexType(int index_type);
    void SetCommandType(int command_type);
    
    string GetPatternFile();
    string GetTextFileName();
    bool HasNumberTotalPattern();
    int GetCompressionType();
    int GetIndexType();
    int GetCommandType();
    
    enum CompressionType
    {
        LZ78,
        LZ77
    };
    
    enum IndexType
    {
        suffix_array,
        suffix_tree
    };
    
    enum InputType
    {
        index,
        search
    };
    
private:
    
    string m_pattern_file;
    string m_file_name;
    bool m_has_number_total_pattern;
    int m_compression_type;
    int m_index_type;
    int m_command_type;

};
#endif /* command_model_hpp */
