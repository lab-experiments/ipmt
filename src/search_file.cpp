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
    
    if (!m_out_lines.empty()) {
        SearchResult search_result = SearchResult(m_occurrence_numbers, m_out_lines);
        search_result.ShowTextLinesOccurrences();
    }
    
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
    long long pattern_lenght = strlen(pattern);
    long long lenght = 0;
    long long r = text_size-1;
    while (lenght <= r)
    {
        long long mid = lenght + (r - lenght)/2;
        int return_ = strncmp(pattern, text + index[mid], pattern_lenght);
        
        if (return_ == 0){
          //  cout << "Index " << index[mid]<< "\n";
            if (GetInputModel().ShowNumberPatternOccurrences()) {
                m_occurrence_numbers++;
            }
        }
        
        if (return_ < 0){
            r = mid - 1;
            
        }else{
            lenght = mid + 1;
        }
    }
    
    if (m_occurrence_numbers > 0) {
        m_out_lines.push_back(text);
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

