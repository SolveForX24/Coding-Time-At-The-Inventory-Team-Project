#pragma once

#include <vector>
#include <string>

void createItem(std::vector<std::vector<std::string>>&);
void deleteItem(std::vector<std::vector<std::string>>&);
bool customFind(std::vector<std::vector<std::string>>, std::string, int&);
bool customDelete(std::vector<std::vector<std::string>>&, int);
int indexFind(std::vector<std::vector<std::string>>);
bool idCheck(std::vector<std::vector<std::string>>, std::string);