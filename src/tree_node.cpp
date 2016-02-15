//
//  tree_node.cpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely on 2/12/16.
//  Copyright © 2016 tmbs. All rights reserved.
//

#include "tree_node.hpp"

TreeNode::TreeNode(map<char, string> code_words)
{
    m_code_words = code_words;
}

void TreeNode::GenerateCode(TreeNode *node)
{
    static std::string sequence = "";
    if( node->left )
    {
        sequence += node->left_code_word;
        GenerateCode( node->left);
    }
    
    if( node->right )
    {
        sequence += node->right_code_word;
        GenerateCode( node->right);
    }
    
    if( !node->left && !node->right )
        m_code_words[node->character] = sequence;
    
    int l = (int)sequence.length();
    if( l > 1 ) sequence = sequence.substr( 0, l-1 );
    else sequence = "";
}

void TreeNode::DestroyNode( TreeNode *node )
{
    if( node->left )
    {
        DestroyNode( node->left );
        delete node->left;
        node->left = NULL;
    }
    
    if( node->right )
    {
        DestroyNode( node->right );
        delete node->right;
        node->right = NULL;
    }
}
