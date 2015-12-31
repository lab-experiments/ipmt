//
//  command_model.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

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
    int GetCompressionPattern();
    int GetIndexType();
    int GetCommandType();
    
    enum CompressionType
    {
        LZ77,
        LZ78
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
