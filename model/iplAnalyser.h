#include <iostream>
#include "../utility/csvReader.h"
#include "iplRun.h"
#include "iplWickets.h"
#include <algorithm>
using namespace std;
class IplAnalyser
{
    string batsmanFilePath = "../resources/MostRuns.csv";
    string bowlerFilePath = "../resources/MostWkts.csv";
    vector<unordered_map<string, string>> battingCsvData;
    vector<unordered_map<string, string>> bowlingCsvData;
    vector<Runs> batsmanRecords;
    vector<Wicket> bowlerRecords;

public:
    IplAnalyser() {
        this -> battingCsvData = csvlib::csvToObj(batsmanFilePath);
        this -> bowlingCsvData = csvlib::csvToObj(bowlerFilePath);
        updateBatsmanRecord();
        updateBowlerRecord();
    }

    vector<Runs> get_player_record() {
        return batsmanRecords;
    }

    void updateBatsmanRecord() {
        for(unordered_map<string, string> itr : battingCsvData) {
            Runs mostRuns(itr.at("PLAYER"));
            mostRuns.setMatch(stoi(itr.at("Mat")));
            mostRuns.setInnings(stoi(itr.at("Inns")));
            mostRuns.setRun(stoi(itr.at("Runs")));
            mostRuns.setHighScore(itr.at("HS"));
            mostRuns.setAverage(stod(itr.at("Avg")));
            mostRuns.setFifty(stoi(itr.at("50")));
            mostRuns.setFours(stoi(itr.at("4s")));
            mostRuns.setHundered(stoi(itr.at("100")));
            mostRuns.setSix(stoi(itr.at("6s")));
            mostRuns.setStrikeRate(stod(itr.at("SR")));
            batsmanRecords.push_back(mostRuns);
        }
    }
    void updateBowlerRecord() {
        for(unordered_map<string, string> itr : bowlingCsvData) {
            Wicket mostWicket(itr.at("PLAYER"));
            mostWicket.setMatch(stoi(itr.at("Mat")));
            mostWicket.setInnings(stoi(itr.at("Inns")));
            mostWicket.setRun(stoi(itr.at("Runs")));
            mostWicket.setOver(stoi(itr.at("Ov")));
            mostWicket.setAverage(stod(itr.at("Avg")));
            mostWicket.setWickets(stoi(itr.at("Wkts")));
            mostWicket.setFoursWkts(stoi(itr.at("4w")));
            mostWicket.setEconomy(stod(itr.at("Econ")));
            mostWicket.setFiveWkts(stoi(itr.at("5w")));
            mostWicket.setStrikeRate(stod(itr.at("SR")));
            bowlerRecords.push_back(mostWicket);
        }
    }

    Runs findTopBattingAverage() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
                return (first_batsman.getAverage() < second_batsman.getAverage());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findTopStrikeRate() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
                return (first_batsman.getStrikeRate() < second_batsman.getStrikeRate());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findTopSixFourHitman() {
       
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
                return ( ((first_batsman.getSix()*6) + (first_batsman.getFour()*4)) < ((second_batsman.getSix()*6) + (second_batsman.getFour()*4)));
            }
        );
        return batsmanRecords[batsmanRecords.size() - 1];
    }
    
    Runs findTopSrOfSixFour() {

        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
                return ( ((first_batsman.getSix()*6) + (first_batsman.getFour()*4)) < ((second_batsman.getSix()*6) + (second_batsman.getFour()*4)));
            }
        );
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findGreatAverageAndStrikeRate() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
                return ( first_batsman.getAverage() * first_batsman.getStrikeRate() 
                < second_batsman.getAverage() * second_batsman.getStrikeRate() );
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findMaxRunBestAvg() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool {
            
                return ( first_batsman.getRun()*first_batsman.getAverage() 
                < second_batsman.getRun()* second_batsman.getAverage() );
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    //bowler

    Wicket findBestBowlingAvg() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &first_batsman, Wicket &second_batsman) -> bool {
            
                return ( first_batsman.getAverage() 
                < second_batsman.getAverage() );
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }
  
    Wicket findBowlingStrikeRate() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &first_batsman, Wicket &second_batsman) -> bool {
            
                return ( first_batsman.getStrikeRate() 
                < second_batsman.getStrikeRate() );
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }

    Wicket findBowlingEconomyRate() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &first_batsman, Wicket &second_batsman) -> bool {
            
                return ( first_batsman.getEconomy() 
                > second_batsman.getEconomy() );
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }

    
};

