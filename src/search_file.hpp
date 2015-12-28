//
//  Search.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef search_file_hpp
#define search_file_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "command.hpp"

using namespace std;

class Search : public Command
{

public:
    
    Search(InputModel input_model);
    void Execute();
    
private:
    
    void SearchInPattern(vector<string> v_pattern_lines);
    std::vector<string> GetPattern();
    
};
#endif /* Search_File_hpp */
