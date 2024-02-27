//
// Created by chase on 2/25/2024.
//
#include "battle.h"
#include "player.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "menu.h"

using namespace std;

//NUKE AND FIX 
void NewPlayerMenu(Player &player1) {
    ifstream inFS;
    int b = 0;
  int choice;
  try{
    cout << "Player Menu:" << endl;
    cout << "1. Create New Player" << endl;
    cout << "2. Load Save File" << endl;
    cout << "Choice: ";
    cin >> choice;
    while (b == 0) {
      if(!isdigit(choice)){
        throw runtime_error("Wrong choice");
      }
        if (choice == 1) {
            b = 1;
            cout << "Create New Player!" << endl;
            cout << "Set Player Username: ";
            string name;
            cin >> name;
            player1.SetName(name);
            return;
        } else if (choice == 2) {
            b = 1;
            cout << "Type in name of the save file: ";
            string filename;
            cin >> filename;
            filename = filename + ".txt";
            inFS.open(filename);
            if (!inFS.is_open()) {
                cout << "Error: Could not open file." << endl;
            } else {
                string title;
                inFS >> title;
                if (title != "11011011-RPS") {
                    throw runtime_error("Wrong Save File Key");
                }
                player1.SetStats(inFS);
                inFS.close();
                cout << "Loaded:" << endl;
                player1.printAllStats();
                return;
            }
        } else {
            choice = {};
            cout << "Please try again, invalid choice." << endl;
            b = 0;
            cout << "Player Menu:" << endl;
            cout << "1. Create New Player" << endl;
            cout << "2. Load Save File" << endl;
            cout << "Choice: ";
            cin >> choice;
          }

    }
}
    catch(runtime_error){
      cout<<"Runtime Error: Input Digit!"<<endl;
      b=1;
    }
}
//NUKE AND FIX ^^ 

void startMenu(Player &player1, Player &computer) {
    int choice;

    cout << "MENU:" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;

    // player quits before ever playing a game
    if (choice == 2) {
        return;
    }
    while (choice != 3) {
        if (choice == 1) {
            GameSequence(player1, computer);
        }
        if (choice == 2) {
            player1.printAllStats();
            char answer;
            cout << "Show Computer Stats? Y or N" << endl;
            cin >> answer;
            if (answer == 'y' || answer == 'Y') {
                computer.printAllStats();
            }
        }

        cout << "MENU:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Show Current Stats" << endl;
        cout << "3. Quit" << endl;
        cout << "Menu Choice: ";
        cin >> choice;
    }
}


void SaveCharacter(Player &player1) {
    ofstream outFS;
    string filename = player1.GetName() + ".txt";
    outFS.open(filename);
    outFS << "11011011-RPS" << endl;
    player1.PrintAllStatsFile(outFS);
}