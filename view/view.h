#include <iostream>
using namespace std;
class Display
{
public:
    int inputChoice();
    void displayTopBatsmanData(string, double,string);
};

int Display::inputChoice() {
    int choice;
    cout << "Enter Your Choice: ";
    cin >> choice ;
    cout << endl << endl;
    return choice;
}

void Display::displayTopBatsmanData(string cricketerName, double battingAvg, string dataName) {
    cout << "PlayerName : " << cricketerName;
    cout << "\nTop Batting" << dataName <<   ": " << battingAvg << endl;
}