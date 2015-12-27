//
//  manipulation_files.cpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <sys/stat.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "error.h"
#include "input_control.hpp"
#include "manipulation_file.hpp"


bool ManipulationFile::IsFile(const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

std::vector<std::string> ManipulationFile::GetFileLines(std::string file_name)
{    
    std::ifstream file;
    file.open(file_name);
    std::vector<std::string> v_out_lines;
    std::string line;
    
    if (file.is_open()){
        while (getline(file, line)){
            v_out_lines.push_back(line);
        }
        file.close();
    }else{
        ShowException("Arquivo corrompido ou inexistente.");
    }
    
    return v_out_lines;
}


void ManipulationFile::CreateIndexFile(std::string file_name, std::vector<std::string>index_put_lines)
{
    std::ofstream file;
    file.open("./"+file_name+".idx");
    
    if (file.is_open()){
        std::ostream_iterator<std::string> output_iterator(file, "\n");
        std::copy(index_put_lines.begin(), index_put_lines.end(), output_iterator);
        file.close();
        
    }else{
        ShowException("Arquivo corrompido ou inexistente.");
    }
}


std::ofstream ManipulationFile::GetIndexFileConvertedForTextFile(std::string file_name)
{
    size_t lastindex = file_name.find_last_of(".");
    std::string rawname = file_name.substr(0, lastindex);

    std::ofstream file;
    file.open(rawname+(".txt"));

    return file;
}
