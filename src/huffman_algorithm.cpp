//
//  huffman_algorithm.cpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely on 2/13/16.
//  Copyright © 2016 tmbs. All rights reserved.
//

#include "huffman_algorithm.hpp"

void HuffmanAlgorithm::Encode( string input_file_name )
{
    map<char, int> frequency; // frequency for each char from input text
    int i;
    
    //  Opening input file
    //
    FILE *inputFile;
    inputFile = fopen( input_file_name.c_str(), "r" );
    assert( inputFile );
    
    //  Counting chars
    char character;
    unsigned total_character = 0;
    while( fscanf( inputFile, "%c", &character ) != EOF )
    {
        frequency[character]++;
        total_character++;
    }
    table_size = (int)frequency.size();
    
    //  Building decreasing frequency table
    table = new Node[table_size];

    float ftot = float(total_character);
    map<char, int>::iterator iterator;
    for( iterator=frequency.begin(),i=0; iterator!=frequency.end(); ++iterator,++i )
    {
        table[i].character = (*iterator).first;
        table[i].probability = float((*iterator).second) / ftot;
    }
    qsort( table, table_size, sizeof(Node), NodeCompare );
    
    //  Encoding
    BuildHuffmanTree();
    
    //  Opening output file
    string temp_out_put_name ="temp_encoded_"+input_file_name;
    FILE *outputFile;
    outputFile = fopen( temp_out_put_name.c_str(), "wb" );
    assert( outputFile );
    
    //  Outputing table and m_codewords
    fprintf( outputFile, "%i""\n", table_size );
    for( i=0; i<table_size; i++ )
    {
        fprintf(outputFile, "%c\t%f\t%s""\n", table[i].character, table[i].probability, m_codeword[table[i].character].c_str() );
    }
    
    //  Outputing encoded text
    fseek( inputFile, SEEK_SET, 0 );

    fprintf(outputFile, "\n");
    while( fscanf( inputFile, "%c", &character ) != EOF )
    {
        fprintf(outputFile, "%s", m_codeword[character].c_str());
    }
    
    //  Cleaning
    m_codeword.clear();
    delete[] table;
    
    //  Closing files
    fclose( outputFile );
    fclose( inputFile );
    
    remove(input_file_name.c_str());
    rename(temp_out_put_name.c_str(), input_file_name.c_str());
}

void HuffmanAlgorithm::Decode( string input_file_name)
{
    //  Opening input file
    FILE *inputFile;
    inputFile = fopen( input_file_name.c_str(), "r" );
    assert( inputFile );

    //  Loading m_codewords
    fscanf( inputFile, "%i", &table_size );
    char character, code[128];
    float p;
    int i;
    fgetc( inputFile ); // skip end line
    for( i=0; i<table_size; i++ )
    {
        character = fgetc(inputFile);
        fscanf( inputFile, "%f %s", &p, code );
        m_codeword[character] = code;
        fgetc(inputFile); // skip end line
    }
    fgetc(inputFile); // skip end line
    
    //  Opening output file
    string temp_out_put_name ="temp_decoded_"+input_file_name;
    FILE *outputFile;
    outputFile = fopen( temp_out_put_name.c_str(), "w" );
    assert( outputFile );
    
    //  Decoding and outputing to file
    string accum = "";
    map<char, string>::iterator iterator;
    while((character = fgetc(inputFile)) != EOF)
    {
        accum += character;
        for( iterator=m_codeword.begin(); iterator!=m_codeword.end(); ++iterator )
            if( !strcmp( (*iterator).second.c_str(), accum.c_str() ) )
            {
                accum = "";
                fprintf( outputFile, "%c", (*iterator).first );
            }
    }
    
    //  Cleaning
    fclose( outputFile );
    fclose( inputFile );
    
    remove(input_file_name.c_str());
    rename(temp_out_put_name.c_str(), input_file_name.c_str());

}

void HuffmanAlgorithm::BuildHuffmanTree()
{
    //  Creating leaves (initial top-nodes)
    //
    TreeNode *node;
    vector<TreeNode*> tops; // top-nodes
    int total_caracter=table_size;
    for( int i=0; i<total_caracter; i++ )
    {
        node = new TreeNode;
        node->character = table[i].character;
        node->probability = table[i].probability;
        node->left = NULL;
        node->right = NULL;
        tops.push_back( node );
    }
    
    //  Building binary tree.
    //  Combining last two nodes, replacing them by new node
    //  without invalidating sort
    //
    while( total_caracter > 1 )
    {
        node = new TreeNode;
        node->probability = tops[total_caracter-2]->probability + tops[total_caracter-1]->probability;
        node->left = tops[total_caracter-2];
        node->right = tops[total_caracter-1];
        
        if( node->left->probability < node->right->probability ){
            node->left_code = '0';
            node->right_code = '1';
            
        }else{
            node->left_code = '1';
            node->right_code = '0';
        }
        
        tops.pop_back();
        tops.pop_back();
        
        bool isins = false;
        std::vector<TreeNode*>::iterator iterador;
        for( iterador=tops.begin(); iterador!=tops.end(); ++iterador ){
            if( (*iterador)->probability < node->probability ){
                tops.insert( iterador, node );
                isins = true;
                break;
            }
        }
        if( !isins ) tops.push_back( node );
        total_caracter--;
    }
    
    //  Building m_codewords
    TreeNode *root = tops[0];
    GenerateCode( root );
    
    //  Cleaning
    DestroyNode( root );
    tops.clear();
}

void HuffmanAlgorithm::GenerateCode( TreeNode *node )
{
    static string sequence = "";
    if( node->left )
    {
        sequence += node->left_code;
        GenerateCode( node->left );
    }
    
    if( node->right )
    {
        sequence += node->right_code;
        GenerateCode( node->right );
    }
    
    if( !node->left && !node->right )
        m_codeword[node->character] = sequence;
    
    int sequence_length = (int)sequence.length();
    if( sequence_length > 1 ){
        sequence = sequence.substr( 0, sequence_length-1 );
        
    }else{
      sequence = "";
        
    }
}

void HuffmanAlgorithm::DestroyNode( TreeNode *node )
{
    if( node->left ){
        DestroyNode( node->left );
        delete node->left;
        node->left = NULL;
    }
    
    if( node->right ){
        DestroyNode( node->right );
        delete node->right;
        node->right = NULL;
    }
}
