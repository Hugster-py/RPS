// Created by Chase Hughes
// @Copyright CHughes 2024


#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "battle.h"

using namespace std;

// 1 - rock, 2 - paper, 3 - scissors, 0 - quit
void GameSequence(Player &player1, Player &computer) {
    int score;
    int roundsNum;
    int reverseCount = 0;
    int choice;
    History ScoreTracker;
    ScoreTracker = History();
    cout<<endl;
    cout << "Enter (Odd) Amount of Rounds: ";
    cin >> roundsNum;
    if (roundsNum % 2 == 0) {
        cout << "Choose odd number!" << endl;
        cout << "Enter Amount of Rounds: ";
        cin >> roundsNum;
    }
    cout<<endl;



    while (ScoreTracker.GetPlayerScore() != (roundsNum + 1) / 2 ||
           ScoreTracker.GetCompScore() != (roundsNum + 1) / 2) {

        //Round Menu
        cout << "Round " << reverseCount + 1 << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: "<<endl;
        cin >> choice;
        if (choice < 0 || choice > 3) {
            cout << "Invalid. Try again: ";
            cin >> choice;
        }
        //user quits
        if (choice == 0) {
            break;
        } else {
            score = Battle(player1, choice, computer);
        }


        if (score == 0) {
            ScoreTracker.SetCompScore();
            cout << "Computer wins round!" << endl;
        } else if (score == 1) {
            ScoreTracker.SetPlayerScore();
            cout << "Player wins round!" << endl;
        }
        else{
            cout << "It's a tie!" << endl;
        }

        //overall win monitoring
        if (ScoreTracker.GetPlayerScore() == (roundsNum + 1) / 2) {
            player1.SetWins();
            computer.SetLosses();
            cout<<endl;
            cout << "Player wins game!" << endl;
            break;
        }
        if (ScoreTracker.GetCompScore() == (roundsNum + 1) / 2) {
            player1.SetLosses();
            computer.SetWins();
            cout<<endl;
            cout << "Computer wins game!" << endl;
            break;
        }

        cout<<endl;
        //win stats to track through the game
        cout << player1.GetName()<<" - " << ScoreTracker.GetPlayerScore() << " | "<<computer.GetName()<<" - "
             << ScoreTracker.GetCompScore() << endl;

        reverseCount++;
    }
}


// rock = 1 || paper = 2 || scissor = 3
int Battle(Player &player1, int choice, Player &computer) {

    //random function
    int ComputerChoice =  1+rand()%9;
    if(ComputerChoice <=3 ){
        ComputerChoice = 1;
    }
    else if(ComputerChoice <= 6){
        ComputerChoice = 2;
    }
    else{
        ComputerChoice = 3;
    }

    //the long list of print statements:
    // player rock - comp paper
    if (choice == 1 && ComputerChoice == 2) {
        // comp wins
        player1.SetRock();
        computer.SetPaper();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Paper!" << endl;
        return 1;
    }
    // player rock - comp scissors
    if (choice == 1 && ComputerChoice == 3) {
        // player wins
        player1.SetRock();
        computer.SetScissor();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        return 0;
    }
    //player rock - comp rock
    if (choice == 1 && ComputerChoice == 1) {
        // tie
        player1.SetRock();
        computer.SetRock();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Rock!" << endl;
        return 2;
    }
    // player paper - comp rock
    if (choice == 2 && ComputerChoice == 1) {
        // player wins
        player1.SetPaper();
        computer.SetRock();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Rock!" << endl;
        return 0;
    }
    // player paper - comp scissors
    if (choice == 2 && ComputerChoice == 3) {
        // comp wins
        player1.SetPaper();
        computer.SetScissor();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        return 1;
    }
    // player paper - comp paper
    if (choice == 2 && ComputerChoice == 2) {
        // tie
        player1.SetPaper();
        computer.SetPaper();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Paper!" << endl;
        return 2;
    }
    // player scissor - comp rock
    if (choice == 3 && ComputerChoice == 1) {
        // comp wins
        player1.SetScissor();
        computer.SetRock();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Rock!" << endl;
        return 1;
    }
    // player scissors - comp paper
    if (choice == 3 && ComputerChoice == 2) {
        // player wins
        player1.SetScissor();
        computer.SetPaper();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Paper!" << endl;
        return 0;
    }
    // player scissors - comp scissors
    if (choice == 3 && ComputerChoice == 3) {
        player1.SetScissor();
        computer.SetScissor();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        return 2;
    }
}
