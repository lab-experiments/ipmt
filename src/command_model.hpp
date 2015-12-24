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
#include <iostream>

using namespace std;

class CommandModel {
    
private:
    
    string m_pattern_file;
    string m_file_name;
    bool m_has_number_total_pattern;
    int m_compression_type;
    int m_index_type;
    int m_command_type;
    
    
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
    
    enum CompressionType{
        LZ77 = 0,
        LZ78 = 1
    };
    
    enum IndexType{
        suffix_tree = 0,
        suffix_array = 1
    };


};
#endif /* command_model_hpp */
