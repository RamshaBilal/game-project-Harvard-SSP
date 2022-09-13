/*
Ramsha Bilal
Final Project
file Header.h
bilal_week7_fp
PC 
*/
#ifndef HEADER_H
#define HEADER_H
void player1Turn(Player& player1, Clue* cluePointer);
void player2Turn(Player& player2, Clue* cluePointer);
void convertToLower(string& word);
void endgame(const Player playerOne, const Player playerTwo);
Clue* getClues();
void game();
#endif
