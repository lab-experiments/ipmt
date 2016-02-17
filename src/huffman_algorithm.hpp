/*
 @brief: huffman_algorithm.hpp
 @file: classe responsável por contr os métodos de compressão e descompressão, além dos métodos auxiliares para construção do arlgoritmo;
 
 */

#ifndef huffman_algorithm_hpp
#define huffman_algorithm_hpp

#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cassert>
#include "generic_compressor.hpp"
#include "tree_struct.hpp"

using namespace std;

class HuffmanAlgorithm : public GenericCompression
{
    
public:
    
    void Encode(const char* input_file_name);
    void Decode(const char* input_file_name);
    
private:
    
    int table_size;
    Node* table;
    map<char, string> m_codeword;
    
    void BuildHuffmanTree();

    void BuildCodewords( TreeNode *node );
    void DestroyNode( TreeNode *node );
    
};
#endif /* huffman_algorithm_hpp */
