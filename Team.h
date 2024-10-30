#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <vector>

class Team {
public:
    std::string teamName;
    std::vector<Player> players;
    int totalRuns;
    int totalWickets;
    int totalBallsBowled;

    Team(std::string name);

    void addPlayer(Player player);
    std::vector<Player>& getPlayers();
    void addRuns(int runs);
    void addBallBowled();
    void addWicket();
    void resetTeamStats();
};

#endif
