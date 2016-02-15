/*
  @file: index.cpp
  @brief: arquivo de implementação dos métodos da classe IndexingFile.
*/

#include "indexing_file.hpp"

using namespace std;

Indexing::Indexing(InputModel input_model)
{
    SetInputModel(input_model);
    
    /**
     * @brief: cria do nome do arquivo de index com base no arquivo de entrada.
     */
    m_file_name = GetInputModel().GetTextFileName();

}

void Indexing::Execute()
{
    IndexingExecute();
    
   // CompressionExecute();

}

/**
  @brief: seleciona o tipo de indexão com base na opção informada em linha de 
  comando ou utiliza indexação via array de sufixo por padrão.
 */
void Indexing::IndexingExecute()
{
    GenericIndexing* generic_indexing = new SuffixArrayAlgorithm();
    generic_indexing->ConvertTextInIndex(m_file_name);

}


/**
  @brief: seleciona o algoritmo de compressão com base na opção informada
  em linha de ou utiliza o LZ78 como padrão.
*/
void Indexing::CompressionExecute()
{
    GenericCompression* generic_compression = new HuffmanAlgorithm();;
    generic_compression->Encode(m_output_file_name);

}
