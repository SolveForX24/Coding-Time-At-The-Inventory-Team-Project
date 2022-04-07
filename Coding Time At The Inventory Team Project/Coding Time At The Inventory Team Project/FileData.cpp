#include <fstream>
#include <string>
#include <vector>

#include "FileData.h"

using namespace std;

void readFromFile(vector<vector<string>>& inventory) {
    ifstream in("data.txt");

    // If file exists
    if (in.good()) {
        vector<string> currentItem;
        string line;

        // Loop through each line of the file
        while (in.peek() != EOF) {
            getline(in, line);

            // If the line is empty, push the item to the inventory and start reading properties into a new item
            if (line.empty()) {
                inventory.push_back(currentItem);
                currentItem = vector<string>();
                continue;
            }

            // Read this property into the item
            currentItem.push_back(line);
        }
    }

    in.close();
}

void writeToFile(vector<vector<string>>& inventory) {
    ofstream out("data.txt");

    // Loop through each property of each item, and save it in a file
    for (vector<string>& item : inventory) {
        for (string& property : item) {
            out << property << endl;
        }
        out << endl;
    }

    out.close();
}