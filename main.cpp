// Created by Chase Hughes Feb
//  @Copyright CHughes 2024


//TO ADD:
//  SIMPLE TEXT BOX UI OR TERMINAL
//  ADD ITEM AND THE WIN/LOSS CONDITIONS FOR IT
//  MORE IN DEPTH STATS (TOT ROUNDS WON, TOT ROUNDS LOST, ROCK WINS, ROCK LOSSES, TIES, ETC.

// TO DO:
//  CUSTOMIZABLE COMPUTER
//  REDO MENUS COMPLETELY
//      Plans for menus, turn the output into an int. Get rid of the nesting that I have now as it has been hard to work
//      on and change around.
//  MOVE LAST SAVE PLAYER TO MENU FUNCTION
//  ABILITY TO RENAME CHARACTER MID-GAME

// FIX ME:
//  PRINT STATEMENTS FOR BATTLE SEQUENCE
//    [ SOME NOT PRINTING CORRECTLY, MOSTLY WHEN COMP WINS.
//      PLAYER ROCK - COMP PAPER NOT PRINTING
//      PLAYER PAPER - COMP SCISSORS OCCASIONALLY NOT PRINTING
//      NOTICED THAT IF COMP WINS 2 TIMES IN ROW FOR PLAYER PAPER.
//      SAME THING FOR PLAYER SCISSORS ]
//   FIX MENU LOOPING
//          MAIN MENU
//          SAVE MENU
//   IF ERROR LOADING FILE, TRY AGAIN
//   LOOPING TO MAKE SURE CHARACTER NAME IS SET

#include "menu.h"
#include "player.h"
#include <iostream>
#include <stdexcept>


using namespace std;

int main() {
  cout << "Welcome to Rock Paper Scissors!" << endl;

  Player player1("temp");
  Player computer("Computer");

  NewPlayerMenu(player1);
  startMenu(player1, computer);

  //move to menu function
  cout << "Save Player? Press 1 for yes." << endl;
  cout << "Choice: ";
  int choice;
  cin >> choice;
  if (choice == 1) {
    SaveCharacter(player1);
  }
  cout<<endl;

  cout << "Thanks for playing!" << endl;

  return 0;
}