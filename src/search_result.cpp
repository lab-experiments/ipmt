//
//  search_result.cpp
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <vector>

#include "command_model.hpp"
#include "search_result.hpp"

SearchResult::SearchResult(CommandModel command_model, vector<int> m_occurrence_per_line, vector<string> m_out_lines)
{
    SearchResult::command_model = command_model;
    SearchResult::SearchResultOut();
    
    if(SearchResult::command_model.HasNumberTotalPattern()){
        SearchResult::ShowTotalPatternOccurrence();
    }
    
}

void SearchResult::SearchResultOut()
{
    for (int i = 0; i < SearchResult::m_out_lines.size(); i++)
    {
        printf("[%s] : %s \n ", SearchResult::command_model.GetTextFileName().c_str(), SearchResult::m_out_lines[i].c_str());
    }
    
    printf("----------------------------------------------\n");
    
    SearchResult::m_out_lines.clear();
}


void SearchResult::ShowTotalPatternOccurrence()
{
    printf("Número total de ocorrências : %lu\n",
           SearchResult::m_occurrence_per_line.size());
    
    SearchResult::m_occurrence_per_line.clear();
}
