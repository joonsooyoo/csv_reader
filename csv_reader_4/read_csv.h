#ifndef READ_CSV_H
#define READ_CSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> parse_row(std::ifstream& ifs, std::string filename);
vector<vector<double>> parse_column(std::ifstream& ifs, std::string filename);

#endif