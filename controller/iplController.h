#include <iostream>
#include  <stdlib.h>
using namespace std;
class IplController
{
    Display view;
    IplAnalyser analyser;
    Runs batsman;

public:
    IplController(){}

    IplController(Display view, IplAnalyser analyser) {
        this -> view = view;
        this -> analyser = analyser;
    }

    void welcomeNote() {
        cout << "IPL ANALYSER SYSTEM" << endl;
    }

    void showOptions() {
        bool start = true;

        enum choice {
            TOP_BATTING_AVG = 1,
            CLEAR_SCREEN,
            EXIT
        };

        while (start) {
            cout << "\n\n1. Find Top Batting Average" << "\n\n2. Clear Screen" <<"\n\n3. Exit\n\n" << endl;
            switch (view.inputChoice())
            {
            case choice::TOP_BATTING_AVG:
                findBattingAverage();
                break;
            case choice::CLEAR_SCREEN:
                system("cls");
                break;
            case choice::EXIT:
                start = false; 
                break;       
            default:
                cout << "Enter Valid Choice..." << endl;
                break;
            } 
        }
        
    }

    void getChoice()
    {
        view.inputChoice();
    }

    void findBattingAverage()
    {
        this -> batsman = analyser.findTopBattingAverage();
        displayTopBattingAvg();
    }

    void displayTopBattingAvg()
    {
        view.displayTopBatsmanByAverage(batsman.getPlayerName(),
             batsman.getAverage());
    }
};
