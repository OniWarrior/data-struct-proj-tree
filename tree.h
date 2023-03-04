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
    TreeNode *root;    // Pointer to the root node
    int m_count = 0;   // current number of nodes.
    int m_leaves = 0;  // current number of leaves in the tree.
    int m_numFull = 0; // current number of full nodes in the tree.

    // Private member functions
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void destroySubTree(TreeNode *nodePtr);
    void deleteNode(int num, TreeNode *&nodePtr);
    void makeDeletion(TreeNode *&nodePtr);

    // Question 1 methods--------------------------
    void setNumLeaves(TreeNode *&nodePtr);
    void setNumNodes(TreeNode *nodePtr);
    void setNumFull(TreeNode *&nodePtr);
    //-------------------------------------
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

    // Question 1 methods----------------------------
    int getNumLeaves() const;
    int getNumNodes() const;
    int getNumFull() const;
    void calcNumFull() { setNumFull(root); }
    void calcNumLeaves() { setNumLeaves(root); }
    void calcNumNodes() { setNumNodes(root); }
    // ---------------------------------------------
    void displayInOrder() const { displayInOrder(root); }
    void displayPreOrder() const { displayPreOrder(root); }
    void displayPostOrder() const { displayPostOrder(root); }
};

#endif