#include <iostream>
using namespace std;
class Display
{
public:

    void welcomeNote() {
        cout << "\n|===========================================================|"<< endl;
        cout << "|                    IPL ANALYSER SYSTEM                    |" << endl;
    }

    void options() {
        cout << "|===========================================================|"<<endl;
        cout << "|                                                           |";
        cout << "\e[1m" << "\n|   1. Find Top Batting Average                             |" << endl;
        cout << "|                                                           |";
        cout << "\n|   2. Top Strike Rate Player                               |" << endl; 
        cout << "|                                                           |";
        cout << "\n|   3. Top SixFour Hitman                                   |" << endl;
        cout << "|                                                           |";
        cout << "\n|   4. Top StrikeRate WRT SixFour                           |" << endl;  
        cout << "|                                                           |";
        cout << "\n|   5. Top Best Avg And Strike Rate                         |" << endl;
        cout << "|                                                           |";
        cout << "\n|   6. Max Run / Best Avg                                   |" << endl; 
        cout << "|                                                           |";
        cout << "\n|   7. Top Bowling average                                  |" << endl;
        cout << "|                                                           |";
        cout << "\n|   8. Bowling StrikeRate                                   |" << endl;  
        cout << "|                                                           |";
        cout << "\n|   9. Bowler Economy Rate                                  |" << endl;
        cout << "|                                                           |";
        cout << "\n|   10. Bowler Best SR with wkts                            |" << endl;
        cout << "|                                                           |";
        cout << "\n|   11. Bowler Best SR with Avg                             |" << endl;
        cout << "|                                                           |";
        cout << "\n|   12. Bowler Max Wkts with Avg                            |" << endl;
        cout << "|                                                           |";
        cout << "\n|   13. Best All-Rounder By Average                         |" << endl;
        cout << "|                                                           |";
        cout << "\n|   14. AllRounder By Wkts and Runs                         |" << endl;
        cout << "|                                                           |";
        cout << "\n|   15. Best Player Hundred and Avg                         |" << endl;
        cout << "|                                                           |";
        cout << "\n|   16. Best Avg Without 100 & 50                           |" << endl;
        cout << "|                                                           |";
        cout << "\n|   17.  Exit                                               |" << endl;
        cout << "|                                                           |";
        cout << "\n=============================================================" << "\e[0m";
    }

    void validOptionMsg(){
        cout << "\n\nEnter Valid Choice" << endl;
    }

    void displayOption() {
        cout << "\n\nEnter Your Choice: ";
    }

    void displayData(string cricketerName, double battingAvg, string dataName) {
        cout << "\n=======================  BEST PLAYER  ======================" << endl;
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   " :: " << battingAvg << endl << endl;
    }

    void displayData(string cricketerName, double dataPointOne, double dataPointTwo, string dataName) {
        cout << "\n=======================  BEST PLAYER  ======================" << endl;
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   " :: " << dataPointOne << " / " << dataPointTwo << endl << endl;
    }
};
