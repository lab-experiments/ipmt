//
//  manipulation_files.cpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "error.hpp"
#include "manipulation_file.hpp"


bool ManipulationFile::IsFile(const string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}


vector<string> ManipulationFile::GetFileLines(string file_name)
{    
    ifstream file;
    file.open(file_name);
    vector<string> v_out_lines;
    string line;
    
    if (file.is_open()){
        while (getline(file, line)){
            v_out_lines.push_back(line);
        }
        file.close();
    }else{
        Error::ShowException("Arquivo corrompido ou inexistente.");
    }
    
    return v_out_lines;
}



void ManipulationFile::CreateIndexFile(string file_name, vector<string>index_put_lines)
{
    string name = ManipulationFile::GetNameWithoutPrefix(file_name);
    ofstream file;
    file.open("./"+ name +".idx");

    if (file.is_open()){
        ostream_iterator<string> output_iterator(file, "\n");
        copy(index_put_lines.begin(), index_put_lines.end(), output_iterator);
        
        file.close();
        
    }else{
        Error::ShowException("Problema na construção do arquivo de index.");
    }
}



string ManipulationFile::GetNameWithoutPrefix(string file_name)
{
    size_t lastindex = file_name.find_last_of(".");
    string rawname = file_name.substr(0, lastindex);

    return rawname;
}



int ManipulationFile::GetCompressionType(string line)
{
    int compression_type = line.at(0);
    
    return compression_type;
}

