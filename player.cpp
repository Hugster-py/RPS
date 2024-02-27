//
// Created by chase on 2/25/2024.
//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player(string name) {
    this->name = name;
    wins = 0;
    losses = 0;
    Rock = 0;
    Paper = 0;
    Scissor = 0;
    win_loss_ratio = 0.0;
    ties = 0;
}

void Player::printAllStats() {
    Win_Loss_R();
    cout << "--" << name << "'s Stats--" << endl;
    cout << "Total Wins: " << wins << endl;
    cout << "Total Losses: " << losses << endl;
    cout << "Win/Loss Ratio: " << setprecision(2) << win_loss_ratio << endl;
    //  cout << "Total Ties: " << ties << endl;
    cout << "Times Chose Rock: " << Rock << endl;
    cout << "Times Chose Paper: " << Paper << endl;
    cout << "Times Chose Scissor: " << Scissor << endl;
}

void Player::SetStats(ifstream &inFS) {
    inFS >> name;
    inFS >> wins;
    inFS >> losses;
    inFS >> win_loss_ratio;
    inFS >> Rock;
    inFS >> Paper;
    inFS >> Scissor;
}
void Player::PrintAllStatsFile(ofstream &outFS) {
    outFS << name << endl;
    outFS << wins << endl;
    outFS << losses << endl;
    outFS << win_loss_ratio << endl;
    outFS << Rock << endl;
    outFS << Paper << endl;
    outFS << Scissor << endl;
}


void Player::Win_Loss_R() {
    win_loss_ratio = (1.0 * wins) / (1.0 * losses);
}
