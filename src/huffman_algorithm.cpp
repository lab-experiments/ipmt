/*
 @file: huffman_algorithm.cpp
 @brief: arquivo de implementação dos métodos da classe HuffmanAlgorithm.
 */


#include "huffman_algorithm.hpp"

void HuffmanAlgorithm::Encode( const char* input_file_name )
{
    // armazena cada caracter e a frequência de cada um
    map<char, int> frequency;
    int i;
    
    FILE *inputFile;
    inputFile = fopen( input_file_name, "r" );
//    assert( inputFile );
    
    //conta o número de caracteres
    char character;
    unsigned total_character = 0;
    while( fscanf( inputFile, "%c", &character ) != EOF )
    {
        frequency[character]++;
        total_character++;
    }
    table_size = (int)frequency.size();
    
    //tabela de frequência de caracteres
    table = new Node[table_size];

    float total_char = float(total_character);
    map<char, int>::iterator iterator;
    for( iterator=frequency.begin(),i=0; iterator!=frequency.end(); ++iterator,++i )
    {
        table[i].character = (*iterator).first;
        table[i].probability = float((*iterator).second) / total_char;
    }
    qsort( table, table_size, sizeof(Node), NodeCompare );
    
    //  Codificação
    BuildHuffmanTree();
    
    //cria um arquivo temporário para criação da tabela e códigos
    const char* temp_out_put_name ="temp_encoded";
    FILE *outputFile;
    outputFile = fopen( temp_out_put_name, "wb" );
   // assert( outputFile );
    
    // escreve no arquivo a tabela e cpodigos
    fprintf( outputFile, "%i""\n", table_size );
    for( i=0; i<table_size; i++ )
    {
        fprintf(outputFile, "%c\t%f\t%s""\n", table[i].character, table[i].probability, m_codeword[table[i].character].c_str() );
    }
    
    fseek( inputFile, SEEK_SET, 0 );
    fprintf(outputFile, "\n");
    while( fscanf( inputFile, "%c", &character ) != EOF )
    {
        fprintf(outputFile, "%s", m_codeword[character].c_str());
    }
    
    //limpa memória
    m_codeword.clear();
    delete[] table;
    
    fclose( outputFile );
    fclose( inputFile );
    
    remove(input_file_name);
    rename(temp_out_put_name, input_file_name);
}

void HuffmanAlgorithm::Decode( const char* input_file_name)
{
    FILE *inputFile;
    inputFile = fopen( input_file_name, "r" );
    //assert( inputFile );

    // carrega os códigos
    fscanf( inputFile, "%i", &table_size );
    char character, code[128];
    float p;
    int i;
    fgetc( inputFile );
    for( i=0; i<table_size; i++ )
    {
        character = fgetc(inputFile);
        fscanf( inputFile, "%f %s", &p, code );
        m_codeword[character] = code;
        fgetc(inputFile);
    }
    fgetc(inputFile);
    
    //cria um arquivo temporário para armazenar a descodificação preservando o arquivo
    //de entrada com a tabela.
    const char* temp_out_put_name ="temp_decoded_";
    FILE *outputFile;
    outputFile = fopen( temp_out_put_name, "w" );
//    assert( outputFile );
    
    //decodifica e adiciona no arquivo de saida
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
    
    fclose( outputFile );
    fclose( inputFile );
    
    remove(input_file_name);
    rename(temp_out_put_name, input_file_name);

}

void HuffmanAlgorithm::BuildHuffmanTree()
{
    //cria as folhas da árvore
    TreeNode *node;
    vector<TreeNode*> tops;
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

    // constroi a arvore binária combinando últimos dois nós, substituindo-os por novo nó
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
        if( !isins )
        {
            tops.push_back( node );
        }
        total_caracter--;
    }
    
    //constroi os códigos
    TreeNode *root = tops[0];
    BuildCodewords( root );
    
    //destroi os nós criados anteriormente
    DestroyNode( root );
    tops.clear();
}

void HuffmanAlgorithm::BuildCodewords( TreeNode *node )
{
    static string sequence = "";
    if( node->left )
    {
        sequence += node->left_code;
        BuildCodewords( node->left );
    }
    
    if( node->right )
    {
        sequence += node->right_code;
        BuildCodewords( node->right );
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
