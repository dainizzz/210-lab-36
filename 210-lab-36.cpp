// COMSC-210 | Lab 36 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"

using namespace std;

/* Milestones (Remove when done)
 * 4. Your code's menu is functional.
*/

// testBinaryTree() tests the StringBinaryTree class by creating a new object of that class and
// calling some of its methods.
// arguments: none
// returns: nothing
void testBinaryTree();

int main() {
	StringBinaryTree tree;
	ifstream infile;
	string temp;

	infile.open("codes.txt");
	if (infile.good()) {
		while (infile >> temp) {
			tree.insertNode(temp);
		}
	} else
		cout << "Error opening file." << endl;

	tree.displayInOrder();

    return 0;
}

void testBinaryTree() {
	StringBinaryTree tree;

	cout << "Inserting nodes into tree..." << endl;
	tree.insertNode("dragonfruit");
	tree.insertNode("banana");
	tree.insertNode("elderberry");
	tree.insertNode("cherry");
	tree.insertNode("apple");

	cout << "Displaying the values in the tree..." << endl;
	tree.displayInOrder();
	cout << endl;

	cout << "Deleting the value apple..." << endl;
	tree.remove("apple");
	cout << endl;

	cout << "Displaying the updated tree..." << endl;
	tree.displayInOrder();
	cout << endl;
}