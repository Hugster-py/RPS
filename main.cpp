// Created by Chase Hughes Feb
//  @Copyright CHughes 2024

//EVENTUAL TO ADD:
//  SIMPLE TEXT BOX UI OR TERMINAL (MAYBE)
//  ADD ITEM AND THE WIN/LOSS CONDITIONS FOR IT
//      WILL HAVE TO SWITCH TO LINKED LIST AND REMAKE BATTLE
//  MORE IN DEPTH STATS (TOT ROUNDS WON, TOT ROUNDS LOST, ROCK WINS, ROCK LOSSES, TIES, ETC.

#include "menu.h"
#include "player.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Welcome to Rock Paper Scissors!" << endl;

  Player player1("temp");
  Player computer("Computer");

  NewPlayerMenu(player1);
  startMenu(player1, computer);
  SaveCharacter(player1);

  cout << "Thanks for playing!" << endl;

  return 0;
}