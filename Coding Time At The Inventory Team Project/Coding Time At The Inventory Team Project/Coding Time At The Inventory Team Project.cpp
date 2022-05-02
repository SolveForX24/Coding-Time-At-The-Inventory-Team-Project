/*
    Names: Xander Russell, Matthew Weir
	Lab: Coding Time At The Inventory
	Date: 3/24/22
	Extra: The inventory is saved between runs.
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "GetData.h"
#include "FileData.h"
#include "InventoryManagement.h"
#include "SortAndPrint.h"

using namespace std;

int main() {
    bool running = true;
    vector<vector<string>> inventory;
    // Read data from inventory file
    readFromFile(inventory);

    // Set the double output precision to 2 decimal places
    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << "Welcome to Goodwill Inventory Systems!\n\n";

    while (running) {
        // Prompt the user for what they want to do
        cout << "What would you like to do?" << endl
            << "1) Add item to inventory" << endl
            << "2) Remove item from inventory" << endl
            << "3) Print items in inventory" << endl
            << "4) End program" << endl;

        int action = promptInt("Enter choice: ", 1, 4);

        // Run an action depending on what the user chose.
        switch (action) {
            case 1:
                createItem(inventory);
                break;
            case 2:
                deleteItem(inventory);
                break;
            case 3:
                printInventory(inventory);
                break;
            case 4:
                cout << "Thank you for using Goodwill Inventory!";
                running = false;
                break;
            default:
                break;
        }
        
        cout << endl;

        writeToFile(inventory);
    }
}
