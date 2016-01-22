/*
  @file: generic_indexing.hpp
  @brief: Classe abstrata para criação de "contrato" para ser utilizada como base dos algoritmos de indexação.
*/

#ifndef generic_indexing_hpp
#define generic_indexing_hpp

#include <stdio.h>

class GenericIndexing
{

public:

    virtual void ConvertTextInIndex(std::string input_file_name,std::string output_file_name)=0;

};
#endif /* generic_indexing_hpp */
