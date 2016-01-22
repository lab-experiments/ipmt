/*
  @file: manipulation_files.cpp
  @brief: arquivo responsável por implementar os métodos que manipulam arquivos de texto e de index.
*/

#include "manipulation_file.hpp"


bool ManipulationFile::IsFile(string name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

/*
  @brief: método retorna um vetor onde cada index representa uma linha do arquivo.
 */
vector<string> ManipulationFile::GetFileLines(string file_name)
{    
    ifstream file;
    file.open(file_name);
    vector<string> v_out_lines;
    string line;
    
    if (file.is_open()){
        while (getline(file, line)){
            v_out_lines.push_back(line);
        }
        file.close();
    }else{
        Error::ShowException("Arquivo corrompido ou inexistente.");
    }
    
    return v_out_lines;
}


/*
  @brief: a função retorna o primeiro caracter que representa o tipo de compressão.
 */
int ManipulationFile::GetCompressionType(string file_name)
{
    ifstream file(file_name);
    char c;
    int value = 0;
    int i = 0;
    
    if (file.is_open()){
        while (file.get(c) && i == 0){
            value = atoi(&c);
            i++;
        }
        file.close();

    }else{
        Error::ShowException("Arquivo corrompido ou inexistente.");
    }
        
    return value;
}


string ManipulationFile::ConvertDecimalToBinary(const int& input)
{
    return std::bitset<8>(input).to_string();
}

int ManipulationFile::ConvertBinaryToDecimal(const char& input)
{
    std::bitset<8> dec(input);
    return (int)dec.to_ulong();
}

string ManipulationFile::ConvertStringToASCII(const string& input)
{
    return std::bitset<8>(input[0]).to_string();
}

/*
  @brief: função retorna o arquivo informado via parâmetro, como uma string.
 */
string ManipulationFile::FileRead(string file_name)
{
    ifstream file(file_name);
    stringstream buffer;
    buffer << file.rdbuf();
    
    string input = buffer.str();
    
    if (input.empty()) {
        Error::ShowException("Problemas ao realizar a indexação do arquivo.");
    }
    return input;
}

/*
  @brief: cria um arquivo com o dados do parâmetro @input
 */
void ManipulationFile::FileWrite(string file_name, const string input)
{
    ofstream file_out(file_name);
    file_out.clear();
    file_out << input;
    if (input.empty()) {
        Error::ShowException("Problemas ao gerar criar o arquivo.");
    }
    file_out.close();
}

void ManipulationFile::FileWriteBinary(string file_name, const string input)
{
    string eight_bits;
    long temp;
    char output;
    ofstream file_out(file_name);
    file_out.clear();
    
    for (unsigned int x = 0; x < (unsigned)input.length(); x += 8)
    {
        eight_bits = input.substr(x, 8);
        temp = strtol(eight_bits.c_str(),0, 2);
        output = temp & 0xffl;
        file_out << output;
    }
    
    file_out.close();
}

/*
  @brief: converte o arquivo de index(FILE) descoprimido em um ponteiro de inteiros.
 */
int* ManipulationFile::ConvertStringFileInInt(string file_name, size_t& out_put)
{
    vector<int> v_index;
    string input_text = ManipulationFile::FileRead(file_name);
    stringstream ss(input_text);
    string token;
    
    while (ss >> token) {
        v_index.push_back(atoi(token.c_str()));
    }
    input_text.clear();
    
    int* suffixes = new int[v_index.size()];
    for (unsigned int i = 0; i < (unsigned)v_index.size(); i++) {
        suffixes[i] = v_index[i];
    }
    out_put = v_index.size();
    
    v_index.clear();
    
    return suffixes;
}

bool ManipulationFile::IsIndexFile(string file_name)
{
    return (file_name.substr(file_name.find_last_of(".") + 1) == "idx") ? true : false;
}

