#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    std::string name;
    int id;
    int runsScored;
    int ballsPlayed;
    int ballsBowled;
    int runsGiven;
    int wicketsTaken;

    Player(std::string playerName, int playerId);

    void resetStats();
};

#endif
