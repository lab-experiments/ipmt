//
//  manipulation_files.hpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef manipulation_file_hpp
#define manipulation_file_hpp

#include <sys/stat.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class ManipulationFile
{
    
public:
    
    static bool IsFile(const string& name);
    
    vector<string> static GetFileLines(string file_name);
    
    static void CreateIndexFile(string file_name, vector<string>index_put_lines);
    
    int GetCompressionType(string line);
    
private:
    
    static string GetNameWithoutPrefix(string file_name);
    

};
#endif /* manipulation_file_hpp */
