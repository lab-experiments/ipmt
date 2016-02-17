/*
  @file: command_model.cpp
  @brief: Implementação dos métodos de acesso da classe InputMode.
*/

#include "input_model.hpp"

using namespace std;

string InputModel::GetPatternFileName()
{
    return m_pattern_file_name;
}

string InputModel::GetTextFileName()
{
    return m_text_file_name;
}

bool InputModel::ShowNumberPatternOccurrences()
{
    return m_show_number_pattern_occurrences;
}

int InputModel::GetCommandType()
{
    return m_command_type;
}

void InputModel::SetPatternFileName(string pattern_file)
{
    m_pattern_file_name = pattern_file;
}

void InputModel::SetTextFileName(string file_name)
{
    m_text_file_name = file_name;
}

void InputModel::SetShowNumberPatternOccurrences(bool status)
{
    m_show_number_pattern_occurrences = status;
}

void InputModel::SetCommandType(int command_type)
{
    m_command_type = command_type;
}
