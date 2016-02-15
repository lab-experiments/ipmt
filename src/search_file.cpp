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

    DecodeFile();
    
//    SearchPatternInIndex();
//    
//    SearchResult  search_result = SearchResult(m_number_ocurrence, m_out_lines, GetInputModel().HasNumberTotalPattern());
//    search_result.SearchResultOut();
    

}

void Search::DecodeFile()
{
    
    GenericCompression* generic_compression = new HuffmanAlgorithm();
    generic_compression->Decode(m_file_name);

}

void Search::SearchPatternInIndex()
{
//    size_t output_text_size;
//    
//    int* indexing = ManipulationFile::ConvertStringFileInInt(m_file_name, output_text_size);
//    vector<string> v_pattern_lines = Search::GetPattern();
//
//    for (int index = 0; v_pattern_lines.size() > index; index++) {
//        size_t m = v_pattern_lines[index].length();
//        const char* pattern = v_pattern_lines[index].c_str();
//        int l = 0, r = (int)output_text_size-1;
//        while (l <= r)
//        {
//            int mid = l + (r - l)/2;
//            int res = strncmp(pattern, indexing[mid], m);
//            
//            if (res == 0)
//            {
//                cout << "Pattern found at index " << indexing[mid];
//                return;
//            }
//            if (res < 0) r = mid - 1;
//            else l = mid + 1;
//        }
//    }
//    
//    delete indexing;
//    v_pattern_lines.clear();

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
