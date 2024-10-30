#include "Team.h"

Team::Team(std::string name) : teamName(name), totalRuns(0), totalWickets(0), totalBallsBowled(0) {}

void Team::addPlayer(Player player) {
    players.push_back(player);
}

std::vector<Player>& Team::getPlayers() {
    return players;
}

void Team::addRuns(int runs) {
    totalRuns += runs;
}

void Team::addBallBowled() {
    totalBallsBowled++;
}

void Team::addWicket() {
    totalWickets++;
}

void Team::resetTeamStats() {
    totalRuns = 0;
    totalWickets = 0;
    totalBallsBowled = 0;
}
