#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
namespace csvlib
{
    vector<unordered_map<string, string>> csvToObj(string file_Path)
    {
        fstream fin; 
        fin.open(file_Path, ios::in);
        
        vector<unordered_map<string, string>> csv_data; 
        string line, word;
        vector<string> header; 
        int row_iterator = 0;
        
        while (getline(fin, line)) 
        {   
            stringstream s(line);
            unordered_map<string, string> csv_column_data;

            if(row_iterator < 1)
            {
                while (getline(s, word, ',')) 
                {
                    header.push_back(word);
                }
            } 

            if(row_iterator > 0)
            {
                int column_iterator = 0;
                
                while (getline(s, word, ',')) 
                {
                    csv_column_data[header.at(column_iterator)] = word;
                    column_iterator++;
                }

                csv_data.push_back(csv_column_data);
            }

            row_iterator++;
        }

        return csv_data;
    }
}