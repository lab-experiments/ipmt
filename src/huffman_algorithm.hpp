//
//  huffman_algorithm.hpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely on 2/13/16.
//  Copyright © 2016 tmbs. All rights reserved.
//

#ifndef huffman_algorithm_hpp
#define huffman_algorithm_hpp

#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <fstream>
#include <sstream>
#include "generic_compressor.hpp"
#include "tree_struct.hpp"

using namespace std;

class HuffmanAlgorithm : public GenericCompression
{
    
public:
    
    void Encode(string input_file_name);
    void Decode(string input_file_name);
    
private:
    
    int table_size;
    Node* table;
    map<char, string> m_codeword;
    
    void BuildHuffmanTree();

    void GenerateCode( TreeNode *node );
    void DestroyNode( TreeNode *node );
    
};
#endif /* huffman_algorithm_hpp */
