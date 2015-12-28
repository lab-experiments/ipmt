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
#include <sstream>
#include "search_result.hpp"


SearchResult::SearchResult(vector<long> occurrence_per_line, vector<string> out_lines, bool has_total_occurrence)
{
    m_occurrence_per_line = occurrence_per_line;
    m_out_lines = out_lines;
    m_has_total_pattern_occurrence = has_total_occurrence;
    
}


void SearchResult::SearchResultOut()
{
    for (int i = 0; i < m_out_lines.size(); i++)
    {
        printf("%s \n", m_out_lines[i].c_str());
    }
    
    printf("----------------------------------------------\n");
    
    SearchResult::m_out_lines.clear();
    
    if(m_has_total_pattern_occurrence){
        SearchResult::ShowTotalPatternOccurrence();
    }
}


void SearchResult::ShowTotalPatternOccurrence()
{
    printf("Número total de ocorrências : %lu\n", m_occurrence_per_line.size());
    
    m_occurrence_per_line.clear();
}


