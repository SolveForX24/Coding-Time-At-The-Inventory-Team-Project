#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <random>

#include "GetData.h"

#include "InventoryManagement.h"

using namespace std;

void createItem(vector<vector<string>>& inven) {
	
	// Setting random seed and cout precision.
	srand(time(NULL));

	/*
		Name
		ID
		DONAR

		Price
		Stock
		Department
		Shelf
		Sale
	*/

	// Variables
	vector<string> item;
	
	string prompt;
	string dummy;

	string posString = "A";

	int intPrompt;

	double doubPrompt;

	// Get name
	cout << "Please enter the item name: ";
	getline(cin, prompt);
	item.push_back(prompt);
	//getline(cin, dummy);

	// Index is a random number,

	do {
		prompt = to_string(rand());
	} while (idCheck(inven, prompt));

	item.push_back(prompt);

	// Get if someone donated the item. If yes, get name. Else, put N/A.
	do {
		cout << "Did someone donate this " + item[0] + "? (y/n) ";
		getline(cin, prompt);
		//getline(cin, dummy);
	} while (prompt != "y" && prompt != "Y" && prompt != "n" && prompt != "N");

	if (prompt == "Y" || prompt == "y") {
		cout << "Please enter the name of the person who donated this: ";
		getline(cin, prompt);
		//getline(cin, dummy);
		item.push_back(prompt);
	}
	else {
		item.push_back("N/A");
	}

	// Get price and stock.
	do {
		cout << "Please enter the price of the item: ";
	} while (!getValidDouble(doubPrompt) || doubPrompt < 0);

	item.push_back(to_string(doubPrompt));

	do {
		cout << "Please enter how many of the item we have received: ";
	} while (!getValidInt(intPrompt) || intPrompt < 1);

	item.push_back(to_string(intPrompt));

	// Get department of item.
	cout << "Department 1: Clothes\n"
		<< "Department 2: Electronics\n"
		<< "Department 3: Food\n"
		<< "Department 4: Health Care\n"
		<< "Department 5: Skincare\n";

	do {
		cout << "Please enter the department the item belongs to (1-5): ";
	} while (!getValidInt(intPrompt) || intPrompt < 1 || intPrompt > 5);

	item.push_back(to_string(intPrompt));

	//return item;
	
	// Get shelf position.
	do {
		cout << "Please enter the aisle this item belongs on: ";
	} while (!getValidInt(intPrompt) || intPrompt < 1);
	posString += to_string(intPrompt);
	posString += "-B";
	do {
		cout << "Please enter the bay this item belongs on: ";
	} while (!getValidInt(intPrompt) || intPrompt < 1);
	posString += to_string(intPrompt);
	posString += "-S";
	do {
		cout << "Please enter the shelf this item belongs on: ";
	} while (!getValidInt(intPrompt) || intPrompt < 1);
	posString += to_string(intPrompt);
	posString += "-P";
	do {
		cout << "Please enter the position this item belongs on: ";
	} while (!getValidInt(intPrompt) || intPrompt < 1);
	posString += to_string(intPrompt);

	item.push_back(posString);

	// Get sale.
	do {
		cout << "Is there a sale on this " + item[0] + "? (y/n) ";
		getline(cin, prompt);
		//getline(cin, dummy);
	} while (prompt != "y" && prompt != "Y" && prompt != "n" && prompt != "N");

	if (prompt == "y" || prompt == "Y") {
		do {
			cout << "Please enter the percent sale: %";
		} while (!getValidDouble(doubPrompt) || doubPrompt <= 0 || doubPrompt > 100);
		item.push_back(to_string(doubPrompt));
	}
	else {
		item.push_back("N/A");
	}

	// Push to inventory
	inven.push_back(item);
}

void deleteItem(vector<vector<string>>& inven) {

	// Variables
	string strPrompt;
	string dummy;

	//Get way to remove item
	int intPrompt = promptInt("Would you like to delete item based on name (1) or by ID (2)? ", 1, 2);

	switch (intPrompt) {
	int index;
	case 1:
		// If deleting by name, get name (making sure it's in the vector) then erase based on index of that item.
		do {
			cout << "Please enter the name of the item: ";
			getline(cin, strPrompt);
			//getline(cin, dummy);
		} while (customFind(inven, strPrompt, index));
		inven.erase(inven.begin() + index);
		cout << "Item deleted!\n";
		break;
	case 2:
		// Get index, then the ID of the item the user wants to use. Make sure t.
		index = indexFind(inven);
		do {
			intPrompt = promptInt("Please enter the ID of the item: ", 0, 2147483647);
		} while (intPrompt > index || intPrompt < 0);
		customDelete(inven, intPrompt);
	}

}

// My function to find the item in the vector.
bool customFind(vector<vector<string>> vect, string key, int& index) {

	// Loop through the vector, checking each value in each row and the first column.
	for (int i = 0; i <= vect.size() - 1; i++) {
		// If key found, print as such, update the pass-by reference variables and leave the function.
		if (vect[i][0] == key) {
			cout << "\nItem found!\n";
			index = i;
			return false;
		}
	}
	// If key not found, print as such, and leave.
	cout << "Item not found.\n\n";
	return true;
}

// My function to delete a item in the vector.
bool customDelete(vector<vector<string>>& vect, int key) {
	// Loop through the vector, checking each value in each row and the first column.
	for (int i = 0; i <= vect.size() - 1; i++) {
		// If key found, print as such, delete the vector there and leave the function.
		if (stoi(vect[i][1]) == key) {
			cout << "\nID found!\n";
			vect.erase(vect.begin() + i);
			cout << "Item deleted!\n";
			return false;
		}
	}
	// If key not found, print as such, and leave.
	cout << "ID not found.\n\n";
	return true;
}

// Finds the highest index possible.
int indexFind(vector<vector<string>> vect) {
	// Variables.
	int indexProspect = stoi(vect[0][1]);
	int check;

	// Loop through vector, checking IDs.
	for (int i = 1; i < vect.size(); i++) {
		check = stoi(vect[i][1]);
		if (check > indexProspect) {
			indexProspect = check;
		}
	}
	//cout << "Index used: " << indexProspect << ".\n";
	return indexProspect;
}

// Finds the highest index possible.
bool idCheck(vector<vector<string>> vect, string prompt) {

	// Loop through vector, checking IDs against the prompt.
	for (int i = 1; i < vect.size(); i++) {
		if (vect[i][1] == prompt) {
			return true;
		}
	}
	return false;
}