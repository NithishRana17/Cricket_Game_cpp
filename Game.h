#ifndef GAME_H
#define GAME_H

#include "Team.h"
#include <vector>

class Game {
private:
    std::vector<std::string> playerPool;
    Team* battingTeam;
    Team* bowlingTeam;
    Player* batsman;
    Player* bowler;
    int maxBalls;
    int currentInning;

public:
    Team teamA;
    Team teamB;

    Game();
    void startGame();
    void toss();
    void playInnings(Team* battingTeam, Team* bowlingTeam);
    void displayScorecard(Team* battingTeam, Team* bowlingTeam, Player* batsman, Player* bowler, int currentBall);
};

#endif
