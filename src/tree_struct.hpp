//
//  node.hpp
//  ipmt-xcode
//
//  Created by Thaisa Mirely on 2/13/16.
//  Copyright © 2016 tmbs. All rights reserved.
//

#ifndef tree_struct_hpp
#define tree_struct_hpp

#include <stdio.h>

struct Node
{
    char character; // char
    float probability; // probability
};

struct TreeNode : public Node
{
    char left_code;
    char right_code;
    TreeNode *left; // left child
    TreeNode *right; // right child
};

static int NodeCompare( const void *element_1, const void *element_2 )
{
    const Node a = *(Node*)element_1;
    const Node b = *(Node*)element_2;
    if( a.probability < b.probability ){
        return 1;
    }else if( a.probability > b.probability ){
        return -1;
    }
    return 0;
}

#endif /* tree_struct_hpp */
