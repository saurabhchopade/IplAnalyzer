#include <iostream>
using namespace std;
class Display
{
public:

    int inputChoice() {
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice ;
        cout << endl << endl;
        return choice;
    }

    void displayTopBatsmanData(string cricketerName, double battingAvg, string dataName) {
        cout << "PlayerName : " << cricketerName;
        cout << "\n" << dataName <<   ": " << battingAvg << endl;
    }

    void displayPlayerData(string cricketerName, double dataPointOne
                    ,double dataPointTwo, string dataName) {
        cout << "PlayerName : " << cricketerName;
        cout << "\n" << dataName <<   ": " << dataPointOne << 
        " / " << dataPointTwo << endl;
    }
};
