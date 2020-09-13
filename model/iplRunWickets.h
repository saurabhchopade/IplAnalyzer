#include <iostream>
#include <unordered_map>
#include <variant>
using namespace std;

class RunsWickets 
{    
    string player;
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
};   