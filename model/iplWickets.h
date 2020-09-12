#include <iostream>
#include <unordered_map>
using namespace std;

class Wicket
{
public:
    string player;
    
    int match, innings, runs, wickets, fourWkts, fiveWkts, over;
    double  bbi, average, economy, strikeRate;

    Wicket(){};

    Wicket(string playerName) {
        player = playerName;
    }

    string getPlayerName() {
        return player;
    }

    void setOver(int over) {
        this -> over = over;
    }

    int getOver() {
        return over;
    }
    
    void setWickets(int wickets) {
        this -> wickets = wickets;
    }

    int getWickets() {
        return wickets;
    }

    void setMatch(int match) {
        this -> match = match;
    }

    int getMatch() {
        return match;
    }

    void setInnings(int innings) {
        this -> innings = innings;
    }

    int get_innings() {
        return innings;
    }

    void setRun(int runs) {
        this -> runs = runs;
    }

    int getRun() {
        return runs;
    }
    
    void setBbi(int bbi) {
        this -> bbi = bbi;
    }

    int getBbi() {
        return bbi;
    }

    void setEconomy(double economy) {
        this -> economy = economy;
    }

    double getEconomy() {
        return economy;
    }
    
    void setFoursWkts(int fourWkts) {
        this -> fourWkts = fourWkts;
    }

    int getFourWkts() {
        return fourWkts;
    }

    void setFiveWkts(int fiveWkts) {
        this -> fiveWkts = fiveWkts;
    }

    int getFiveWkts() {
        return fiveWkts;
    }

    void setAverage(double avg) {
        this -> average = avg;
    }

    double getAverage() {
        return average;
    }

    void setStrikeRate(double strikeRate) {
        this -> strikeRate = strikeRate;
    }

    double getStrikeRate() {
        return strikeRate;
    }
};    
