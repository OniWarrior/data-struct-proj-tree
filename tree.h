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

class IntBinaryTree
{
private:
    TreeNode *root; // Pointer to the root node

    // Private member functions
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void destroySubTree(TreeNode *nodePtr);
    void deleteNode(int num, TreeNode *&nodePtr);
    void makeDeletion(TreeNode *&nodePtr);
    void displayInOrder(TreeNode *nodePtr) const;
    void displayPreOrder(TreeNode *nodePtr) const;
    void displayPostOrder(TreeNode *nodePtr) const;

public:
    IntBinaryTree() { root = nullptr; }
    ~IntBinaryTree() { destroySubTree(root); }

    // Binary tree operations
    void insertNode(int num);
    bool searchNode(int num);
    void remove(int num);
    void displayInOrder() const { displayInOrder(root); }
};

#endif