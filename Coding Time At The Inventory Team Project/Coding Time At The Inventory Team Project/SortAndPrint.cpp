#include <iostream>
#include <string>
#include <vector>

#include "GetData.h"

using namespace std;

vector<vector<string>> exchangeSort(vector<vector<string>> inventory, int index) {
	return inventory;
}

vector<vector<string>> quickSort(vector<vector<string>> inventory, int index) {
	return inventory;
}


void printInventory(vector<vector<string>>& inventory) {
	cout << "What sorting algorithm would you like to use? " << endl
		<< "1) Exchange Sort" << endl
		<< "2) Quick Sort" << endl;
	int algorithm = promptInt("Enter your choice (1-2): ", 1, 2);

	cout << endl << "What do you want to sort by? " << endl
		<< "1) ID" << endl
		<< "2) Name" << endl
		<< "3) Donar" << endl
		<< "4) Price" << endl;
	int index = promptInt("Enter your choice (1-4): ", 1, 4);

	vector<vector<string>> sortedInventory;
	switch (algorithm) {
	case 1:
		sortedInventory = exchangeSort(inventory, index - 1);
		break;
	case 2:
		sortedInventory = quickSort(inventory, index - 1);
		break;
	}

	cout << endl << "========== INVENTORY ==========" << endl;
	for (int i = 0; i < sortedInventory.size(); i++) {
		cout << endl << "ID: " << sortedInventory[i][0] << endl
			<< "Name: " << sortedInventory[i][1] << endl
			<< "Donar: " << sortedInventory[i][2] << endl
			<< "Base Price: $" << sortedInventory[i][3] << endl
			<< "Stock: " << sortedInventory[i][4] << endl
			<< "Department: " << sortedInventory[i][5] << endl
			<< "Shelf Location: " << sortedInventory[i][6] << endl
			<< "Sale: " << sortedInventory[i][7] << "%" << endl;
	}
	cout << endl << "===============================" << endl;
}