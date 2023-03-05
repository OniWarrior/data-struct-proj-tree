/*
Author: Stephen Aranda
Date  : 3/3/23
File  : tree.cpp
Desc  : Specification file for tree.h
*/

#include "tree.h"
#include <iostream>
#include <queue>

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

int IntBinaryTree::getSearchProp() const { return m_searchProp; }
int IntBinaryTree::getNumFull() const { return m_numFull; }
int IntBinaryTree::getNumNodes() const { return m_count; }
int IntBinaryTree::getNumLeaves() const { return m_leaves; }

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{

    if (nodePtr)
    {

        if (nodePtr->left)
        {
            destroySubTree(nodePtr->left);
        }

        if (nodePtr->right)
        {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }
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

void IntBinaryTree::setNumFull(TreeNode *&nodePtr)
{

    if (!nodePtr)
    {
        return;
    }
    else if (nodePtr->left && nodePtr->right)
    {
        m_numFull++;
    }
    if (nodePtr->left)
    {
        setNumFull(nodePtr->left);
    }
    if (nodePtr->right)
    {
        setNumFull(nodePtr->right);
    }
}

void IntBinaryTree::searchAndTestForOrder(TreeNode *nodePtr, int prevNodeVal, bool isSatisfied)
{

    if (nodePtr)
    {
        searchAndTestForOrder(nodePtr->left, prevNodeVal, m_searchProp);
        if (nodePtr->m_value > prevNodeVal)
        {
            m_searchProp = true;
            prevNodeVal = nodePtr->m_value;
        }
        else
        {
            m_searchProp = false;
            prevNodeVal = nodePtr->m_value;
        }
        searchAndTestForOrder(nodePtr->right, prevNodeVal, m_searchProp);
    }
}

void IntBinaryTree::setNumNodes(TreeNode *nodePtr)
{

    if (nodePtr)
    {
        // count the current node
        setNumNodes(nodePtr->left);
        m_count++; // variable that represents the number of nodes.
        setNumNodes(nodePtr->right);
    }
}

void IntBinaryTree::setNumLeaves(TreeNode *&nodePtr)
{
    if (!nodePtr)
    {
        return;
    }
    else if (!nodePtr->left && !nodePtr->right)
    {
        m_leaves++;
        return;
    }
    if (nodePtr->left)
    {
        setNumLeaves(nodePtr->left);
    }
    if (nodePtr->right)
    {
        setNumLeaves(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{

    if (nodePtr)
    {

        std::cout << nodePtr->m_value << std::endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{

    if (nodePtr)
    {

        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        std::cout << nodePtr->m_value << std::endl;
    }
}

void IntBinaryTree::displayLevelOrder(TreeNode *nodePtr)
{
    int level = 0;
    std::queue<TreeNode *> myQueue;

    if (nodePtr == nullptr)
    {
        return;
    }

    myQueue.push(nodePtr);
    myQueue.push(nullptr);

    while (myQueue.size() != 0)
    {

        TreeNode *frontQ = myQueue.front();
        myQueue.pop();

        if (frontQ == nullptr)
        {

            if (myQueue.size() == 0)
            {
                std::cout << "Level " << level << std::endl;
                break;
            }

            std::cout << "Level " << level << std::endl;
            level++;
            myQueue.push(nullptr);
        }
        else
        {
            std::cout << frontQ->m_value << " ";

            if (frontQ->left != nullptr)
            {
                myQueue.push(frontQ->left);
            }

            if (frontQ->right != nullptr)
            {
                myQueue.push(frontQ->right);
            }
        }
    }
}

bool IntBinaryTree::searchNode(int num)
{

    TreeNode *nodePtr = root;

    while (nodePtr)
    {

        if (nodePtr->m_value == num)
        {
            return true;
        }
        else if (num < nodePtr->m_value)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }
    return false;
}

void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{

    if (num < nodePtr->m_value)
    {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->m_value)
    {
        deleteNode(num, nodePtr->right);
    }
    else
    {
        makeDeletion(nodePtr);
    }
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{

    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode *tempNodePtr;

    if (nodePtr == nullptr)
    {
        std::cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // reattach the left child.
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {

        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child.
        delete tempNodePtr;
    }
    else
    { // If the node has two children.

        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
        {

            tempNodePtr = tempNodePtr->left;
        }

        // reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}