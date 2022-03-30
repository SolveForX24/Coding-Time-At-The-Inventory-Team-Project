#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

#include "GetData.h"

#include "solveFunctions.h"
using namespace std;

void createItem(vector<vector<string>> inven) {
	
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

	vector<string> item;
	
	string prompt;
	string dummy;

	int intPrompt;

	double doubPrompt;

	cout << "Please enter the item name: ";
	getline(cin, prompt);
	item.push_back(prompt);
	getline(cin, dummy);

	prompt = to_string(inven.size());

	item.push_back(prompt);

	do {
		cout << "Did someone donate this " + item[0] + "? (y/n) ";
		getline(cin, prompt);
		getline(cin, dummy);
	} while (prompt != "y" && prompt != "Y" && prompt != "n" && prompt != "N");

	if (prompt == "Y" || prompt == "y") {
		cout << "Please enter the name of the person who donated this: ";
		getline(cin, prompt);
		getline(cin, dummy);
		item.push_back(prompt);
	}
	else {
		item.push_back("N/A");
	}

	do {
		cout << "Please enter the price of the item: ";
	} while (!getValidDouble(doubPrompt) && doubPrompt < 0);

	item.push_back(to_string(doubPrompt));

	do {
		cout << "Please enter how many of the item we have received: ";
	} while (!getValidInt(intPrompt) && intPrompt < 1);

	item.push_back(to_string(intPrompt));

	cout << "Department 1: Clothes\n"
		<< "Department 2: Electronics\n"
		<< "Department 3: Food\n"
		<< "Department 4: Health Care\n"
		<< "Department 5: Skincare\n";

	do {
		cout << "Please enter the department the item belongs to (1-5): ";
	} while (!getValidInt(intPrompt) && intPrompt < 1 && intPrompt > 5);

	item.push_back(to_string(intPrompt));

	//return item;
}