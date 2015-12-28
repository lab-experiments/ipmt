//
//  Command_h
//  ipmt-xcode
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include "input_model.hpp"

class Command
{
    
public:
    
    virtual void Execute() = 0;
   
protected:
    
    void SetInputModel(InputModel input_model)
    {
        m_input_model = input_model;
    }
    
    InputModel GetInputModel()
    {
        return m_input_model;
    }

private:
    
    InputModel m_input_model;
    
};
#endif /* Command_h */
