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
#include "huffman_algorithm.hpp"
#include "search_result.hpp"

using namespace std;

class Search : public Command
{

public:
    
    Search(InputModel input_model);
    void Execute();
    void SearchPatternInIndex();

private:
    
    long m_occurrence_numbers = 0;
    vector<string> m_out_lines;
    string m_input_file_name;
    int* index;
    
    vector<string> GetPattern();
    void DecodeFile();
    void BinarySearch(const char* pattern, const char* text,size_t text_size);
    
};
#endif /* Search_File_hpp */
