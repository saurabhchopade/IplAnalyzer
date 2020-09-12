#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
namespace csvlib
{
    vector<unordered_map<string, string>> csvToObj(string filePath) {
        fstream fin; 
        fin.open(filePath, ios::in);
        
        vector<unordered_map<string, string>> csvData; 
        string line, word;
        vector<string> header; 
        int row_iterator = 0;
        
        while (getline(fin, line)) {   
            stringstream streamOfString(line);
            unordered_map<string, string> coulumnDetails;

            if(row_iterator < 1) {
                while (getline(streamOfString, word, ',')) {
                    header.push_back(word);
                }
            } 

            if(row_iterator > 0) {
                int column_iterator = 0;
                
                while (getline(streamOfString, word, ',')) {
                    coulumnDetails[header.at(column_iterator)] = word;
                    column_iterator++;
                }

                csvData.push_back(coulumnDetails);
            }

            row_iterator++;
        }

        return csvData;
    }
}