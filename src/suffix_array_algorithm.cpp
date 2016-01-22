/*
  @file: suffix_array_algorithm.cpp
  @brief: Arquivos com implementações do método de conversão do arquivo de texto para
  um arquivo de index.
*/

#include "suffix_array_algorithm.hpp"

/**
  @brief: Método responsável realizar as sequências de ações para criação de um arquivo de index. Ler o arquivo de texto, executa a compressão com base nesses arquivos e escreve o resultado(indexes) em um arquivo de texto.
 */
void SuffixArrayAlgorithm::ConvertTextInIndex(string file_name,
                                              string output_file_name)
{
    string input_text = ManipulationFile::FileRead(file_name);
    size_t text_length = input_text.length();
    
    BuildSuffixArray(input_text, text_length);
    
    if (!output_text.empty()) {
        ManipulationFile::FileWrite(file_name, output_text.c_str());
        cout << "--- Arquivo de index gerado com sucesso ---" << "\n";
    }else{
        Error::ShowException("Problemas ao realizar a indexação do arquivo.");
    }
    output_text.clear();

}

/**
 * @brief: métodos para construção do arquivo de index utilizando array de sufixo.(Uma construção O(nLogn)). Para criação do sufixo foi utilizado todo o texto como entrada armazenado em memória  como uma string.
 */
void SuffixArrayAlgorithm::BuildSuffixArray(string &input_text, size_t text_length)
{
    /*
      @brief: inicializa o ponteiro de Suffix com o tamanho total do texto de entrada.
      armazena as informações do sufixo.
     */
    struct Suffix* suffix = new Suffix[text_length];
    
    /* 
      @brief: Armazena os sufixos(indice e posição em uma matriz de estruturas. Necessária para classificar os sufixos em ordem alfabética e manter as posições atual e anterior.
     */
    for (size_t i = 0; i < text_length; i++)
    {
        suffix[i].index = (int)i;
        suffix[i].position[0] = input_text[i];
        suffix[i].position[1] = ((i+1) < text_length)? (input_text[i + 1]): -1;
    }
    /*
      @brief: Organiza os sufixos usando a função de comparação.
     */
    sort(suffix, suffix + text_length, ComparationSuffixPair);
    
    /* 
     @brief: cria um array como os itens "originais". A partir do indice original
      é possível realizar o mapeamento para as próximas posições.*/
    int* original_index = new int[text_length];
    
    /*
       @brief:todos os sufixos são classificadas de acordo com a 2 primeiros caracteres.Os sufixos são posicionados de acordo com as primeiras caracter.
     */
    for (size_t k = 4; k < 2 * text_length; k = k*2)
    {
        int position = 0;
        int previous_position = suffix[0].position[0];
        suffix[0].position[0] = position;
        original_index[suffix[0].index] = 0;
        
        /* @brief: posiciona(ordena) os sufixos */
        for (size_t i = 1; i < text_length; i++)
        {
            /*
             @brief: se o primeiro posicionamento e o proximo são os mesmo que o sufixo anterior, atribui a mesma classificação a este novo sufixo.
             */
            if (suffix[i].position[0] == previous_position &&
                suffix[i].position[1] == suffix[i-1].position[1])
            {
                previous_position = suffix[i].position[0];
                suffix[i].position[0] = position;
            }else{
                previous_position = suffix[i].position[0];
                suffix[i].position[0] = ++position;
            }
            original_index[suffix[i].index] = (int)i;
        }

        /* @brief: Atribui a próxima posição para cada sufixo */
        for (size_t i = 0; i < text_length; i++)
        {
            size_t next_index = suffix[i].index + k/2;
            suffix[i].position[1] = (next_index < text_length)?
            suffix[original_index[next_index]].position[0]: -1;
        }
        
        sort(suffix, suffix + text_length, ComparationSuffixPair);
    }
      
    /* @brief: "limpar" atributo com auto valor em memória */
    delete [] original_index;

    /* 
      @brief: converte os arquivos de index para uma string a ser escrita em no arquivo
       idx.
     */
    for (size_t i = 0; i < text_length; i++){
        output_text.append(to_string(suffix[i].index)+" ");
    }
    
    /* @brief: "limpar" atributos com auto valor em memória */
    input_text.clear();
    text_length = 0;
    delete [] suffix;
}

/**
 * @brief: método resposável por classificar de acordo com os dois primeiros caracteres atribuir uma classificação a todos os sufixos usando valor ASCII do primeiro caractere.
 */
int SuffixArrayAlgorithm::ComparationSuffixPair(struct Suffix suffix_one, struct Suffix suffix_two)
{
    int position_temp = 0;
    if (suffix_one.position[0] == suffix_two.position[0]) {
        if (suffix_one.position[1] < suffix_two.position[1]) {
            position_temp = 1;
        }else{
            position_temp = 0;
        }
        
    }else if (suffix_one.position[0] < suffix_two.position[0]){
            position_temp = 1;
        
    }else{
            position_temp = 0;
        
    }
    
    return position_temp;
}


