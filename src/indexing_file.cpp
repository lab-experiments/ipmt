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
    size_t lastindex = m_file_name.find_last_of(".");
    m_output_file_name = "./" + m_file_name.substr(0, lastindex)+".idx";
    
}

void Indexing::Execute()
{
  //  IndexingExecute();
    
    CompressionExecute();

}

/**
  @brief: seleciona o tipo de indexão com base na opção informada em linha de 
  comando ou utiliza indexação via array de sufixo por padrão.
 */
void Indexing::IndexingExecute()
{
    GenericIndexing* generic_indexing = NULL;

    switch (GetInputModel().GetIndexType())
    {
        case InputModel::suffix_tree:
        {
            // generic_indexing = new SuffixTreeAlgorithm();
            break;
        }
        case InputModel::suffix_array:
        default:
            generic_indexing = new SuffixArrayAlgorithm();
            break;
    }
    
    generic_indexing->ConvertTextInIndex(m_file_name, m_output_file_name.c_str());

}


/**
  @brief: seleciona o algoritmo de compressão com base na opção informada
  em linha de ou utiliza o LZ78 como padrão.
*/
void Indexing::CompressionExecute()
{
    GenericCompression* generic_compression = NULL;
    
    switch (GetInputModel().GetCompressionType())
    {
        case InputModel::LZ77:
        {
            //generic_compression = new LZ77Algorithm();
            break;
        }
        case InputModel::LZ78:
        default:
            generic_compression = new LZ78Algorithm();
            break;
    }
    
   generic_compression->Encode(m_file_name);

}
