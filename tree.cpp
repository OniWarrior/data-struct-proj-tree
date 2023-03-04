/*
Author: Stephen Aranda
Date  : 3/3/23
File  : tree.cpp
Desc  : Specification file for tree.h
*/

#include "tree.h"

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{

    if (nodePtr == nullptr)
    {
        nodePtr = newNode; // Insert the node.
    }
    else if (newNode->m_value < nodePtr->m_value)
    {
        insert(nodePtr->left, newNode); // Search the left branch.
    }
    else
    {
        insert(nodePtr->right, newNode); // Search the right branch.
    }
}