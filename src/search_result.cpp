/*
 @file: search_result.cpp
 @brief: arquivo responsável implementar os métodos de exibição de resultado e exibição de tortal de casamentos de padrão realizados. 
 
*/

#include "search_result.hpp"

SearchResult::SearchResult(long &occurrence_numbers, vector<string> &out_lines)
{
    m_occurrence_numbers = occurrence_numbers;
    m_out_lines = out_lines;
}

/*
  @brief: método que exibi no console as linhas onde ocorreu casamento de padrão
 */
void SearchResult::ShowTextLinesOccurrences()
{
    for (unsigned int i = 0; i < (unsigned)m_out_lines.size(); i++)
    {
        printf("%s \n", m_out_lines[i].c_str());
    }
    printf("----------------------------------------------\n");
    
    m_out_lines.clear();
    
    if(m_occurrence_numbers > 0)
    {
        ShowOccurrenceNumbersPatterns();
    }
}


void SearchResult::ShowOccurrenceNumbersPatterns()
{
    printf("Número total de ocorrências : %lu\n",m_occurrence_numbers);
}


