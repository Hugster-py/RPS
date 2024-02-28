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


void NewPlayerMenu(Player &player1) {
    ifstream inFS;
    int choice = 0;
    while(choice != 1 || choice != 2) {
        cout << "1. Create New Player" << endl;
        cout << "2. Upload Previous Player" << endl;
        cout<<"Choice: ";
        cin>>choice;
        cout<<endl;
        if(choice == 1 || choice ==2){
            break;
        }
        if(choice != 1){
            if(choice !=2){
                cout<<"Invalid Choice. Try Again."<<endl;
            }
        }
    }
    if(choice == 1){
        cout<<"You chose to create a new player!"<<endl;
        cout<<"Please enter username: ";
        string name;
        cin>>name;
        player1.SetName(name);
    }
    if(choice == 2){
        cout<<"You chose to upload a previous save!"<<endl;
        cout<<"Please paste full path of save file!"<<endl;
        cout<<"File Name: ";
        string filename;
        cin>>filename;
        inFS.open(filename);
        if(!inFS.is_open()){
            cout<<"Error: File Not Found. Try again."<<endl;
        }
        cout<<endl;
        player1.SetStats(inFS);
        cout<<"1. Show Stats of Previous Save"<<endl;
        cout<<"2. Continue"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        if(choice == 1){
            player1.printAllStats();
        }
    }
}


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