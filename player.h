// Created by Chase Hughes Feb
// @Copyright CHughes 2024

#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
  Player(string name);
  void SetName(string name) { this->name = name; }
  string GetName() { return name; }
  void SetWins() { wins++; }
  int GetWins() { return wins; }
  void SetLosses() { losses++; }
  int GetLosses() { return losses; }
  void Win_Loss_R();
  void SetRock() { Rock++; }
  void SetPaper() { Paper++; }
  void SetScissor() { Scissor++; }
  void printAllStats();
  void SetStats(ifstream &inFS);
  void PrintAllStatsFile(ofstream &outFS);

private:
  string name;
  int wins;
  int losses;
  double win_loss_ratio;
  int Rock;
  int Paper;
  int Scissor;
};

#endif