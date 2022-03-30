#include <fstream>
#include <string>
#include <vector>

#include "FileData.h"

using namespace std;

void readFromFile(vector<vector<string>>& inventory) {
    ifstream fin("data.txt");

    if (fin.good()) {
        int i = 0;
        vector<string> currentItem;
        string line;

        while (fin.peek() != EOF) {
            getline(fin, line);

            if (line == "") {
                i = 0;
                inventory.push_back(currentItem);
                currentItem = vector<string>();
                continue;
            }

            currentItem.push_back(line);
        }
    }

    fin.close();
}

void writeToFile(vector<vector<string>>& inventory) {
    ofstream fout("data.txt");

    for (int i = 0; i < inventory.size(); i++) {
        for (int j = 0; j < inventory[i].size(); j++) {
            fout << inventory[i][j] << endl;
        }
        fout << endl;
    }

    fout.close();
}