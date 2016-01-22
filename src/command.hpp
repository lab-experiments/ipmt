/*
  @file: command.hpp
  @brief: Classe abstrada utilizda com base no padrão Factory Method. Um objeto Command é composto por um método de execução. É a classe base dos obejtos relativos a commandos como IndexingFile e SearchFile.
*/

#ifndef command_hpp
#define command_hpp

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
#endif /* command_hpp */
