/*Author: stephen aranda
  File  : main.cpp
  Desc  : Entry point to answer data structs homework questions for current homework.
  Date  : 3/1/23
*/

#include "tree.cpp"
#include <chrono>

int main()
{

  // timer for calcNumNodes execution time--setNumNodes is the actual method that calculates the number of nodes.
  auto startCalcNumNodesTimer = std::chrono::high_resolution_clock::now();

  // Timer for calcNumLeaves execution time--setNumLeaves is the actual method that calculates the number of leavs.
  auto startCalcNumLeaves = std::chrono::high_resolution_clock::now();

  // Timer for calcNumFull execution time--setNumFull is the actual method that calculates the number of full nodes.
  auto startCalcNumFull = std::chrono::high_resolution_clock::now();

  // create the binary tree.
  IntBinaryTree tree;

  std::cout << "*********Welcome to my demonstration tree app**********************\n\n";

  // Insert some values.
  tree.insertNode(4);
  tree.insertNode(2);
  tree.insertNode(3);
  tree.insertNode(1);
  tree.insertNode(9);

  // calculate the number of nodes and leaves in tree.

  tree.calcNumNodes();
  auto endCalcNumNodesTimer = std::chrono::high_resolution_clock::now();
  //--------------------------------------------------------------------------------------------------------

  tree.calcNumLeaves();
  auto endCalcNumLeaves = std::chrono::high_resolution_clock::now();
  //-------------------------------------------------------------------------------------------------------

  tree.calcNumFull();
  auto endCalcNumFull = std::chrono::high_resolution_clock::now();
  //---------------------------------------------------------------------------------------------------------

  // time difference for the calcNumNodes timer
  auto timeDiffCalcNumNodes = std::chrono::duration_cast<std::chrono::microseconds>(endCalcNumNodesTimer - startCalcNumNodesTimer);

  // time difference for the calcNumLeaves timer
  auto timeDiffCalcNumLeaves = std::chrono::duration_cast<std::chrono::microseconds>(endCalcNumLeaves - startCalcNumLeaves);

  // time difference for the calcNumFull
  auto timeDiffCalcNumFull = std::chrono::duration_cast<std::chrono::microseconds>(endCalcNumFull - startCalcNumFull);

  // Display the current values in the tree.
  std::cout << "\nHere are the values in the tree: \n";
  tree.displayInOrder();

  std::cout << std::endl;
  std::cout << std::endl;

  // Display the current number of nodes in the tree.
  std::cout << "Here are the number of nodes in the tree: \n";

  int tempNodes = tree.getNumNodes();
  std::cout << tempNodes << std::endl;

  // Execution time for calcNumNodes and setNumNodes methods.
  std::cout << "Execution time:   " << timeDiffCalcNumNodes.count()
            << "  microseconds. " << std::endl;

  // Display the current number of leaves in the tree.
  int tempLeaves = tree.getNumLeaves();

  std::cout << "Here are the number of leaves in the tree: \n";
  std::cout << tempLeaves << std::endl;

  // Execution time for calcNumLeaves and setNumLeaves methods.
  std::cout << "Execution time:   " << timeDiffCalcNumLeaves.count()
            << "  microseconds." << std::endl;

  // Display the current number of full nodes in the tree.
  int tempFullNodes = tree.getNumFull();

  std::cout << "Here are the number of full nodes in the tree: \n";
  std::cout << tempFullNodes << std::endl;

  // Execution time for calcNumFull and setNumFull methods.
  std::cout << "Execution time:   " << timeDiffCalcNumFull.count()
            << "  microseconds." << std::endl;

  //--------------------End of Question 1 implementation.-------------------
}