/*
  @file: lz78_algorithm.hpp
  @brief: classe de compressão implementando conceitos relativos ao algoritmo LZ78
*/

#ifndef lz78_algorithm_hpp
#define lz78_algorithm_hpp

#include <stdio.h>
#include <time.h>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iostream>
#include <fstream>
#include <string>
#include "manipulation_file.hpp"
#include "generic_compressor.hpp"

using namespace std;

class LZ78Algorithm : public GenericCompression
{
    
public:
    
    void Encode(string file_name);
    void Decode(string file_name);
    
};
#endif /* lz78_algorithm_hpp */
