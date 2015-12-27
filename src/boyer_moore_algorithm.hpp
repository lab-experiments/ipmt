//
//  boyer_moore_algorithm.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef boyer_moore_algorithm_hpp
#define boyer_moore_algorithm_hpp

#include <stdio.h>
#include <string.h>
#include <vector>

#include "command_model.hpp"

std::vector<int> SearchUsingBoyerMoore(CommandModel command_line, std::string text_line, long long& duration);

#endif /* boyer_moore_algorithm_hpp */
