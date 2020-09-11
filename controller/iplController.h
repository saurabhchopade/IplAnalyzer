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
            SR_WRT_SIX_FOUR,
            BEST_AVG_STRIKERATE,
            MAX_RUN_BEST_AVG,
            CLEAR_SCREEN,
            EXIT
        };

        while (start) {
            cout << "\n\n1. Find Top Batting Average" << "\n\n2. Top Strike Rate Player" 
            << "\n\n3. Top SixFour Hitman" << "\n\n4. Top StrikeRate WRT SixFour"  
            << "\n\n5. Top Best Avg And Strike Rate"  << "\n\n6. Max Run / Best Avg"
            << "\n\n7. Clear Screen" <<"\n\n8. Exit\n\n" 
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
            case choice:: SR_WRT_SIX_FOUR:
                findStrikeRateofSixFour();
                break;
            case choice:: BEST_AVG_STRIKERATE:
                findBestAvgAndStrikeRate();
                break;
            case choice:: MAX_RUN_BEST_AVG:
                findMaxRunAndBestAvg();
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
        this -> batsman = analyser.findTopStrikeRate();
        displayData(batsman.getPlayerName(), batsman.getStrikeRate(), dataName);
    }

    void findSixFourHitman() {
        string dataName = "Six / Four";
        this -> batsman = analyser.findTopSixFourHitman();
        displayDataField(batsman.getPlayerName(),batsman.getSix(),batsman.getFour(),dataName);
    }

    void findStrikeRateofSixFour() {
        double six = 6;
        double four = 4;
        string dataName = "SR WithRTO SixFour";
        this -> batsman = analyser.findTopSrOfSixFour();
        double strikeRate = ( (batsman.getSix()*six) + (batsman.getFour()*four) ) 
                            /(batsman.getSix()+batsman.getFour()); 

        displayData(batsman.getPlayerName(), strikeRate, dataName);
    }

    void findBestAvgAndStrikeRate() {
        string dataName = "Best Avg / Best StrikeRate";
        this -> batsman = analyser.findGreatAverageAndStrikeRate();
        displayDataField(batsman.getPlayerName(),batsman.getAverage(),batsman.getStrikeRate(),dataName);
    }
    void findMaxRunAndBestAvg() {
        string dataName = "MAx Run / Best Avg";
        this -> batsman = analyser.findMaxRunBestAvg();
        displayDataField(batsman.getPlayerName(),batsman.getRun(),batsman.getAverage(),dataName);
    }

    void displayData(string playerName, double playerData, string dataName) {
        view.displayTopBatsmanData(playerName,playerData, dataName);
    }

    void displayDataField(string playerName, double playerDataOne, double playerDataTwo, string dataName) {
        view.displayPlayerData(playerName,playerDataOne,playerDataTwo, dataName);
    }

 
};
