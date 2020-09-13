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
        view.displayData(batsman.getPlayerName(), batsman.getAverage(),dataName);
    }

    void findSrikesRateAverage() {
        string dataName = " StrikeRate";
        this -> batsman = analyser.findTopStrikeRate();
        view.displayData(batsman.getPlayerName(), batsman.getStrikeRate(), dataName);
    }

    void findSixFourHitman() {
        string dataName = "Six / Four";
        this -> batsman = analyser.findTopSixFourHitman();
        view.displayData(batsman.getPlayerName(), batsman.getSix(), batsman.getFour(),dataName);
    }

    void findStrikeRateofSixFour() {
        double six = 6;
        double four = 4;
        string dataName = "SR WithRTO SixFour";
        this -> batsman = analyser.findTopSrOfSixFour();
        double strikeRate = ( (batsman.getSix()*six) + (batsman.getFour()*four) ) 
                            /(batsman.getSix()+batsman.getFour()); 

        view.displayData(batsman.getPlayerName(), strikeRate, dataName);
    }

    void findBestAvgAndStrikeRate() {
        string dataName = "Best Avg / Best StrikeRate";
        this -> batsman = analyser.findGreatAverageAndStrikeRate();
        view.displayData(batsman.getPlayerName(),batsman.getAverage(),batsman.getStrikeRate(),dataName);
    }
    void findMaxRunAndBestAvg() {
        string dataName = "MAx Run / Best Avg";
        this -> batsman = analyser.findMaxRunBestAvg();
        view.displayData(batsman.getPlayerName(),batsman.getRun(),batsman.getAverage(),dataName);
    }

    void  findMaxBowlingAvg() {
        string dataName = "Bowling Avg";
        this -> bowler = analyser.findBestBowlingAvg();
        view.displayData(bowler.getPlayerName(),bowler.getAverage(),dataName);
    }
    void  findMaxBowlingStrikeRate() {
        string dataName = "Bowling StrikeRate";
        this -> bowler = analyser.findBowlingStrikeRate();
        view.displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void  findBowlingEconomyRate() {
        string dataName = "Economy Rate";
        this -> bowler = analyser.findBowlingEconomyRate();
        view.displayData(bowler.getPlayerName(),bowler.getEconomy(),dataName);
    }

    void topBowlerStrikeRateWithWkts() {
        string dataName = "Bowl StrikeRate WRT Wkts";
        this -> bowler = analyser.findSrWithWkts();
        view.displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void topBowlerBestAvgWithSr() {
        string dataName = "Bowl Avg WRT StrikeRate";
        this -> bowler = analyser.findTopAvgWithSr();
        view.displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }

    void  topBowlerMaxWktsWithAvg() {
        string dataName = "Max Wkts WT Avg";
        this -> bowler = analyser.findBowlerMaxWicketsWithAvg();
        view.displayData(bowler.getPlayerName(),bowler.getStrikeRate(),dataName);
    }
    C
};
