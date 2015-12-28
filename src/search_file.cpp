//
//  Search.cpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "error.hpp"
#include "manipulation_file.hpp"
#include "boyer_moore_algorithm.hpp"
#include "search_result.hpp"
#include "search_file.hpp"


Search::Search(InputModel input_model)
{
    SetInputModel(input_model);
}


void Search::Execute()
{
    std::vector<std::string> v_pattern_lines = Search::GetPattern();

    SearchInPattern(v_pattern_lines);
}


void Search::SearchInPattern(std::vector<std::string> v_pattern_lines)
{
    std::ifstream file;
    file.open(GetInputModel().GetTextFileName());
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
            Error::ShowException("Arquivo corrompido ou inexistente.");
        }
        
    }
    file.close();

    
    SearchResult  search_result = SearchResult(result_by_line, out_lines, GetInputModel().HasNumberTotalPattern());
    search_result.SearchResultOut();
}

std::vector<std::string> Search::GetPattern()
{
    std::vector<std::string> v_pattern_lines;
    std::string pattern_name = GetInputModel().GetPatternFile();
    if(ManipulationFile::IsFile(pattern_name)){
        v_pattern_lines = ManipulationFile::GetFileLines(pattern_name);
        
    }else{
        v_pattern_lines.push_back(pattern_name);
        
    }
    
    return v_pattern_lines;
}





