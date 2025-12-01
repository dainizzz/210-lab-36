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

// menu() displays the menu options for adding, deleting, searching, and modifying records, validates the user's choice,
// and returns the user's choice as an int.
// arguments: none
// returns: an int value representing the user's menu choice
int menu();

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

int menu() {
	int choice;

	cout << "Make a selection:" << endl;
	cout << "1. Add a record" << endl;
	cout << "2. Delete a record" << endl;
	cout << "3. Search for a record" << endl;
	cout << "4. Modify a record" << endl;
	cout << "5. Display all records" << endl;
	cout << "6. Exit" << endl;
	while (!(cin >> choice)) {
		cout << "Invalid input. Please enter a number." << endl;
	}

	return choice;
}
