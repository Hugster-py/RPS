// Created by Chase Hughes
// @Copyright CHughes 2024

#include "battle.h"
#include "player.h"
#include <fstream>
#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

void PlayerCreation(Player&player1){
    cout << "Please enter username: ";
    string name;
    cin >> name;
    player1.SetName(name);
    cout << endl;
}

void FilePlayerCreation(Player&player1){
    ifstream inFS;
    int choice;
    cout << "Please paste full path of save file!" << endl;
    cout << "File Name: ";
    string filename;
    cin >> filename;
    inFS.open(filename);
    int b = 1;
    if (!inFS.is_open()) {
        cout << "Error: File Not Found. Try again." << endl;
        cout << endl;
        NewPlayerMenu(player1);
        b = 0;
    }
    cout << endl;
    if (b == 1) {
        player1.SetStats(inFS);
        cout << "1. Show Stats of Previous Save" << endl;
        cout << "2. Continue" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 1) {
            player1.printAllStats();
            cout << endl;
        }
    }
}


void NewPlayerMenu(Player &player1) {
    int choice;
    while(choice != 1 || choice != 2) {
        cout << "1. Create New Player" << endl;
        cout << "2. Upload Previous Player" << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << endl;
        switch(choice) {
            case 1:
                cout << "You chose to create a new player!" << endl;
                PlayerCreation(player1);
            case 2:
                cout << "You chose to upload a previous save!" << endl;
                FilePlayerCreation(player1);
            default:
                cout<<"Error, please try again."<<endl;
        }
    }
    }



void startMenu(Player &player1, Player &computer) {
    int choice;

    cout << "MAIN MENU:" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;

    // player quits before ever playing a game
    if (choice == 2) {
        return;
    }

    while (choice != 0) {
        if (choice == 1) {
            GameSequence(player1, computer);
        }
        if (choice == 2) {
            player1.printAllStats();
            char answer;
            cout << "Show" <<computer.GetName()<<" Stats? Y or N" << endl;
            cin >> answer;
            if (answer == 'y' || answer == 'Y') {
                computer.printAllStats();
            }
        }
        if(choice == 3){
            PlayerSetting(player1, computer);
        }
        cout<<endl;
        cout << "MENU:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Show Current Stats" << endl;
        cout << "3. Player Settings" <<endl;
        cout << "0. Quit" << endl;
        cout << "Menu Choice: ";
        cin >> choice;
        cout<<endl;
    }
}


void PlayerSetting(Player &player1, Player &computer){
    string newName;
    int choice;
    char confirm;

    cout<<"Player Settings Menu"<<endl;
    cout<<"1. Change Player Name"<<endl;
    cout<<"2. Clear All Player Stats"<<endl;
    cout<<"3. Change Computer Name"<<endl;
    cout<<"0. Back to Main Menu"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    cout<<endl;

    if(choice == 1){
        cout<<"You Chose Change Player Name:"<<endl;
        cout<<"Please input new name:";
        cin>>newName;
        cout<<endl;
        player1.SetName(newName);
    }
    if(choice == 2){
        cout<<"You Chose to Clear All Stats:"<<endl;
        cout<<"Confirm? Y for Yes"<<endl;
        cin>>confirm;

        if(confirm == 'N' || confirm == 'n'){
            return;
        }
        else{
            player1.ClearStats();
            cout<<"Stats cleared!"<<endl;
            return;
        }

    }
    if(choice == 3){
        cout<<"You Chose Change Computer Name:"<<endl;
        cout<<"Please input new name:";
        cin>>newName;
        cout<<endl;
        computer.SetName(newName);
    }
}

void SaveCharacter(Player &player1) {
    int choice;
    ofstream outFS;
    cout << "Save Player? Press 1 for yes." << endl;
    cout << "Choice: ";
    cin >> choice;
    cout<<endl;
    if (choice == 1) {
        string filename = player1.GetName() + ".txt";
        outFS.open(filename);
        player1.PrintAllStatsFile(outFS);
        cout<<"Character Saved!"<<endl;
    }
}
