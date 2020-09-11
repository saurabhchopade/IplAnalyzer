#include <iostream>
#include <unordered_map>
#include <variant>
using namespace std;
class Runs 
{    
    string player, high_score;
    int match, innings, run, hundred, fifty, fours, six;
    double  avg, strikeRate;

public:
    Runs(){};
    Runs(string player_name) {
        player = player_name;
    }

    string getPlayerName() {
        return player;
    }

    void setHighScore(string high_score) {
        this -> high_score = high_score;
    }

    string getHighScore() {
        return high_score;
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
    
    void setHundered(int hundered) {
        this -> hundred = hundred;
    }

    int getHundered() {
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

    double getAverage() {
        return avg;
    }

    void setStrikeRate(double strikeRate) {
        this -> strikeRate = strikeRate;
    }

    double getStrikeRate() {
        return strikeRate;
    }
};    