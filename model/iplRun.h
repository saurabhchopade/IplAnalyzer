#include <iostream>
#include <unordered_map>
#include <variant>
using namespace std;
class Runs 
{    
    string player, highScore;
    int match, avg, innings, run, hundred, fifty, fours, six;
    double   strikeRate;

public:

    Runs(){};

    Runs(string playerName) {
        player = playerName;
    }

    string getPlayerName() {
        return player;
    }

    void setHighScore(string highScore) {
        this -> highScore = highScore;
    }

    string getHighScore() {
        return highScore;
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

    void setRun(int run) {
        this -> run = run;
    }

    int getRun() {
        return run;
    }
    
    void setHundered(int hundred) {
        this -> hundred = hundred;
    }

    int getHundred() {
        return hundred;
    }

    void setFifty(int fifty) {
        this -> fifty = fifty;
    }

    int getFifty() {
        return fifty;
    }
    
    void setFours(int fours) {
        this -> fours = fours;
    }

    int getFour() {
        return fours;
    }

    void setSix(int six) {
        this -> six = six;
    }

    int getSix() {
        return six;
    }

    void setAverage(double avg) {
        this -> avg = avg;
    }

    int getAverage() {
        return avg;
    }

    void setStrikeRate(double strikeRate) {
        this -> strikeRate = strikeRate;
    }

    double getStrikeRate() {
        return strikeRate;
    }
};    
