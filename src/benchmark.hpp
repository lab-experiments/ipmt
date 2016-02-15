#ifndef benchmark_hpp
#define benchmark_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include "suffix_array_algorithm.hpp"
#include "lz78_algorithm.hpp"
#include "huffman_algorithm.hpp"

using namespace std;

static size_t GetBuffer(const char* file_name){
    
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    return size_t(size);
}

static void RunSuffixArray(){
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);
    
    /////////// Index - MEASURING EXECUTION TIME /////////////
    size_t index_begin_buffer =  GetBuffer("file.txt");
    
    auto index_begin_time = std::chrono::system_clock::now();
    
    SuffixArrayAlgorithm* generic_indexing = new SuffixArrayAlgorithm();
    generic_indexing->ConvertTextInIndex("file.txt");
    
    auto index_end_time = std::chrono::system_clock::now();
    auto index_duration = std::chrono::duration_cast<std::chrono::milliseconds>( index_end_time -
                                                                                index_begin_time ).count();
    
    size_t index_end_buffer =  GetBuffer("file.idx");
    
    metrics_file << "\n" << "---- Indexing Execution ----" << "\n";
    metrics_file <<  "Time : " << index_duration << "\n";
    metrics_file << "Buffer arquivo de entrada : " << index_begin_buffer << "\n";
    metrics_file << "Buffer arquivo de saida : " << index_end_buffer << "\n";
    
    ////////////////////////////////////////////////////////////
    
    metrics_file.close();

}


static void RunHuffmanEncode()
{
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);
    
    ///////// Decode - MEASURING EXECUTION TIME //////////////
    size_t encode_begin_buffer =  GetBuffer("file.idx");
    
    auto encode_begin_time = std::chrono::system_clock::now();
    
    HuffmanAlgorithm* generic_decompression = new HuffmanAlgorithm();
    generic_decompression->Encode("file.idx");
    
    auto encode_end_time = std::chrono::system_clock::now();
    auto encode_duration = std::chrono::duration_cast<std::chrono::milliseconds>( encode_end_time - encode_begin_time ).count();
    
    size_t encode_end_buffer =  GetBuffer("file.idx");
    
    metrics_file << "\n" << "---- Encoding Execution ----" << "\n";
    metrics_file << " Time : " << encode_duration << "\n";
    metrics_file << " Buffer arquivo de entrada : " << encode_begin_buffer << "\n";
    metrics_file << " Buffer arquivo de saida : " << encode_end_buffer << "\n";
    /////////////////////////////////////////////////////////////
    
    metrics_file.close();

};

static void RunHuffmanDecode()
{
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);
    
    ///////// Decode - MEASURING EXECUTION TIME //////////////
    size_t encode_begin_buffer =  GetBuffer("file.idx");
    
    auto encode_begin_time = std::chrono::system_clock::now();
    
    HuffmanAlgorithm* generic_decompression = new HuffmanAlgorithm();
    generic_decompression->Decode("file.idx");
    
    auto encode_end_time = std::chrono::system_clock::now();
    auto encode_duration = std::chrono::duration_cast<std::chrono::milliseconds>( encode_end_time - encode_begin_time ).count();
    
    size_t encode_end_buffer =  GetBuffer("file.idx");
    
    metrics_file << "\n" << "---- Decoding Execution ----" << "\n";
    metrics_file << " Time : " << encode_duration << "\n";
    metrics_file << " Buffer arquivo de entrada : " << encode_begin_buffer << "\n";
    metrics_file << " Buffer arquivo de saida : " << encode_end_buffer << "\n";
    /////////////////////////////////////////////////////////////
    
    metrics_file.close();
    
};


#endif /* benchmark_hpp */
