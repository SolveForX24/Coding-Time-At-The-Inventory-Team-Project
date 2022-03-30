#include <iostream>
#include <string>
#include <vector>

#include "GetData.h"
#include "FileData.h"
#include "solveFunctions.h";

using namespace std;

int main()
{
    bool running = true;
    vector<vector<string>> inventory;
    readFromFile(inventory);

    while (running) {
        cout << "What would you like to do?" << endl
            << "1) Add item to inventory" << endl
            << "2) Remove item from inventory" << endl
            << "3) Print items in inventory" << endl;

        int action = promptInt("Enter choice: ", 1, 3);

        switch (action) {
        case 1:
            createItem(inventory);
            break;
        case 2:
            // remove item
            break;
        case 3:
            // print inventory
            break;
        }
        
        cout << endl;

        writeToFile(inventory);
    }
}

/*
    Name
    ID
    Donar
    
    Price
    Stock
    Department
    Shelf Location
    Sale
*/

