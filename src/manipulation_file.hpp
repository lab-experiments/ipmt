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
#include "error.hpp"

using namespace std;

class ManipulationFile
{
    
public:
    
    static bool IsIndexFile(string name);
    
    static bool IsFile(string name);
    
    static vector<string> GetFileLines(string file_name);
        
    static int GetCompressionType(string file_name);
    
    static void FileWriteBinary(string file_name, const string input);
    
    static void FileWrite(string file_name, const string input);

    static string FileRead(string file_name);

    static string ConvertStringToASCII(const string& input);
    
    static int ConvertBinaryToDecimal(const char& input);
    
    static string ConvertDecimalToBinary(const int& input);
    
    static int* ConvertStringFileInInt(string file_name, size_t& out_put);
    
};
#endif /* manipulation_file_hpp */
