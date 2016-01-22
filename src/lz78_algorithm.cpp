/*
  @file: lz78_algorithm.cpp
  @brief: arquivo responsável por implementar os métodos de codificação e decodificação.
*/

#include "lz78_algorithm.hpp"

void LZ78Algorithm::Encode(string file_name)
{    
    map<string, int> dictionary;
    string text;
    string output_text_code;
    string character;
    string prefix;
    
    text = ManipulationFile::FileRead(file_name);
    
    for(size_t x = 0; x < text.length() ; ++x)
    {
        character = text.substr(x,1);
        
        /*@brief: Ao ler um caractere do arquivo, procuramos no dicionario se ele esta registrado.*/
        if(dictionary.count(prefix + character)){
            prefix += character;
            
        }else{
            /*@brief: caso seja encontra um caractere que não está presente no dicionário é introduzida uma sequencia com terminada no caracteber "inexistente". */
            
            if (prefix.empty()){
                output_text_code += "00000000";
                
            }else{
                output_text_code += ManipulationFile::ConvertDecimalToBinary(dictionary[prefix]);
            }
            output_text_code += ManipulationFile::ConvertStringToASCII(character);
            
            dictionary[prefix + character] = (key_t)dictionary.size() + 1;
            
            prefix.clear();

        }
    }
    /* @brief: "limpa" variaveis com auto consumo de memória */
    text.clear();
    dictionary.clear();
    
   // text.insert(0,ManipulationFile::ConvertStringToASCII("0"));// insert algorithm type for encode
    
    ManipulationFile::FileWriteBinary("encode.txt", output_text_code);
    cout << "--- Arquivo de index compactado com sucesso ---" << "\n";

    /* @brief: "limpa" variaveis com auto consumo de memória */
    output_text_code.clear();
    
}

void LZ78Algorithm::Decode(string file_name)
{

    map<int, string> dictionary;
    string output_text;
    string text;
    string character;
    int code_word;

    text = ManipulationFile::FileRead(file_name);
    
    for (size_t x = 0; x < text.length(); ++++x)
    {
        code_word = ManipulationFile::ConvertBinaryToDecimal(text[x]);
        character = text.substr(x + 1, 1);
        
        if (code_word != 0){
            output_text += dictionary[code_word];
        
        }
        
        output_text += character;
        
        if (code_word != 0){
            dictionary[(key_t)dictionary.size() + 1] = dictionary[code_word] + character;
        
        }else{
            dictionary[(key_t)dictionary.size() + 1] = character;
        
        }
    }
    
    text.clear();
    dictionary.clear();
    

    ManipulationFile::FileWrite("decode.txt", output_text);
    cout << "--- Arquivo de index descompactado com sucesso ---" << "\n";

    output_text.clear();
}
