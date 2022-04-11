#include <iostream>
#include "CSVReader.h"
#ifdef _WIN32
#include <Windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    /* Example.csv
        Index, Message, ExpireDay, RewardIndex, RewardCount
        1, contents, 14, 100000, 10
        2, "Comma,Seperated,Text", 7, 100001, 30
        3, """Event"",""contents"",""123"",""!@#""    ", 365, 100002, 5
    */

    CSVReader reader;
    reader.ReadFile("test.csv");

    auto& row = reader.GetRow(1);
    std::cout << row[1] << std::endl;
    

    // for(int i = 0; i<reader.GetRowCount(); i++)
    // {
    //     auto& row = reader.GetRow(i);
    //     for(int j=0; j<row.size(); j++)
    //     {
    //         std::cout << row[j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for (auto& rows : reader)
    // {
    //     for (auto& row : rows)
    //     {
    //         std::cout << row << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << reader.GetCell(1, 1) << std::endl;
}