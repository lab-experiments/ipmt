/*
  @file: command_model.cpp
  @brief: Implementação dos métodos de acesso da classe InputMode.
*/

#include "input_model.hpp"

using namespace std;

string InputModel::GetPatternFile()
{
    return m_pattern_file;
}

string InputModel::GetTextFileName()
{
    return m_file_name;
}

bool InputModel::HasNumberTotalPattern()
{
    return m_has_number_total_pattern;
}

int InputModel::GetCompressionType()
{
    return m_compression_type;
}

int InputModel::GetCommandType()
{
    return m_command_type;
}

int InputModel::GetIndexType()
{
    return m_index_type;
}

void InputModel::SetPatternFile(string pattern_file)
{
    m_pattern_file = pattern_file;
}

void InputModel::SetFileName(string file_name)
{
    m_file_name = file_name;
}

void InputModel::SetHasNumberTotalPattern(bool status)
{
    m_has_number_total_pattern = status;
}

void InputModel::SetCompressioType(int compression_type)
{
    m_compression_type = compression_type;
}

void InputModel::SetIndexType(int index_type)
{
    m_index_type = index_type;
}

void InputModel::SetCommandType(int command_type)
{
    m_command_type = command_type;
}
