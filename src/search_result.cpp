/*
 @file: search_result.cpp
 @brief: arquivo responsável implementar os métodos de exibição de resultado e exibição de tortal de casamentos de padrão realizados. 
 
*/

#include "search_result.hpp"

SearchResult::SearchResult(long &occurrence_per_line, vector<string> &out_lines, bool has_total_occurrence)
{
    m_out_lines = out_lines;
    m_has_total_pattern_occurrence = has_total_occurrence;
    m_occurrence_per_line = occurrence_per_line;
    
}

/*
  @brief: método que exibi no console as linhas onde ocorreu casamento de padrão
 */
void SearchResult::SearchResultOut()
{
    for (unsigned int i = 0; i < (unsigned)m_out_lines.size(); i++)
    {
        printf("%s \n", m_out_lines[i].c_str());
    }
    
    printf("----------------------------------------------\n");
    
    m_out_lines.clear();
    
    if(m_has_total_pattern_occurrence){
        SearchResult::ShowTotalPatternOccurrence();
    }
}


void SearchResult::ShowTotalPatternOccurrence()
{
    printf("Número total de ocorrências : %lu\n",m_occurrence_per_line);
    
}


