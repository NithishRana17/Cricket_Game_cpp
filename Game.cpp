#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Game::Game() : teamA("Team A"), teamB("Team B"), maxBalls(6), currentInning(1) {
    playerPool = { "Virat", "Rohit", "Dhawan", "Rahul", "Kohli", "Dhoni", "Jadeja", "Pant", "Bumrah", "Shami", "Pandya" };
}

void Game::startGame() {
    std::cout << "Welcome to the Cricket Game!" << std::endl;

    // Select players for Team A
    std::cout << "Select players for Team A:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        int index;
        std::cout << "Choose player " << (i + 1) << " for Team A (0-10): ";
        std::cin >> index;
        teamA.addPlayer(Player(playerPool[index], index));
    }

    // Select players for Team B
    std::cout << "Select players for Team B:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        int index;
        std::cout << "Choose player " << (i + 1) << " for Team B (0-10): ";
        std::cin >> index;
        teamB.addPlayer(Player(playerPool[index], index));
    }

    toss();
}

void Game::toss() {
    srand(time(0));
    int tossResult = rand() % 2;
    if (tossResult == 0) {
        std::cout << "Team A wins the toss and chooses to bat first!" << std::endl;
        battingTeam = &teamA;
        bowlingTeam = &teamB;
    }
    else {
        std::cout << "Team B wins the toss and chooses to bat first!" << std::endl;
        battingTeam = &teamB;
        bowlingTeam = &teamA;
    }

    playInnings(battingTeam, bowlingTeam);
    playInnings(bowlingTeam, battingTeam);
}

void Game::playInnings(Team* battingTeam, Team* bowlingTeam) {
    batsman = &battingTeam->getPlayers().at(0);
    bowler = &bowlingTeam->getPlayers().at(0);

    for (int i = 0; i < maxBalls; ++i) {
        int runs = rand() % 7;
        if (runs == 0) {
            std::cout << batsman->name << " is OUT!" << std::endl;
            battingTeam->addWicket();
            if (battingTeam->totalWickets == 4) {
                break;
            }
            batsman = &battingTeam->getPlayers().at(battingTeam->totalWickets);
        }
        else {
            batsman->runsScored += runs;
            battingTeam->addRuns(runs);
        }
        battingTeam->addBallBowled();
        displayScorecard(battingTeam, bowlingTeam, batsman, bowler, i + 1);
    }
}

void Game::displayScorecard(Team* battingTeam, Team* bowlingTeam, Player* batsman, Player* bowler, int currentBall) {
    std::cout << "Ball " << currentBall << " Scorecard: " << std::endl;
    std::cout << battingTeam->teamName << " - " << battingTeam->totalRuns << "/" << battingTeam->totalWickets << std::endl;
}
