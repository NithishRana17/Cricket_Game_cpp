#include "Player.h"

Player::Player(std::string playerName, int playerId) {
    name = playerName;
    id = playerId;
    resetStats();
}

void Player::resetStats() {
    runsScored = 0;
    ballsPlayed = 0;
    ballsBowled = 0;
    runsGiven = 0;
    wicketsTaken = 0;
}
