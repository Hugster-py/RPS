// Created by Chase Hughes
// @Copyright CHughes 2024

#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GameSequence(Player &player1, Player &computer);
int Battle(Player &player1, int choice, Player &computer);



class History {
public:
  History(){CompScore = 0, PlayerScore = 0;}
  void SetCompScore() { CompScore++; }
  void SetPlayerScore() { PlayerScore++; }
  int GetCompScore() { return CompScore; }
  int GetPlayerScore() { return PlayerScore; }

private:
  int CompScore;
  int PlayerScore;
};



#endif
