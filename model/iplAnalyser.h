#include <iostream>
#include "../utility/csvReader.h"
#include "iplRun.h"
#include "iplWickets.h"
#include "iplRunWickets.h"
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
    vector<RunsWickets> allRounderRecords;

public:
    IplAnalyser() {
        this -> battingCsvData = csvlib::csvToObj(batsmanFilePath);
        this -> bowlingCsvData = csvlib::csvToObj(bowlerFilePath);
        updateBatsmanRecord();
        updateBowlerRecord();
        updateAllRounderRecord();
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

    void updateAllRounderRecord() {
        for(unordered_map<string, string> batsman : battingCsvData) {
          
            for(unordered_map<string, string> bowler : bowlingCsvData) {
              
                if(batsman.at("PLAYER") == bowler.at("PLAYER")) {
                    RunsWickets mostRunWicket(batsman.at("PLAYER"));
                    mostRunWicket.setBattingAverage(stod(batsman.at("Avg")));
                    mostRunWicket.setBowlingAverage(stod(bowler.at("Avg")));
                    mostRunWicket.setRuns(stoi(batsman.at("Runs")));
                    mostRunWicket.setWickets(stoi(bowler.at("Wkts")));
                    mostRunWicket.setHundred(stoi(batsman.at("100")));
                    mostRunWicket.setFifty(stoi(batsman.at("50")));
                    allRounderRecords.push_back(mostRunWicket);
                }
            }
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
           Wicket &firstBowler, Wicket &secondBowler) -> bool {
              
                if(firstBowler.getAverage() > 0 && secondBowler.getAverage() > 0 ) {     
                    return ( firstBowler.getAverage() > secondBowler.getAverage() );
                }
                return false;    
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }
  
    Wicket findBowlingStrikeRate() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &firstBowler, Wicket &secondBowler) -> bool {

                if(firstBowler.getStrikeRate() > 0 && secondBowler.getStrikeRate() > 0 ) {     
                    return ( firstBowler.getStrikeRate() > secondBowler.getStrikeRate());
                }
               return false;
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }

    Wicket findBowlingEconomyRate() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
            Wicket &firstBowler, Wicket &secondBowler) -> bool {
                return ( firstBowler.getEconomy() 
                > secondBowler.getEconomy());   
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    }

    Wicket findBowlerSrWithWkts() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &firstBowler, Wicket &secondBowler) -> bool {

                if(firstBowler.getStrikeRate() > 0 && secondBowler.getStrikeRate() > 0 ) {     
                    return ( (firstBowler.getStrikeRate()- (firstBowler.getFourWkts()+ firstBowler.getFiveWkts())) 
                             > ( secondBowler.getStrikeRate() - ( secondBowler.getFiveWkts() 
                            + secondBowler.getFourWkts()) ));
                }
               return false;
            }
        );
        
        return bowlerRecords[bowlerRecords.size() - 1];
    } 

    Wicket findTopBowlerAvgWithSr() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &firstBowler, Wicket &secondBowler) -> bool {
         
                if(firstBowler.getStrikeRate() > 0 && secondBowler.getStrikeRate() > 0 ) {     
                    return ( firstBowler.getAverage() * firstBowler.getStrikeRate() 
                            > secondBowler.getAverage() * secondBowler.getStrikeRate() );
                }
                return false;   
            }
        );
        return bowlerRecords[bowlerRecords.size() - 1];
    }

    Wicket findBowlerMaxWicketsWithAvg() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &firstBowler, Wicket &secondBowler) -> bool {
         
                if(firstBowler.getWickets() > 0 && secondBowler.getWickets() > 0 ) {     
                    return ( firstBowler.getWickets() - firstBowler.getAverage() 
                        < secondBowler.getWickets() - secondBowler.getAverage() );
                }
                return false;   
            }
        );
        return bowlerRecords[bowlerRecords.size() - 1];
    }

//Allrounder
    RunsWickets findAllRounderWithAverage() {
        sort(allRounderRecords.begin(), allRounderRecords.end(),[] (
           RunsWickets &firstAllRounder, RunsWickets &secondAllRounder) -> bool {
                    return ( firstAllRounder.getBattingAverage() * firstAllRounder.getBowlingAverage() 
                         < secondAllRounder.getBattingAverage() * secondAllRounder.getBowlingAverage());
            }
        );
        return allRounderRecords[allRounderRecords.size() - 1];
    }

    RunsWickets findAllRounderByWktsAndRuns() {
        sort(allRounderRecords.begin(), allRounderRecords.end(),[] (
           RunsWickets &firstAllRounder, RunsWickets &secondAllRounder) -> bool {
                    return ( firstAllRounder.getWickets() * firstAllRounder.getRuns() 
                         < secondAllRounder.getWickets() * secondAllRounder.getRuns());
            }
        );
        return allRounderRecords[allRounderRecords.size() - 1];
    }

};

