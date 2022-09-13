/*
Ramsha Bilal
Final project
file Clue.h
PC 
*/
#ifndef CLUE_H
#define CLUE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

class Clue
{
private:
	string m_clue;
	string m_answer;

public:
	Clue();
	
	void setClue(string clue);
	void setAnswer(string answer);
	void displayClue();
	void displayAnswer();

	string getClue();
	string getAnswer();

};

#endif
