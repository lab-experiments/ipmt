/*
 @file: search_result.cpp
 @brief: arquivo responsável implementar os métodos de exibição de resultado e exibição de tortal de casamentos de padrão realizados. 
 
*/

#include "search_result.hpp"

/*
  @brief: método que exibi no console as linhas onde ocorreu casamento de padrão
 */
void SearchResult::ShowTextLinesOccurrences(vector<string> &out_lines)
{
    for (unsigned int i = 0; i < (unsigned)out_lines.size(); i++)
    {
        printf("%s \n", out_lines[i].c_str());
    }
    printf("----------------------------------------------\n");
    
    out_lines.clear();
    
}


void SearchResult::ShowOccurrenceNumbersPatterns(long &occurrence_numbers)
{
    printf("Número total de ocorrências : %lu\n",occurrence_numbers);
}


