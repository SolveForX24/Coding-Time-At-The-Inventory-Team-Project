#pragma once

#include <string>
#include <vector>

std::vector<std::vector<std::string>> exchangeSort(std::vector<std::vector<std::string>>);
std::vector<std::vector<std::string>> quickSort(std::vector<std::vector<std::string>>);
void doQuickSort(std::vector<std::vector<std::string>>&, int, int, int);
int partition(std::vector<int>&, int, int);
void printInventory(std::vector<std::vector<std::string>>&);