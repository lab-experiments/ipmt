/*
  @file: generic_compressor.hpp
  @brief: Classe abstrata representa a interface para algoritmos de compressão.
*/

#ifndef generic_compressor_hpp
#define generic_compressor_hpp

#include <stdio.h>

class GenericCompression
{
    
public:
    
    virtual void Encode(const char* input_file_name) = 0;
    
    virtual void Decode(const char* input_file_name) = 0;

};
#endif /* generic_compressor_hpp */
