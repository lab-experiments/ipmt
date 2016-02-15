//
//  tree_node.hpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely on 2/12/16.
//  Copyright © 2016 tmbs. All rights reserved.
//

#ifndef tree_node_hpp
#define tree_node_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "node.hpp"

using namespace std;

class TreeNode: public Node
{
 
public:
    
    char left_code_word;
    char right_code_word;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(map<char, string> code_words);
    TreeNode();
    void GenerateCode(TreeNode *node);
    void DestroyNode(TreeNode *node);
    
private:
    
    map<char, string> m_code_words;

};

#endif /* tree_node_hpp */
