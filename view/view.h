#include <iostream>
using namespace std;
class Display
{
public:

    void welcomeNote() {
        cout << "\n\n====================IPL ANALYSER SYSTEM======================" << endl;
    }
    void options() {
        cout << "\n\n1. Find Top Batting Average" << "\n\n2. Top Strike Rate Player" 
            << "\n\n3. Top SixFour Hitman" << "\n\n4. Top StrikeRate WRT SixFour"  
            << "\n\n5. Top Best Avg And Strike Rate"  << "\n\n6. Max Run / Best Avg"
            << "\n\n7. Top Bowling average" << "\n\n8. Bowling StrikeRate"  
            << "\n\n9. Bowler Economy Rate" << "\n\n10. Bowler Best SR with wkts"
            << "\n\n11. Bowler Best SR with Avg" << "\n\n12. Bowler Max Wkts with Avg"
             << "\n\n13. Clear Screen" <<"\n\n14. Exit\n\n" 
            << endl;
    }

    void validOptionMsg(){
        cout << "Enter Valid Choice" << endl;

    }
    int inputChoice() {
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice ;
        cout << endl << endl;
        return choice;
    }

    void displayTopBatsmanData(string cricketerName, double battingAvg, string dataName) {
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   ": " << battingAvg << endl;
    }

    void displayPlayerData(string cricketerName, double dataPointOne
                    ,double dataPointTwo, string dataName) {
        cout << "PLAYER NAME : " << cricketerName;
        cout << "\n" << dataName <<   ": " << dataPointOne << 
        " / " << dataPointTwo << endl;
    }
};
