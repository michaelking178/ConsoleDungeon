#pragma once

#include <iostream>
#include <conio.h>
#include <array>

void StartNewGame();
void DrawBoard();
void GetKeyPress();
void CheckPosition();

int size;
std::string player;
std::string key;
std::string door;
std::string incidentalMessage;
std::array<int, 2> playerPos{ 2, 2 };
std::array<int, 2> keyPos{ 4, 6 };
std::array<int, 2> doorPos{ 0, 0 };
std::array<int, 2> winPos{ 0, 0 };
bool isGameOver;
bool hasKey;