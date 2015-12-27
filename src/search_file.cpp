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

void Search::SearchPattern(CommandModel command_model)
{
    Search::command_model = command_model;
    std::vector<std::string> v_pattern_lines = Search::GetPattern();

    Search::SearchInFile(v_pattern_lines);
}


void Search::SearchInFile(std::vector<std::string> v_pattern_lines)
{
    std::ifstream file;
    file.open(Search::command_model.GetTextFileName());
    std::string line;
    int index = 0;
    std::vector<int> result_by_line;
    
    for (index; v_pattern_lines.size() > index; index++) {
        if (file.is_open()){
            while (std::getline(file, line)){
               result_by_line.push_back(SearchUsingBoyerMoore(v_pattern_lines[index], line, duration));
                
                n_BM_duratio_excecution.push_back(duration);
                
                if(!result_by_line.empty()){
                    n_lines.push_back(index);
                    out_lines.push_back(line);
                    occurrence_per_line.push_back((int)result_by_line.size());
                }
            }
        }else{
            ShowException("Arquivo corrompido ou inexistente.");
        }
        
        SearchResultOut(commad_model.GetTextFileNames()[j].c_str());
    }
    file.close();

}

std::vector<std::string> GetPattern()
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





