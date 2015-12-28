//
//  manipulation_files.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef manipulation_file_hpp
#define manipulation_file_hpp

#include <string.h>
#include <vector>
#include <fstream>

class ManipulationFile
{
    
public:
    
    bool static IsFile(const std::string& name);
    
    std::vector<std::string> static GetFileLines(std::string file_name);
    
    void CreateIndexFile(std::string file_name, std::vector<std::string>index_put_lines);
    
    std::ofstream GetIndexFileConvertedForTextFile(std::string file_name);
    
    int GetCompressionType(std::string line);

};
#endif /* manipulation_file_hpp */
