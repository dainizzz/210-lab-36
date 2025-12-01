// COMSC-210 | Lab 36 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
#include <limits>
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

// addRecord() prompts the user for a value, creates a record, and adds a new record to the StringBinaryTree object
// arguments: the StringBinaryTree object a record is being added to
// returns: nothing
void addRecord(StringBinaryTree&);

// deleteRecord() prompts the user for a value, checks if that value is in the StringBinaryTree object, and removes the
// record with that value from the StringBinaryTree object if it exists.
// arguments: the StringBinaryTree object a record is being removed from
// returns: nothing
void deleteRecord(StringBinaryTree&);

// searchForRecord() prompts the user for a value, checks if that value is in the StringBinaryTree object, and displays
// a message letting the user know whether the value was found.
// arguments: the StringBinaryTree object being searched
// returns: nothing
void searchForRecord(StringBinaryTree&);

// modifyRecord() prompts the user for a value, checks if that value is in the StringBinaryTree object, prompts the user
// for a new value for the record, and updates the value of the record.
// arguments: the StringBinaryTree object where a record is being modified
// returns: nothing
void modifyRecord(StringBinaryTree&);

int main() {
	StringBinaryTree tree;
	ifstream infile;
	string temp;
	int choice;
	bool displayMenu = true;

	// cout << "Loading initial record data..." << endl;
	//
	// infile.open("codes.txt");
	// if (infile.good()) {
	// 	while (infile >> temp) {
	// 		tree.insertNode(temp);
	// 	}
	// } else
	// 	cout << "Error opening file." << endl;
	//
	// cout << "Displaying initial record data..." << endl;
	// tree.displayInOrder();
	// cout << endl << endl;

	while (displayMenu) {
		choice = menu();
		switch (choice) {
			case 1:
				addRecord(tree);
				break;
			case 2:
				deleteRecord(tree);
				break;
			case 3:
				searchForRecord(tree);
				break;
			case 4:
				modifyRecord(tree);
				break;
			case 5:
				tree.displayInOrder();
				break;
			case 6:
				displayMenu = false;
				break;
			// Default case will not occur since the menu() function validates user input
			default:
				break;
		}
	}

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
	while (!(cin >> choice) || choice < 1 || choice > 6) {
		cout << "Invalid input. Please enter a number between 1 and 6." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return choice;
}

void addRecord(StringBinaryTree &tree) {
	string input;
	cout << "Enter the value of the new record:" << endl;
	cin >> input;
	tree.insertNode(input);
	cout << "New record successfully added!" << endl << endl;
}

void deleteRecord(StringBinaryTree &tree) {
	string input;
	cout << "Enter the value of the record to delete:" << endl;
	cin >> input;
	bool found = tree.searchNode(input);
	if (found) {
		tree.remove(input);
		cout << "Deleted the record with the value \"" << input << "\"." << endl << endl;
	} else
		cout << "Record not found." << endl << endl;
}

void searchForRecord(StringBinaryTree &tree) {
	string input;
	cout << "Enter the value of the record to search for:" << endl;
	cin >> input;
	bool found = tree.searchNode(input);
	cout << "The record with the value \"" << input;
	if (found)
		cout << "\" was found." << endl << endl;
	else
		cout << "\" was not found." << endl << endl;
}

void modifyRecord(StringBinaryTree &tree) {
	string input;
	cout << "Enter the value of the record to modify:" << endl;
	cin >> input;
	bool found = tree.searchNode(input);
	if (found) {
		// Rather than modifying the value directly, which could cause the BST to no longer be in order,
		// the record that should be modified is deleted, and a new record is added with the value the user provides.
		// This will ensure that the order of the BST is maintained.
		tree.remove(input);
		cout << "Enter the new value of the record:" << endl;
		cin >> input;
		tree.insertNode(input);
		cout << "The record was successfully modified!" << endl << endl;
	} else
		cout << "Record not found." << endl << endl;
}
