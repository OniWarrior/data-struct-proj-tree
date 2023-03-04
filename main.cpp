/*Author: stephen aranda
  File  : main.cpp
  Desc  : Entry point to answer data structs homework questions for current homework.
  Date  : 3/1/23
*/

#include "tree.cpp"

int main()
{

  // create the binary tree.
  IntBinaryTree tree;

  std::cout << "*********Welcome to my demonstration tree app**********************\n\n";

  // Insert some values.
  tree.insertNode(1);
  tree.insertNode(2);
  tree.insertNode(3);
  tree.insertNode(4);

  // Display the current values in the tree.
  std::cout << "\nHere are the values in the tree: \n";

  std::cout << std::endl;
  std::cout << std::endl;

  // Display the current number of nodes in the tree.
  tree.displayInOrderNumNodes();
}