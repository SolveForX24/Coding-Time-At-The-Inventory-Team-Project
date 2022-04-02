#include <iostream>
#include <string>
#include <vector>

#include "GetData.h"

using namespace std;

bool compare(const string& item1, const string& item2, int index) {
    switch (index) {
        case 1:
            return stoi(item1) > stoi(item2);
        case 3:
            return stod(item1) > stod(item2);
        default:
            return item1 > item2;
    }
}

vector<vector<string>> exchangeSort(vector<vector<string>> inventory, int index) {
    vector<string> temp;
    int inventoryLength = (int) inventory.size();

    for (int i = 0; i < inventoryLength - 1; i++) {
        for(int j = i + 1; j < inventoryLength; j++) {
            if (compare(inventory[i][index], inventory[j][index], index)) {
                temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }

	return inventory;
}

vector<vector<string>> shellSort(vector<vector<string>> inventory, int index) {
    int flag = 1, inventoryLength = (int) inventory.size(), d = inventoryLength;
    vector<string> temp;

    while(flag || (d > 1)) {
        flag = 0; // reset flag to 0 to check for future swaps
        d = (d + 1) / 2;
        for (int i = 0; i < inventoryLength - d; i++) {
            if (compare(inventory[i][index], inventory[i + d][index], index)) {
                temp = inventory[i + d]; // swap positions i+d and i
                inventory[i + d] = inventory[i];
                inventory[i] = temp;
                flag = 1; // tells swap has occurred
            }
        }
    }

	return inventory;
}

void printInventory(vector<vector<string>>& inventory) {
	cout << endl << "What sorting algorithm would you like to use? " << endl
		<< "1) Exchange Sort" << endl
		<< "2) Shell Sort" << endl;
	int algorithm = promptInt("Enter your choice (1-2): ", 1, 2);

	cout << endl << "What do you want to sort by? " << endl
		<< "1) Name" << endl
		<< "2) ID" << endl
		<< "3) Donor" << endl
		<< "4) Price" << endl;
	int index = promptInt("Enter your choice (1-4): ", 1, 4);

	vector<vector<string>> sortedInventory;
	switch (algorithm) {
	    case 1:
		    sortedInventory = exchangeSort(inventory, index - 1);
		    break;
	    case 2:
		    sortedInventory = shellSort(inventory, index - 1);
		    break;
        default:
            sortedInventory = inventory;
            break;
	}

	cout << endl << "========== INVENTORY ==========" << endl;
	for (vector<string>& item : sortedInventory) {
		cout << endl << "Name: " << item[0] << endl
			<< "ID: " << item[1] << endl
			<< "Donor: " << item[2] << endl
			<< "Base Price: $" << stod(item[3]) << endl
			<< "Stock: " << item[4] << endl
			<< "Department: " << item[5] << endl
			<< "Shelf Location: " << item[6] << endl;
		if (item[7] == "N/A") {
			cout << "Sale: N/A" << endl;
		}
		else {
			cout << "Sale: " << item[7] << " % " << endl;
		}
	}
	cout << endl << "===============================" << endl;
}