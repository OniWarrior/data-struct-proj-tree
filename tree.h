/*
  Author: Stephen Aranda
  File  : tree.h
  Desc  : Declaration file for tree that will be used to answer homework questions
  Date  : 3/1/23
*/

#ifndef _INT_BINARY_TREE_H_
#define _INT_BINARY_TREE_H_

struct TreeNode
{
    int m_value;     // The value in the node.
    TreeNode *left;  // Pointer to left child node
    TreeNode *right; // Pointer to right child node
};

#endif