#include <iostream>
#include <unordered_map>
#include <variant>
using namespace std;

class RunsWickets 
{    
    string player;
    int wickets, runs, hundred, fifty;
    double battingAverage, bowlingAverage;

public:

    RunsWickets(){};

    RunsWickets(string playerName) {
        player = playerName;
    }
    
    string getPlayerName() {
        return player;
    }

    void setBattingAverage(double battingAverage) {
        this->battingAverage = battingAverage;
    }

    double getBattingAverage() {
        return battingAverage; 
    }

    void setBowlingAverage(double bowlingAverage) {
        this->bowlingAverage = bowlingAverage;
    }

    double getBowlingAverage() {
        return bowlingAverage; 
    }

    void setRuns(double runs) {
        this->runs = runs;
    }

    double getRuns() {
        return runs; 
    }

    void setWickets(double wickets) {
        this-> wickets = wickets;
    }

    double getWickets() {
        return wickets; 
    }

    void setHundred(double hundred) {
        this-> hundred = hundred;
    }

    double getHundred() {
        return hundred; 
    }
    
    void setFifty(double fifty) {
        this-> fifty = fifty;
    }

    double getFifty() {
        return fifty; 
    }

};   