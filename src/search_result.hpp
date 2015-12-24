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

#include "command_model.hpp"

using namespace std;

class SearchResult{
    
private :
    CommandModel command_model;
    vector<int> m_occurrence_per_line;
    vector<string> m_out_lines;
    
public:
    SearchResult(CommandModel command_model, vector<int> m_occurrence_per_line, vector<string> m_out_lines);
    void SearchResultOut();
    void ShowTotalPatternOccurrence();

};
#endif /* search_result_hpp */
