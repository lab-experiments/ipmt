/*
  @file: search_file.cpp
  @brief: classe de implementação dos dos métodos de decodificação e busca.
*/


#include "search_file.hpp"

Search::Search(InputModel input_model)
{
    SetInputModel(input_model);
    m_input_file_name = GetInputModel().GetTextFileName();
}


void Search::Execute()
{
    DecodeFile();

    SearchPatternInIndex();
    
    if (!m_out_lines.empty()) {
        SearchResult::ShowTextLinesOccurrences(m_out_lines);
        if (GetInputModel().ShowNumberPatternOccurrences()) {
           SearchResult::ShowOccurrenceNumbersPatterns(m_occurrence_numbers);
        }
    }
    
}

void Search::DecodeFile()
{
    GenericCompression* generic_compression = new HuffmanAlgorithm();
    generic_compression->Decode(m_input_file_name.c_str());
}

void Search::SearchPatternInIndex()
{
    ManipulationFile::IndexFileProperty ifp = ManipulationFile::ReadIndexFile(m_input_file_name.c_str());
    
    vector<string> v_pattern_lines = Search::GetPattern();
    index = ifp.p_index;
    string last_value = "";
    
    for (size_t i = 0; i < v_pattern_lines.size(); i++)
    {
        for(size_t j = 0; j < ifp.v_text.size(); j++)
        {
            BinarySearch(v_pattern_lines[i].c_str(), ifp.v_text[j].c_str(),  ifp.v_text[j].length());
            if (m_occurrence_numbers > 0) {
                if( ifp.v_text[j] != last_value)
                {
                    m_out_lines.push_back(ifp.v_text[j]);
                    last_value = ifp.v_text[j];
                }
            }
        }
    }
    
    //limpando campos
    delete index;
    last_value.clear();
    ifp.v_text.clear();
    v_pattern_lines.clear();
}

void Search::BinarySearch(const char* pattern, const char* text, size_t text_size)
{
    long long pattern_lenght = strlen(pattern);
    long long lenght = 0;
    long long r = text_size-1;
    while (lenght <= r)
    {
        long long mid = lenght + (r - lenght)/2;
        int return_ = strncmp(pattern, text + index[mid], pattern_lenght);
        
        if (return_ == 0){
            m_occurrence_numbers++;
        }
        
        if (return_ < 0){
            r = mid - 1;
            
        }else{
            lenght = mid + 1;
        }
    }
}


vector<string> Search::GetPattern()
{
    vector<std::string> v_pattern_lines;
    const char* pattern_name = GetInputModel().GetPatternFileName().c_str();
    
    if(ManipulationFile::IsFile(pattern_name)){
        v_pattern_lines = ManipulationFile::GetFileLines(pattern_name);
        
    }else{
        v_pattern_lines.push_back(pattern_name);
        
    }
    
    return v_pattern_lines;
}

