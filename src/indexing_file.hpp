/*
  @file: index.hpp
  @brief: classe responsável por executar os comandos referentes a indexação do
  arquivo de texto de entrada. Seleciona o tipo de indexação e compressão do arquivo.
 
*/

#ifndef indexing_file_hpp
#define indexing_file_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include "error.hpp"
#include "suffix_array_algorithm.hpp"
#include "lz78_algorithm.hpp"
#include "huffman_algorithm.hpp"
#include "manipulation_file.hpp"
#include "command.hpp"

using namespace std;

class Indexing : public Command
{
    
public:
    
    Indexing(InputModel input_model);
    void Execute();
    
private:

    string  m_file_name;
    string  m_output_file_name;

    void IndexingExecute();
    void CompressionExecute();

};
#endif /* indexing_file_hpp */
