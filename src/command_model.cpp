//
//  command_model.cpp
//  ipmt
//
//  Created by Thaisa Mirely.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "command_model.hpp"

using namespace std;

string CommandModel::GetPatternFile()
{
    return m_pattern_file;
}

string CommandModel::GetTextFileName()
{
    return m_file_name;
}

bool CommandModel::HasNumberTotalPattern()
{
    return m_has_number_total_pattern;
}

int CommandModel::GetCompressionPattern()
{
    return m_compression_type;
}

int CommandModel::GetCommandType()
{
    return m_command_type;
}

int CommandModel::GetIndexType()
{
    return m_index_type;
}

void CommandModel:: SetPatternFile(string pattern_file)
{
    m_pattern_file = pattern_file;
}

void CommandModel::SetFileName(string file_name)
{
    m_file_name = file_name;
}

void CommandModel::SetHasNumberTotalPattern(bool status)
{
    m_has_number_total_pattern = status;
}

void CommandModel::SetCompressioType(int compression_type)
{
    m_compression_type = compression_type;
}

void CommandModel::SetIndexType(int index_type)
{
    m_index_type = index_type;
}

void CommandModel::SetCommandType(int command_type)
{
    m_command_type = command_type;
}
