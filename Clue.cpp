/*
Ramsha Bilal
Final project
file Clue.cpp 
PC
*/
#include "Clue.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

//constructor
Clue::Clue() 
{}

//mutators:
void Clue::setClue(string clue)
{
	m_clue = clue;
}

void Clue::setAnswer(string answer)
{
	m_answer = answer; 
}

//display methods:
void Clue::displayClue()
{
	cout << m_clue << endl;
}

void Clue::displayAnswer()
{
	cout << m_answer << endl;
}

//mutators:
//removes the "C: " from clue and saves in m_clue. returns m_clue
string Clue::getClue()
{
	string clue;
	for (int i = 0; i < m_clue.length(); i++)
	{ 
		if (!(i == 0 || i == 1 || i == 2))
			clue = clue + m_clue.substr(i, 1);
	}
	m_clue = clue;

	return m_clue;
}

//removes the "A: " from answer and saves in m_answer. returns m_answer
string Clue::getAnswer()
{
	string answerEdited;
	for (int i = 0; i < m_answer.length(); i++)
	{
		if (!(i == 0 || i == 1 || i == 2))
			answerEdited = answerEdited + m_answer.substr(i, 1);
	}
	m_answer = answerEdited;
	return m_answer;
}


