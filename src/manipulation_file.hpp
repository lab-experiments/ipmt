/*
  @file: manipulation_files.hpp
  @brief: classe responsável por manipular arquivos de texto e realizar conversão.
*/

#ifndef manipulation_file_hpp
#define manipulation_file_hpp

#include <sys/stat.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <iostream>
#include "error.hpp"

using namespace std;

class ManipulationFile
{
    
public:
    
    struct IndexFileProperty
    {
        vector<string> v_text;
        int* p_index;
    };
    
    static bool IsIndexFile(string name);
    
    static bool IsFile(const char* name);
    
    static vector<string> GetFileLines(const char* file_name);
    
    static string FileRead(const char* file_name);
    
    static void CreateIndexFile(const char* input_file_name, const char* output_file_name, string input, size_t input_text_lenght);
    
    static IndexFileProperty ReadIndexFile(const char* input_file_name);
    
//
//    static void CreateBinaryFile(string file_name, size_t size, int* array_suffix);
//    
//    static int* ReadBinaryIndexFile(string file_name);

};
#endif /* manipulation_file_hpp */
