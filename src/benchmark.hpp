#ifndef benchmark_hpp
#define benchmark_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include "suffix_array_algorithm.hpp"
#include "lz78_algorithm.hpp"

using namespace std;

static size_t GetBuffer(const char* file_name){
    
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    return size_t(size);
}

static void runSuffixArray(){
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);
    
    /////////////////////// Index - MEASURING EXECUTION TIME ////////////////////////////////////////////////////////////////
    size_t index_begin_buffer =  GetBuffer("file.txt");
    
    auto index_begin_time = std::chrono::system_clock::now();
    
    SuffixArrayAlgorithm* generic_indexing = new SuffixArrayAlgorithm();
    generic_indexing->ConvertTextInIndex("file.txt", "index.idx");
    
    auto index_end_time = std::chrono::system_clock::now();
    auto index_duration = std::chrono::duration_cast<std::chrono::milliseconds>( index_end_time - index_begin_time ).count();
    
    size_t index_end_buffer =  GetBuffer("index.txt");
    
    metrics_file << "\n" << "---- Indexing Execution ----" << "\n";
    metrics_file <<  "Time : " << index_duration << "\n";
    metrics_file << "Buffer arquivo de entrada : " << index_begin_buffer << "\n";
    metrics_file << "Buffer arquivo de saida : " << index_end_buffer << "\n";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    metrics_file.close();

}

static void runEncodeLZ78(){
    
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);

       /////////////////////// Encode - MEASURING EXECUTION TIME ////////////////////////////////////////////////////////
    size_t compress_begin_buffer =  GetBuffer("index.txt");

    auto compress_begin_time = std::chrono::system_clock::now();

    LZ78Algorithm* generic_compression =  new LZ78Algorithm();
    generic_compression->Encode("index.txt");

    auto compress_end_time = std::chrono::system_clock::now();
    auto compress_duration = std::chrono::duration_cast<std::chrono::milliseconds>( compress_end_time - compress_begin_time ).count();
    
    size_t compress_end_buffer =  GetBuffer("encode.txt");

    metrics_file << "\n" << "---- Encoding Execution ----" << "\n";
    metrics_file << "Time : " << compress_duration << "\n";
    metrics_file << "Buffer arquivo de entrada : " << compress_begin_buffer << "\n";
    metrics_file << "Buffer arquivo de saida : " << compress_end_buffer << "\n";
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    metrics_file.close();

}

static void runDecodeLZ78(){
    
    std::ofstream metrics_file("./metrics_file.txt", std::ofstream::binary | std::ofstream::app);

    /////////////////////// Decode - MEASURING EXECUTION TIME ////////////////////////////////////////////////////////
    size_t encode_begin_buffer =  GetBuffer("encode.txt");
    
    auto encode_begin_time = std::chrono::system_clock::now();
    
    LZ78Algorithm* generic_decompression = new LZ78Algorithm();
    generic_decompression->Decode("encode.txt");
    
    auto encode_end_time = std::chrono::system_clock::now();
    auto encode_duration = std::chrono::duration_cast<std::chrono::milliseconds>( encode_end_time - encode_begin_time ).count();
    
    size_t encode_end_buffer =  GetBuffer("decode.txt");
    
    metrics_file << "\n" << "---- Decoding Execution ----" << "\n";
    metrics_file << " Time : " << encode_duration << "\n";
    metrics_file << " Buffer arquivo de entrada : " << encode_begin_buffer << "\n";
    metrics_file << " Buffer arquivo de saida : " << encode_end_buffer << "\n";
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    metrics_file.close();

}

#endif /* benchmark_hpp */
