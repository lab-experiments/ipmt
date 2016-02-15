/*
  @file: search_file.cpp
  @brief: classe de implementação dos dos métodos de decodificação e busca.
*/


#include "search_file.hpp"

Search::Search(InputModel input_model)
{
    SetInputModel(input_model);
    m_file_name = GetInputModel().GetTextFileName();

}


void Search::Execute()
{

  //  DecodeFile();
    SearchPatternInIndex();
    
//    SearchResult  search_result = SearchResult(m_number_ocurrence, m_out_lines, GetInputModel().ShowNumberPatternOccurrences());
//    search_result.SearchResultOut();
//    
//
}

void Search::DecodeFile()
{
    GenericCompression* generic_compression = new HuffmanAlgorithm();
    generic_compression->Decode(m_file_name);
}

void Search::SearchPatternInIndex()
{
    ManipulationFile::IndexFileProperty ifp = ManipulationFile::ReadIndexFile(m_file_name);
    
    vector<string> v_pattern_lines = Search::GetPattern();
    
    for (int i = 0; i < v_pattern_lines.size(); i++)
    {
        for(int j = 0; j < ifp.v_text.size(); j++)
        {
            BinarySearch(v_pattern_lines[i].c_str(),  ifp.v_text[j].c_str(), ifp.p_index, ifp.v_text[j].length());
        }
    }
}

void Search::BinarySearch(const char* pattern, const char* text, int* index, size_t text_size)
{
    size_t pattern_lenght = strlen(pattern);
    size_t lenght_ = 0;
    size_t r = text_size-1;
    while (lenght_ <= r)
    {
        size_t mid = lenght_ + (r - lenght_)/2;
        int return_ = strncmp(pattern, text + index[mid], pattern_lenght);
        
        if (return_ == 0){
            cout << "Pattern found at index " << index[mid]<< "\n";
        }
        
        if (return_ < 0){
            r = mid - 1;
            
        }else{
            lenght_ = mid + 1;
        }
    }
}


vector<string> Search::GetPattern()
{
    vector<std::string> v_pattern_lines;
    string pattern_name = GetInputModel().GetPatternFileName();
    
    if(ManipulationFile::IsFile(pattern_name)){
        v_pattern_lines = ManipulationFile::GetFileLines(pattern_name);
        
    }else{
        v_pattern_lines.push_back(pattern_name);
        
    }
    
    return v_pattern_lines;
}
