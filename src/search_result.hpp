//
//  search_result.hpp
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

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
    
    SearchResult(vector<long> m_occurrence_per_line, vector<string> m_out_lines, bool has_total_occurrence);
    void SearchResultOut();
    
private :
    
    vector<long> m_occurrence_per_line;
    vector<string> m_out_lines;
    bool m_has_total_pattern_occurrence;
    void ShowTotalPatternOccurrence();

};
#endif /* search_result_hpp */
