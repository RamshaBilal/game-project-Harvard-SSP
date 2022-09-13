/*
Ramsha Bilal
Final project
file player.h
PC 
*/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

class Player
{
private:
	string m_name;
	int m_score;
	string m_answer; 
	vector<string>m_guessList = {};

public:
	Player();
	Player(string name);

	//mutators
	void setName(string n);
	void setScore(int s);
	void updateScore(int scoreToAdd);
	void updateGuessList(string guessToAdd);

	//accessors
	string getName();
	int getScore();
	string getAnswer();
	
	void askForAnswer();
	void displayScore(int playerNum);
	void displayGuessList();
	void displayName();

};

#endif