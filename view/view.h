#include <iostream>
using namespace std;
class Display
{
public:

    void welcomeNote() {
        cout << "\n\n========================================================"<< endl;
        cout << "==================  IPL ANALYSER SYSTEM  ===============" << endl;
    }

    void options() {
        cout << "========================================================"<<endl;
        cout <<"\e[1m" << "\n\n1. Find Top Batting Average      :";
        cout << "\n\n2. Top Strike Rate Player        :"; 
        cout << "\n\n3. Top SixFour Hitman            :";
        cout << "\n\n4. Top StrikeRate WRT SixFour    :";  
        cout << "\n\n5. Top Best Avg And Strike Rate  :";
        cout << "\n\n6. Max Run / Best Avg            :"; 
        cout << "\n\n7. Top Bowling average           :";
        cout << "\n\n8. Bowling StrikeRate            :";  
        cout << "\n\n9. Bowler Economy Rate           :";
        cout << "\n\n10. Bowler Best SR with wkts     :";
        cout << "\n\n11. Bowler Best SR with Avg      :";
        cout << "\n\n12. Bowler Max Wkts with Avg     :";
        cout << "\n\n13. Best All-Rounder By Average  :";
        cout << "\n\n14. AllRounder By Wkts By Runs   :";
        cout <<"\n\n15.  Exit                        :";
        cout <<"\n\n=========================================================" << "\e[0m";
    }

    void validOptionMsg(){
        cout << "\n\nEnter Valid Choice" << endl;

    }
    int inputChoice() {
        int choice;
        cout << "\n\nEnter Your Choice: ";
        cin >> choice ;
        cout << endl << endl;
        return choice;
    }

    void displayData(string cricketerName, double battingAvg, string dataName) {
        cout << "\n\n=======================  OUTPUT  =======================" << endl;
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   ": " << battingAvg << endl << endl;
    }

    void displayData(string cricketerName, double dataPointOne, double dataPointTwo, string dataName) {
        cout << "\n\n=======================  OUTPUT  =======================" << endl;
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   ": " << dataPointOne << 
        " / " << dataPointTwo << endl << endl;
    }
};
