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
    vector<string> v_pattern_lines = Search::GetPattern();

    SearchInPattern(v_pattern_lines);
    
    SearchResult  search_result = SearchResult(m_n_ocurrence_by_line, m_out_lines, GetInputModel().HasNumberTotalPattern());
    search_result.SearchResultOut();

}


void Search::SearchInPattern(vector<string> v_pattern_lines)
{
    ifstream file;
    file.open(GetInputModel().GetTextFileName());
    string line;

    for (int index = 0; v_pattern_lines.size() > index; index++) {
        
        if (file.is_open()){
            while (getline(file, line))
            {
                m_n_ocurrence_by_line = SearchUsingBoyerMoore(v_pattern_lines[index], line);
                if(m_n_ocurrence_by_line != 0){
                    m_out_lines.push_back(line);
                    m_n_ocurrence_by_line ++;
                }
            }
        }else{
            Error::ShowException("Arquivo corrompido ou inexistente.");
        }
        
    }
    
    file.close();
}

vector<string> Search::GetPattern()
{
    vector<std::string> v_pattern_lines;
    string pattern_name = GetInputModel().GetPatternFile();
    if(ManipulationFile::IsFile(pattern_name)){
        v_pattern_lines = ManipulationFile::GetFileLines(pattern_name);
        
    }else{
        v_pattern_lines.push_back(pattern_name);
        
    }
    
    return v_pattern_lines;
}





