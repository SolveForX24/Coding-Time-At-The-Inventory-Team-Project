#include <iostream>
#include <string>
#include <vector>

#include "GetData.h"

using namespace std;

vector<vector<string>> exchangeSort(vector<vector<string>> inventory, int index) {
	return inventory;
}

// partitions array & returns middle subscript
int partition(vector<vector<string>>& array, int top, int bottom, int index)
{
	string x = array[top][index];
	int i = top - 1;
	int j = bottom + 1;
	string temp;
	do {
		do {
			j--;
		} while (x > array[j][index]);
		do {
			i++;
		} while (x < array[i][index]);

		if (i < j)
		{
			temp = array[i][index];
			array[i][index] = array[j][index];
			array[j][index] = temp;
		}
	} while (i < j);

	return j; // returns middle subscript 
}

void doQuickSort(vector<vector<string>>&inv, int top, int bottom, int index) {
	int middle;
	if (top < bottom)
	{
		middle = partition(inv, top, bottom, index);

		// sort first section 
		doQuickSort(inv, top, middle, index);
		// sort second section
		doQuickSort(inv, middle + 1, bottom, index);
	}
}

vector<vector<string>> quickSort(vector<vector<string>> inventory, int index, int top, int bottom) {
	doQuickSort(inventory, 0, inventory.size() - 1, index);
	return inventory;
}

void printInventory(vector<vector<string>>& inventory) {
	cout << "\nWhat sorting algorithm would you like to use? " << endl
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
		sortedInventory = quickSort(inventory, index - 1, 0, inventory.size() - 1);
		break;
	}

	cout << endl << "========== INVENTORY ==========" << endl;
	for (int i = 0; i < sortedInventory.size(); i++) {
		cout << endl << "ID: " << sortedInventory[i][0] << endl
			<< "Name: " << sortedInventory[i][1] << endl
			<< "Donar: " << sortedInventory[i][2] << endl
			<< "Base Price: $" << stod(sortedInventory[i][3]) << endl
			<< "Stock: " << sortedInventory[i][4] << endl
			<< "Department: " << sortedInventory[i][5] << endl
			<< "Shelf Location: " << sortedInventory[i][6] << endl;
		if (sortedInventory[i][7] == "N/A") {
			cout << "Sale: N/A" << endl;
		}
		else {
			cout << "Sale: " << sortedInventory[i][7] << " % " << endl;
		}
	}
	cout << endl << "===============================" << endl;
}