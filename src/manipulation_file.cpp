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
        while (getline(file, line, '\n')){
            v_out_lines.push_back(line);
        }
        file.close();
    }else{
        Error::ShowException("Arquivo corrompido ou inexistente.");
    }
    
    return v_out_lines;
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

void ManipulationFile::CreateIndexFile(string file_name, string input, size_t input_text_lenght)
{
    //open text file e get size
    ifstream text_file(file_name);
    
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
    combined_file << to_string(input_text_lenght) << "\n" << text_file.rdbuf()  << "\n" << file_out_index.rdbuf();
    
    //close all files
    text_file.close();
    file_out_index.close();
    combined_file.close();
    
    //remove temporary files
    remove(file_name.c_str());
    remove(temp_index_file_name);
    
}


ManipulationFile::IndexFileProperty ManipulationFile::ReadIndexFile(string input_file_name)
{
    ifstream file(input_file_name);
    string line;
    getline(file, line);
    int position = stoi(line.c_str());
    
    ManipulationFile::IndexFileProperty ifp;
    // lendo o texto
    long long  tll = file.tellg();
    
    while (tll < position) {
        getline(file, line);
        ifp.v_text.push_back(line);
        tll = file.tellg();
    }
    
    // lendo os indexes
    while (getline(file, line))
    {
        line = line;
    }

    stringstream ss(line);
    string token;
    vector<int> v_index;

    while (ss >> token) {
        v_index.push_back(atoi(token.c_str()));
    }

    ifp.p_index = new int[v_index.size()];
    for (unsigned int i = 0; i < (unsigned)v_index.size(); i++) {
        ifp.p_index[i] = v_index[i];
    }

    return ifp;
}

