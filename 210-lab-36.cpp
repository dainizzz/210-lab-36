// COMSC-210 | Lab 36 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

/* Milestones (Remove when done)
 * 2. Code modification from int to strings is complete, and your code exercises this for testing.
 * 3. Your code successfully creates a BST from the records and outputs it using the method of your choosing.
 * 4. Your code's menu is functional.
*/

int main() {
    IntBinaryTree tree;

	cout << "Inserting nodes into tree..." << endl;
	tree.insertNode("apple");
	tree.insertNode("banana");
	tree.insertNode("cherry");
	tree.insertNode("dragonfruit");

	cout << "Displaying the values in the tree..." << endl;
	tree.displayInOrder();
	tree.displayPostOrder();
	tree.displayPreOrder();

    return 0;
}