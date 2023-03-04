/*
Author: Stephen Aranda
Date  : 3/3/23
File  : tree.cpp
Desc  : Specification file for tree.h
*/

#include "tree.h"
#include <iostream>

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

void IntBinaryTree::insertNode(int num)
{

    TreeNode *newNode; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->m_value = num;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{

    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        std::cout << nodePtr->m_value << std::endl;
        displayInOrder(nodePtr->right);
    }
}