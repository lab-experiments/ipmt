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
    
    static bool IsFile(string name);
    
    static vector<string> GetFileLines(string file_name);
    
    static void CreateBinaryFile(string file_name, size_t size, int* array_suffix);
    
    static int* ReadBinaryIndexFile(string file_name);
    
    static void FileWrite(string file_name, const string input);

    static string FileRead(string file_name);
    
    static void CreateIndexFile(string file_name, string input, size_t input_text_lenght);
    
    static IndexFileProperty ReadIndexFile(string input_file_name);

};
#endif /* manipulation_file_hpp */
