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
        this -> battingCsvData = csvlib:: csvToObj(batsmanFilePath);
        this -> bowlingCsvData = csvlib:: csvToObj(bowlerFilePath);
        updateBatsmanRecord();
        updateBowlerRecord();
        updateAllRounderRecord();
    }

    void updateBatsmanRecord() {
        for(unordered_map<string, string> player : battingCsvData) {
            Runs mostRuns(player.at("PLAYER"));
            mostRuns.setMatch(stoi(player.at("Mat")));
            mostRuns.setInnings(stoi(player.at("Inns")));
            mostRuns.setRun(stoi(player.at("Runs")));
            mostRuns.setHighScore(player.at("HS"));
            mostRuns.setAverage(stoi(player.at("Avg")));
            mostRuns.setFifty(stoi(player.at("50")));
            mostRuns.setFours(stoi(player.at("4s")));
            mostRuns.setHundered(stoi(player.at("100")));
            mostRuns.setSix(stoi(player.at("6s")));
            mostRuns.setStrikeRate(stod(player.at("SR")));
            batsmanRecords.push_back(mostRuns);
        }
    }
    
    void updateBowlerRecord() {
        for(unordered_map<string, string> player : bowlingCsvData) {
            Wicket mostWicket(player.at("PLAYER"));
            mostWicket.setMatch(stoi(player.at("Mat")));
            mostWicket.setInnings(stoi(player.at("Inns")));
            mostWicket.setRun(stoi(player.at("Runs")));
            mostWicket.setOver(stoi(player.at("Ov")));
            mostWicket.setAverage(stod(player.at("Avg")));
            mostWicket.setWickets(stoi(player.at("Wkts")));
            mostWicket.setFoursWkts(stoi(player.at("4w")));
            mostWicket.setEconomy(stod(player.at("Econ")));
            mostWicket.setFiveWkts(stoi(player.at("5w")));
            mostWicket.setStrikeRate(stod(player.at("SR")));
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
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
                return (firstBatsman.getAverage() < secondBatsman.getAverage());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findTopStrikeRate() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
                return (firstBatsman.getStrikeRate() < secondBatsman.getStrikeRate());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findTopSixFourHitman() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
                return (((firstBatsman.getSix()*6) + (firstBatsman.getFour()*4)) 
                        < ((secondBatsman.getSix()*6) + (secondBatsman.getFour()*4)));
            }
        );
        return batsmanRecords[batsmanRecords.size() - 1];
    }
    
    Runs findTopSrOfSixFour() {

        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
                return (((firstBatsman.getSix()*6) + (firstBatsman.getFour()*4)) 
                        < ((secondBatsman.getSix()*6) + (secondBatsman.getFour()*4)));
            }
        );
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findGreatAverageAndStrikeRate() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
                return (firstBatsman.getAverage() * firstBatsman.getStrikeRate() 
                        < secondBatsman.getAverage() * secondBatsman.getStrikeRate());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findMaxRunBestAvg() {
        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {
            
                return (firstBatsman.getRun()*firstBatsman.getAverage() 
                        < secondBatsman.getRun()* secondBatsman.getAverage());
            }
        );
        
        return batsmanRecords[batsmanRecords.size() - 1];
    }

//bowler

    Wicket findBestBowlingAvg() {
        sort(bowlerRecords.begin(), bowlerRecords.end(),[] (
           Wicket &firstBowler, Wicket &secondBowler) -> bool {
              
                if(firstBowler.getAverage() > 0 && secondBowler.getAverage() > 0 ) {     
                    return (firstBowler.getAverage() > secondBowler.getAverage());
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
                             > ( secondBowler.getStrikeRate() - ( secondBowler.getFiveWkts() + secondBowler.getFourWkts()) ));
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


    Runs findBatsmanByHundredAndAvg() {

        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {

               if(firstBatsman.getHundred() > 0  || secondBatsman.getHundred() > 0) {
                    return ( firstBatsman.getHundred() * firstBatsman.getAverage() 
                         < secondBatsman.getHundred() * secondBatsman.getAverage());
               }
               return false;
            }
        );

        return batsmanRecords[batsmanRecords.size() - 1];
    }

    Runs findBatsmanByAvg() {

        sort(batsmanRecords.begin(), batsmanRecords.end(),[] (
           Runs &firstBatsman, Runs &secondBatsman) -> bool {

               if(firstBatsman.getHundred() == 0  || secondBatsman.getHundred() == 0) {
                    return ( firstBatsman.getAverage() < secondBatsman.getAverage());
               }
               return false;
            }
        );

        return batsmanRecords[batsmanRecords.size() - 1];
    }

};

