//
// Created by chase on 2/25/2024.
//
#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#include "battle.h"

// 1 - rock, 2 - paper, 3 - scissors, 0 - quit
void GameSequence(Player &player1, Player &computer) {
    int score;
    int roundsNum;
    int reverseCount = 0;
    History ScoreTracker;
    ScoreTracker = History();

    cout << "Enter (Odd) Amount of Rounds: ";
    cin >> roundsNum;
    if (roundsNum % 2 == 0) {
        cout << "Choose odd number!" << endl;
        cout << "Enter Amount of Rounds: ";
        cin >> roundsNum;
    }

    // TODO: Clean up spacing
    while (ScoreTracker.GetPlayerScore() != (roundsNum + 1) / 2 ||
           ScoreTracker.GetCompScore() != (roundsNum + 1) / 2) {
        score = 0;
        cout << "Round " << reverseCount + 1 << endl;
        int choice;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice < 0 || choice > 3) {
            cout << "Invalid. Try again: ";
            cin >> choice;
        }
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

        if (ScoreTracker.GetPlayerScore() == (roundsNum + 1) / 2) {
            player1.SetWins(0);
            computer.SetLosses(0);
            cout << "Player wins game!" << endl<<endl;
            break;
        }

        if (ScoreTracker.GetCompScore() == (roundsNum + 1) / 2) {
            player1.SetLosses(0);
            computer.SetWins(0);
            cout << "Computer wins game!" << endl<<endl;
            break;
        }

        cout << "Player - " << ScoreTracker.GetPlayerScore() << " | Computer - "
             << ScoreTracker.GetCompScore() << endl;

        reverseCount++;
    }
    ScoreTracker = {};
}


// rock = 1 || paper = 2 || scissor = 3
int Battle(Player &player1, int choice, Player &computer) {
    int CompWin = 7;
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

    // player rock - comp paper
    if (choice == 1 && ComputerChoice == 2) {
        // comp wins
        player1.SetRock();
        computer.SetPaper();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Paper!" << endl;
        CompWin = 1;
    }
    // player rock - comp scissors
    if (choice == 1 && ComputerChoice == 3) {
        // player wins
        player1.SetRock();
        computer.SetScissor();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        CompWin = 0;
    }
    //player rock - comp rock
    if (choice == 1 && ComputerChoice == 1) {
        // tie
        player1.SetRock();
        computer.SetRock();
        cout << player1.GetName() << " chose Rock!" << endl;
        cout << "The Computer chose Rock!" << endl;
        CompWin = 2;
    }
    // player paper - comp rock
    if (choice == 2 && ComputerChoice == 1) {
        // player wins
        player1.SetPaper();
        computer.SetRock();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Rock!" << endl;
        CompWin = 0;
    }
    // player paper - comp scissors
    if (choice == 2 && ComputerChoice == 3) {
        // comp wins
        player1.SetPaper();
        computer.SetScissor();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        CompWin = 1;
    }
    // player paper - comp paper
    if (choice == 2 && ComputerChoice == 2) {
        // tie
        player1.SetPaper();
        computer.SetPaper();
        cout << player1.GetName() << " chose Paper!" << endl;
        cout << "The Computer chose Paper!" << endl;
        CompWin = 2;
    }
    // player scissor - comp rock
    if (choice == 3 && ComputerChoice == 1) {
        // comp wins
        player1.SetScissor();
        computer.SetRock();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Rock!" << endl;
        CompWin = 1;
    }
    // player scissors - comp paper
    if (choice == 3 && ComputerChoice == 2) {
        // player wins
        player1.SetScissor();
        computer.SetPaper();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Paper!" << endl;
        CompWin = 0;
    }
    // player scissors - comp scissors
    if (choice == 3 && ComputerChoice == 3) {
        player1.SetScissor();
        computer.SetScissor();
        cout << player1.GetName() << " chose Scissors!" << endl;
        cout << "The Computer chose Scissors!" << endl;
        CompWin = 2;
    }

    // compWin = 1 then update stats accordingly (Computer has won)
    if (CompWin == 1) {
        return 1;
    } else if (CompWin == 0) {
        return 0;
    } else {
        cout << "It's a tie!" << endl;
        // computer.SetTie();
        // player1.SetTie(); WILL BE USED WHEN TRACKING INDIVIDUAL STATS
        return 2;
    }
}