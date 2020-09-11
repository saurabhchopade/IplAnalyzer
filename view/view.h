#include <iostream>
using namespace std;
class Display
{
public:
    int inputChoice();
    void displayTopBatsmanByAverage(string cricketer_name, double batting_avg);
};

int Display::inputChoice() {
    int choice;
    cout << "Enter Your Choice: ";
    cin >> choice ;
    cout << endl << endl;
    return choice;
}

void Display::displayTopBatsmanByAverage(string cricketer_name, double batting_avg) {
    cout << "PlayerName : " << cricketer_name << "\nTop Batting Average : "
            << batting_avg << endl;
}