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
#include "command_model.hpp"

using namespace std;

class Search{

private:
    
    CommandModel command_model;
    void SearchInFile(std::vector<std::string> v_pattern_lines);
    std::vector<std::string> GetPattern();

public:
    
    void SearchPattern(CommandModel command_model);// change for constructor Search()
    
};
#endif /* Search_File_hpp */
