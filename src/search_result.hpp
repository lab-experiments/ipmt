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
    
    static void ShowTextLinesOccurrences( vector<string> &out_lines );
    static void ShowOccurrenceNumbersPatterns(long &occurrence_numbers );

};
#endif /* search_result_hpp */
