// Created by Chase Hughes Feb
//  @Copyright CHughes 2024


//TO ADD:
//  SIMPLE TEXT BOX UI OR TERMINAL
//  ADD ITEM AND THE WIN/LOSS CONDITIONS FOR IT
//  MORE IN DEPTH STATS (TOT ROUNDS WON, TOT ROUNDS LOST, ROCK WINS, ROCK LOSSES, TIES, ETC.

// TO DO:
//  ADD IN OTHER THROW STATEMENTS IN MENUS
//  CUSTOMIZABLE COMPUTER
//  RETYPE NEW PLAYER MENU
//  REDO MENUS COMPLETELY
//      Plans for menus, turn the output into an int. Get rid of the nesting that I have now as it has been hard to work
//      on and change around.

// FIX ME:
//  PRINT STATEMENTS FOR BATTLE SEQUENCE
//    [ SOME NOT PRINTING CORRECTLY, MOSTLY WHEN COMP WINS.
//      PLAYER ROCK - COMP PAPER NOT PRINTING
//      PLAYER PAPER - COMP SCISSORS OCCASIONALLY NOT PRINTING
//      NOTICED THAT IF COMP WINS 2 TIMES IN ROW FOR PLAYER PAPER.
//      SAME THING FOR PLAYER SCISSORS ]
//   FIX MENU LOOPING
//      NUKE NEW PLAYER MENU AND REMAKE. NOT WORKING CORRECTLY.
//          ESPECIALLY THE NEW PLAYER MENU.
//   IF ERROR LOADING FILE, TRY AGAIN
//   LOOPING TO MAKE SURE CHARACTER NAME IS SET

#include "menu.h"
#include "player.h"
#include <iostream>
#include <stdexcept>


using namespace std;

int main() {
  cout << "Welcome!" << endl;
  Player player1("temp");
  try {
    NewPlayerMenu(player1);
  } catch (runtime_error) {
    cout << "Wrong File Key" << endl;
    return -1;
  }
  Player computer("Computer");
  startMenu(player1, computer);

  cout << "Save Player? Press 1 for yes." << endl;
  cout << "Choice: ";
  int choice;
  cin >> choice;
  if (choice == 1) {
    SaveCharacter(player1);
  }

  cout << "Thanks for playing!" << endl;

  return 0;
}