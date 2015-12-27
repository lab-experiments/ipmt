//
//  Search.cpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "error.h"
#include "command_model.hpp"
#include "manipulation_file.hpp"
#include "boyer_moore_algorithm.hpp"
#include "search_file.hpp"
#include "search_result.hpp"

Search::Search(CommandModel command_model)
{
    Search::command_model = command_model;
}

void Search::Execute()
{
    std::vector<std::string> v_pattern_lines = Search::GetPattern();

    Search::SearchInPattern(v_pattern_lines);
}


void Search::SearchInPattern(std::vector<std::string> v_pattern_lines)
{
    std::ifstream file;
    file.open(Search::command_model.GetTextFileName());
    std::string line;
    std::vector<long> result_by_line;
    std::vector<std::string> out_lines;

    for (int index = 0; v_pattern_lines.size() > index; index++) {
        
        if (file.is_open()){
            while (std::getline(file, line))
            {
                result_by_line.push_back
                (SearchUsingBoyerMoore(v_pattern_lines[index], line));
                
                if(!result_by_line.empty()){
                    out_lines.push_back(line);
                }
            }
        }else{
            ShowException("Arquivo corrompido ou inexistente.");
        }
        
    }
    file.close();

}

std::vector<std::string> Search::GetPattern()
{
    std::vector<std::string> v_pattern_lines;
    std::string pattern_name = Search::command_model.GetPatternFile();
    if(ManipulationFile::IsFile(pattern_name)){
        v_pattern_lines = ManipulationFile::GetFileLines(pattern_name);
        
    }else{
        v_pattern_lines.push_back(pattern_name);
        
    }
    
    return v_pattern_lines;
}





