#include <iostream>
#include  <stdlib.h>
using namespace std;

class IplController {
    Display view;
    IplAnalyser analyser;
    Runs batsman;
    Wicket bowler;

public:
    IplController() {}

    IplController(Display view, IplAnalyser analyser) {
        this -> view = view;
        this -> analyser = analyser;
        view.welcomeNote();
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
            BOWLING_AVERAGE,
            BOWLING_STRIKERATE,
            BOWLING_ECONOMY,
            BOWL_SR_WITH_WKTS,
            BESTBOWL_AVG_WITH_SR,
            BESTBOWL_MAXWKTS_WITH_AVG,
            CLEAR_SCREEN,
            EXIT
        };

        while (start) {
            view.options();

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
                case choice:: BOWLING_AVERAGE:
                    findMaxBowlingAvg();
                    break;
                case choice:: BOWLING_STRIKERATE:
                    findMaxBowlingStrikeRate();
                    break;
                case choice:: BOWLING_ECONOMY:
                    findBowlingEconomyRate();
                    break;
                case choice:: BOWL_SR_WITH_WKTS:
                    topBowlerStrikeRateWithWkts();
                    break;
                case choice:: BESTBOWL_AVG_WITH_SR:
                    topBowlerBestAvgWithSr();
                    break;
                case choice:: BESTBOWL_MAXWKTS_WITH_AVG:
                    topBowlerMaxWktsWithAvg();
                    break;
                case choice::CLEAR_SCREEN:
                    system("clear");
                    break;
                case choice::EXIT:
                    start = false; 
                    break;       
                default:
                    view.validOptionMsg();
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

    void  findMaxBowlingAvg() {
        string dataName = "Bowling Avg";
        this -> bowler = analyser.findBestBowlingAvg();
        displayData(bowler.getPlayerName(),bowler.getAverage(),dataName);
    }
    void  findMaxBowlingStrikeRate() {
        string dataName = "Bowling StrikeRate";
        this -> bowler = analyser.findBowlingStrikeRate();
        displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void  findBowlingEconomyRate() {
        string dataName = "Economy Rate";
        this -> bowler = analyser.findBowlingEconomyRate();
        displayData(bowler.getPlayerName(),bowler.getEconomy(),dataName);
    }

    void topBowlerStrikeRateWithWkts() {
        string dataName = "Bowl StrikeRate WRT Wkts";
        this -> bowler = analyser.findSrWithWkts();
        displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void topBowlerBestAvgWithSr() {
        string dataName = "Bowl Avg WRT StrikeRate";
        this -> bowler = analyser.findTopAvgWithSr();
        displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void  topBowlerMaxWktsWithAvg() {
        string dataName = "Max Wkts WT Avg";
        this -> bowler = analyser.findBowlerMaxWicketsWithAvg();
        displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void displayData(string playerName, double playerData, string dataName) {
        view.displayTopBatsmanData(playerName,playerData, dataName);
    }

    void displayDataField(string playerName, double playerDataOne, double playerDataTwo, string dataName) {
        view.displayPlayerData(playerName,playerDataOne,playerDataTwo, dataName);
    }

};
