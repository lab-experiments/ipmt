/*
  @file: Search.hpp
  @brief: Classe responsável pelo comando de busca. Descompacta o arquivo e realiza uma busca com base no padrão formado. 
*/

#ifndef search_file_hpp
#define search_file_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "command.hpp"
#include "error.hpp"
#include "manipulation_file.hpp"
#include "lz78_algorithm.hpp"
#include "huffman_algorithm.hpp"
#include "search_result.hpp"

using namespace std;

class Search : public Command
{

public:
    
    Search(InputModel input_model);
    void Execute();
    
private:
    
    //long m_number_ocurrence;
    string m_file_name;
    vector<string> m_out_lines;
    
    vector<string> GetPattern();
    void DecodeFile();
    void SearchPatternInIndex();
    void BinarySearch(const char* pattern, const char* text, int* index, size_t text_size);
    
};
#endif /* Search_File_hpp */
