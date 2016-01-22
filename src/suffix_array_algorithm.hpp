/*
  @brief: suffix_array_algorithm.hpp
  @file: Classe responsável por conter métodos e atributos referêntes a criação do arquivo de index.

*/

#ifndef suffix_array_algorithm_hpp
#define suffix_array_algorithm_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include "generic_indexing.hpp"
#include "manipulation_file.hpp"

using namespace std;

class SuffixArrayAlgorithm : public GenericIndexing
{

public:
    
    void ConvertTextInIndex(string file_name, string output_file_name);

private:

    string output_text;
    
    /**
     * @brief: Estrutura de um suffixo. Composta por index e posição(um array de inteiros com as posições atual e anterior.)
     */
    struct Suffix
    {
        int index;
        int position[2];
    };
    
    static int ComparationSuffixPair(struct Suffix suffix_one, struct Suffix suffix_two);
    
    void BuildSuffixArray(string &input, size_t _length);
    
};
#endif /* suffix_array_algorithm_hpp */
