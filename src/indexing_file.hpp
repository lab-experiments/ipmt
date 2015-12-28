//
//  index.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef indexing_file_hpp
#define indexing_file_hpp

#include <stdio.h>
#include "command.hpp"

class Indexing : public Command
{
    
public:
    
    Indexing(InputModel input_model);
    void Execute();
    
private:
    

};
#endif /* indexing_file_hpp */
