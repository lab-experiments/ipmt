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
    
    SearchResult(long &m_occurrence_per_line, vector<string> &m_out_lines, bool has_total_occurrence);
    void SearchResultOut();
    
private :
    
    long m_occurrence_per_line;
    vector<string> m_out_lines;
    bool m_has_total_pattern_occurrence;
    
    void ShowTotalPatternOccurrence();

};
#endif /* search_result_hpp */
