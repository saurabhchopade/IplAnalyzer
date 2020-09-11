#include <iostream>
#include  <stdlib.h>
using namespace std;
class IplController {
    Display view;
    IplAnalyser analyser;
    Runs batsman;

public:
    IplController() {}

    IplController(Display view, IplAnalyser analyser) {
        this -> view = view;
        this -> analyser = analyser;
    }

    void welcomeNote() {
        cout << "\n\nIPL ANALYSER SYSTEM" << endl;
    }

    void showOptions() {
        bool start = true;

        enum choice {
            TOP_BATTING_AVG = 1,
            TOP_STRIKES_RATE,
            TOP_SIX_FOUR,
            CLEAR_SCREEN,
            EXIT
        };

        while (start) {
            cout << "\n\n1. Find Top Batting Average" << "\n\n2. Top Strike Rate Player" 
            << "\n\n3. Top SixFour Hitman" << "\n\n4. Clear Screen" <<"\n\n5. Exit\n\n" 
            << endl;
            
            switch (view.inputChoice()) {
            case choice::TOP_BATTING_AVG:
                findBattingAverage();
                break;
            case choice::TOP_STRIKES_RATE:
                findSrikesRateAverage();
                break;
            case choice::TOP_SIX_FOUR:
                findSixFourHitman();
                break;
            case choice::CLEAR_SCREEN:
                system("cls");
                break;
            case choice::EXIT:
                start = false; 
                break;       
            default:
                cout << "Enter Valid Choice" << endl;
                break;
            } 
        }
        
    }

    void getChoice() {
        view.inputChoice();
    }

    void findBattingAverage() {
        string dataName = " Average";
        this -> batsman = analyser.findTopBattingAverage();
        displayData(batsman.getPlayerName(), batsman.getAverage(),dataName);
    }

    void findSrikesRateAverage() {
        string dataName = " StrikeRate";
        this -> batsman = analyser.findTopSrikeRate();
        displayData(batsman.getPlayerName(), batsman.getStrikeRate(), dataName);
    }

    void findSixFourHitman() {
        string dataName = " SixFour";
        this -> batsman = analyser.findTopSixFourHitman();
        displayData(batsman.getPlayerName(), batsman.getStrikeRate(), dataName);
    }

    void displayData(string playerName, double playerData, string dataName) {
        view.displayTopBatsmanData(playerName,playerData, dataName);
    }
};
