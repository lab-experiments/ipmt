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
    m_input_file_name = GetInputModel().GetTextFileName();
    size_t lastindex = m_input_file_name.find_last_of(".");
    m_output_file_name = "./" + m_input_file_name.substr(0, lastindex)+".idx";
}

void Indexing::Execute()
{
    IndexingExecute();
    
    CompressionExecute();

}

/**
  @brief: seleciona o tipo de indexão com base na opção informada em linha de 
  comando ou utiliza indexação via array de sufixo por padrão.
 */
void Indexing::IndexingExecute()
{
    GenericIndexing* generic_indexing = new SuffixArrayAlgorithm();
    generic_indexing->ConvertTextInIndex(m_input_file_name.c_str(), m_output_file_name.c_str());

}


/**
  @brief: seleciona o algoritmo de compressão com base na opção informada
  em linha de ou utiliza o LZ78 como padrão.
*/
void Indexing::CompressionExecute()
{
    GenericCompression* generic_compression = new HuffmanAlgorithm();;
    generic_compression->Encode(m_output_file_name.c_str());

}
