/*
Ramsha Bilal
Final project
file PlayerClass.cpp 
PC
*/
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std; 

//default constructor
Player::Player()
{
	m_name = " ";
	m_score = 0; 
}

//single parameter constructor
Player::Player(string name)
{
	m_name = name;
	m_score = 0; 
}

//mutators below:
void Player::setName(string n)
{
	m_name = n;
}

void Player::setScore(int s)
{
	m_score = s;
}

void Player::updateScore(int scoreToAdd)
{
	m_score += scoreToAdd; 
}

void Player::updateGuessList(string guessToAdd)
{
	m_guessList.push_back(guessToAdd); 
}

//accessors below:
string Player::getName()
{
	return m_name;
}

int Player::getScore()
{
	return m_score;
}

string Player::getAnswer()
{
	return m_answer;
}

//asks user to enter answer, takes the answer and pushes it onto the list of guesses 
void Player::askForAnswer()
{
	cout << "\nPlease enter your answer: " << endl; 
	getline(cin, m_answer);
	m_guessList.push_back(m_answer);
}

//displays scores
void Player::displayScore(int playerNum)
{
	cout << "Score for Player " << playerNum << ": " << m_score << endl;
}

//displays the list of guesses made by player so far
void Player::displayGuessList()
{
	cout << "Guesses made so far: " << endl;
	for (string i : m_guessList)
		cout << i << endl; 
}

//displays name
void Player::displayName()
{
	cout << m_name;
}
