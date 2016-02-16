/*
  @file: search_result.hpp
  @brief: Classe responsável por exibir no console o resultado da busca.
  
*/

#ifndef search_result_hpp
#define search_result_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

class SearchResult
{
    
public:
    
    SearchResult( long &occurrence_numbers, vector<string> &m_out_lines );
    void ShowTextLinesOccurrences();

private :
    
    long m_occurrence_numbers = 0;
    vector<string> m_out_lines;
    
    void ShowOccurrenceNumbersPatterns();

};
#endif /* search_result_hpp */
