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
//int ManipulationFile::GetCompressionType(string file_name)
//{
//    ifstream file(file_name);
//    char c;
//    int value = 0;
//    int i = 0;
//    
//    if (file.is_open()){
//        while (file.get(c) && i == 0){
//            value = atoi(&c);
//            i++;
//        }
//        file.close();
//
//    }else{
//        Error::ShowException("Arquivo corrompido ou inexistente.");
//    }
//        
//    return value;
//}


//string ManipulationFile::ConvertDecimalToBinary(const int& input)
//{
//    return std::bitset<8>(input).to_string();
//}
//
//int ManipulationFile::ConvertBinaryToDecimal(const char& input)
//{
//    std::bitset<8> dec(input);
//    return (int)dec.to_ulong();
//}
//
//string ManipulationFile::ConvertStringToASCII(const string& input)
//{
//    return std::bitset<8>(input[0]).to_string();
//}

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
        Error::ShowException("Arquivo de entrada vazio.");
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

//void ManipulationFile::FileWriteBinary(string file_name, const string input)
//{
//    string eight_bits;
//    long temp;
//    char output;
//    ofstream file_out(file_name);
//    file_out.clear();
//    
//    for (unsigned int x = 0; x < (unsigned)input.length(); x += 8)
//    {
//        eight_bits = input.substr(x, 8);
//        temp = strtol(eight_bits.c_str(),0, 2);
//        output = temp & 0xffl;
//        file_out << output;
//    }
//    
//    file_out.close();
//}

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

/*
 @brief: created binary file with idx extension
 Index file.
 */
void ManipulationFile::CreateBinaryFile(string file_name, size_t size, int* array_suffix)
{
    ofstream file(file_name, ios::binary | ios::ate);
    file.write(reinterpret_cast<const char*> (array_suffix), sizeof(int) * size);
    file.close();
    
    for (int i = 0; i < size; ++i)
        cout<<array_suffix[i]<<"\n";

}


int* ManipulationFile::ReadBinaryIndexFile(string file_name)
{
   ifstream file(file_name, ios::binary);
   size_t size = 0;
   file.seekg(0, ios::end); // set the pointer to the end
   size = file.tellg() ; // get the length of the file
   file.seekg(0, ios::beg); // set the pointer to the beginning
   
   int * index_pointer = new int[size];
   file.read(reinterpret_cast<char *>(index_pointer), sizeof(int) * size);
   file.close();
    
   return index_pointer;
}

void ManipulationFile::CreateIndexFile(string file_name, string input)
{
    //open text file e get size
    ifstream text_file(file_name);
    
    string text_lenght = to_string(GetSizeFile(text_file));
    
    //create temp index file
    const char* temp_index_file_name = "temp_index_.txt";
    ofstream file_out_temp_index(temp_index_file_name);
    file_out_temp_index << input;
    file_out_temp_index.close();

    //open temp index file
    ifstream file_out_index(temp_index_file_name);

    //create index file
    size_t lastindex = file_name.find_last_of(".");
    string m_output_file_name = "./" + file_name.substr(0, lastindex)+".idx";
    ofstream combined_file( m_output_file_name ) ;
    combined_file << text_lenght << "\n" << text_file.rdbuf() << file_out_index.rdbuf();
    
    //close all files
    text_file.close();
    file_out_index.close();
    combined_file.close();
    
    //remove temporary files
    remove(file_name.c_str());
    remove(temp_index_file_name);
    
    ReadIndexFile(m_output_file_name);

}

//istream& IgnoreLine(std::ifstream& in, std::ifstream::pos_type& pos)
//{
//    pos = in.tellg();
//    return in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//}
//
//string GetLastLine(ifstream& in)
//{
//    std::ifstream::pos_type pos = in.tellg();
//    
//    std::ifstream::pos_type lastPos;
//    while (in >> std::ws && IgnoreLine(in, lastPos))
//        pos = lastPos;
//    
//    in.clear();
//    in.seekg(pos);
//    
//    std::string line;
//    std::getline(in, line);
//    return line;
//}


ManipulationFile::IndexFileProperty ManipulationFile::ReadIndexFile(string input_file_name)
{
    ifstream file(input_file_name);
    string line;
    getline(file, line);
    int position = stoi(line.c_str());
    
    ManipulationFile::IndexFileProperty ifp;
    // lendo o texto
    cout << "texto : \n";
    long long  tll = file.tellg();
    
    while (tll < position) {
        getline(file, line);
        ifp.v_text.push_back(line);
        cout << line << "\n";
        tll = file.tellg();
    }
    
    
    // lendo os indexes
    getline(file, line);

    cout << line;

    stringstream ss(line);
    string token;
    
    while (ss >> token) {
        ifp.v_index.push_back(atoi(token.c_str()));
    }

    return ifp;
}

int ManipulationFile::GetSizeFile(std::ifstream& file)
{
    size_t length = 0;
    file.seekg(0, ios::end);
    length = file.tellg();
    file.seekg(0, ios::beg);
    int position = static_cast<int>(length);
    return position;
}


