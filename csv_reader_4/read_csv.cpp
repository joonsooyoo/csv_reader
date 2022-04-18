#include "read_csv.h"

using namespace std;

vector<vector<double>> parse_row(std::ifstream& ifs, std::string filename) {
    
    ifs.open("some_file.csv");

    string line;

    string delimiter = ",";
    string end_of_line = "\n";

    string token;
    double data;

    size_t pos_start = 0, pos_end;
    vector<double> row;
    vector<vector<double>> res;

    getline(ifs, line); // skips the first line
    
    
    while(getline(ifs, line)){
        
        // first token : find ","
        // getline(ifs, line);
        pos_end = line.find(delimiter, pos_start);
        token = line.substr(pos_start, pos_end);
        data = atof(token.c_str());
        row.push_back(data);

        // second token : find " \n"
        pos_start += pos_end + 1;
        pos_end = line.find(end_of_line, pos_start);
        token = line.substr(pos_start, pos_end);
        data = atof(token.c_str());
        row.push_back(data);

        // put row into res vector
        res.push_back(row);
        // reflush row vector
        row.clear();
        pos_start = 0;

    }

    return res;

}

vector<vector<double>> parse_column(std::ifstream& ifs, std::string filename) {
    
    /* 
        read by columns
    */

    ifs.open(filename);

    string line;
    double data;

    vector<vector<double>> res;
    /* number of columns you need */
    vector<double> col1;
    vector<double> col2;

    getline(ifs, line); // skips first line

    while(ifs.good()) { // read until the end of file

        /** reads first data **/
        getline(ifs, line, ',');
        data = atof(line.c_str()); // atof changes c_string to double
        col1.push_back(data);

        /** reads second data **/
        getline(ifs, line, '\n');
        data = atof(line.c_str());
        col2.push_back(data);

    }

    /* deletes last element */
    col1.pop_back();
    col2.pop_back();

    res.push_back(col1);
    res.push_back(col2);

    return res;

}