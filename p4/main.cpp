/*	
 *	Developed by Faisal, Hafiz, and Jesstern
 *	Bachelor of Computer Science, University of Adelaide
 *	All Rights Reserved. Copyright (C) Jesstern Rays
 *	This work is licensed under CC BY-SA 4.0
 */

#include "Search.h"
#include "Sort.h"
#include "lib.h"

/*********************************************/
/*               Main Function               */
/*********************************************/

void result(int, int);
void goodbye();

int main()
{
	srand(time(0)); // seed rand() with current time
	vector<int> table;

	// prompt user for table size
	cout << "What is the size of the table? ";
	unsigned int size;
	cin >> size;
	// check if user's input is valid
	if (cin.fail()) {
		cout << "Invalid entry!";
	} else {
		// resize the vector to users requirements
		table.resize(size);
		// assign random integers to the vector
		for (int i = 0; i < table.size(); i++) {
			// table[i] = i;			 // assign incremental values
			table[i] = rand() % 100 + 1; // assign random values
		}
	}

	// display table elements
	for (int i = 0; i < table.size(); i++) {
		cout << table[i];
		if (i < (table.size() - 1)) 
			cout << ", ";
	}
	cout << endl;

	// generate a search term
	cout << "Search term: ";
	int search = table[ rand() % table.size() + 0 ];
	cout << search << endl;
	
	// search unsorted table
	result(linearSearch(table, search), search); // linear search
	result(binarySearch(table, search), search); // binary search

	// sort table

	// search sorted table

	// smart swap
	/*
	int a = 32;
	int b = 21;
	cout << a << " and " << b << endl;
	a = a + b;
	b = a - b; // b = (a + b) - b
	a = a - b; // a = (a + b) - a
	cout << a << " and " << b << endl;
	*/

	// say goodbye
	goodbye();	
	return 0;
} // end main function 

void result(int index, int search) {
	index += 1; // increment index by 1

	string pos = "th";			// Nth position
	if (index == 1) pos = "st"; // 1st position
	if (index == 2) pos = "nd"; // 2nd position
	if (index == 3) pos = "rd"; // 3rd position

	if (index != 0) {
		cout << "We found it! " << search << " is the ";
		cout << index << pos << " element of the table." << endl;
	} else {
		cout << "Sorry. No match found." << endl;
	}
}

void goodbye() {
	cout << "Goodbye!" << endl;
	cout << "Developed by Faisal, Hafiz, and Jesstern." << endl;
}