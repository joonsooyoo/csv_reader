#include <iostream>
#include <fstream>
#include <vector>
#include "read_csv.h"


int main() {

    std::ifstream ifs;
    std::string filename = "some_file.csv";
    // std::vector<vector<double>> res = parse_row(ifs, filename);
    std::vector<vector<double>> res = parse_column(ifs, filename);

    for (size_t i = 0; i < 3; i++) {
        cout << res.at(0).at(i) << endl;
    }

}