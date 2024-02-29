// Created by Chase Hughes
// @Copyright CHughes 2024

#ifndef MENU_H
#define MENU_H

#include "battle.h"
#include "player.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void NewPlayerMenu(Player &player1);
void startMenu(Player &player1, Player &computer);
void SaveCharacter(Player &player1);
void PlayerSetting(Player &player1, Player &computer);

#endif