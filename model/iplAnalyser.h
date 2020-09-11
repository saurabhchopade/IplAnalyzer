#include <iostream>
#include "../utility/csvReader.h"
#include "iplRun.h"
#include <algorithm>
using namespace std;
class IplAnalyser
{
    string file_path = "../resources/MostRuns.csv";
    vector<unordered_map<string, string>> csv_data;
    vector<Runs> player_records;

public:
    IplAnalyser()
    {
        this -> csv_data = csvlib::csvToObj(file_path);
        update_player_record();
    }

    vector<Runs> get_player_record()
    {
        return player_records;
    }

    void update_player_record()
    {
        for(unordered_map<string, string> itr : csv_data)
        {
            Runs most_runs(itr.at("PLAYER"));
            most_runs.setMatch(stoi(itr.at("Mat")));
            most_runs.setInnings(stoi(itr.at("Inns")));
            most_runs.setRun(stoi(itr.at("Runs")));
            most_runs.setHighScore(itr.at("HS"));
            most_runs.setAverage(stod(itr.at("Avg")));
            most_runs.setFifty(stoi(itr.at("50")));
            most_runs.setFours(stoi(itr.at("4s")));
            most_runs.setHundered(stoi(itr.at("100")));
            most_runs.setSix(stoi(itr.at("6s")));
            most_runs.setStrikeRate(stod(itr.at("SR")));
            player_records.push_back(most_runs);
        }
    }

    Runs findTopBattingAverage()
    {
        sort(player_records.begin(), player_records.end(),[] (
           Runs &first_batsman, Runs &second_batsman) -> bool
            {
                return (first_batsman.getAverage() < second_batsman.getAverage());
            }
        );
        
        return player_records[player_records.size() - 1];
    }
};
