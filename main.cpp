/*
Ramsha Bilal
Final project
file main.cpp 
bilal_week7_fp
PC
*/
#include "Player.h"
#include "Clue.h"
#include"Header.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

//some global variables and constant
bool debugGame = false;
vector<int> cluesUsed;
const int SIZE = 16; 

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	game(); 
	return 0; 
}

//main code for the flow of the game: calls player's turns, displays scores
void game()
{
	string player1Name;
	Clue* cluePointer, *start;
	int response = 0;

	cout << "Welcome to Movie Trivia!" << endl
		<< "It's time to test your knowledge of movies." << endl;
	cout << "Would you like to debug the game? Press 1 for yes, 0 for no."
		<< endl;
	cin >> response;
	if (response == 1)
		debugGame = true;

	cout << "Player 1, please enter your first name: ";
	cin >> player1Name;

	Player player1;
	player1.setName(player1Name);
	cin.ignore();

	string player2Name;
	cout << "Player 2, please enter your first name: ";
	cin >> player2Name;

	Player player2;
    player2.setName(player2Name);
	cin.ignore();

	cluePointer = getClues();
	start = cluePointer;

	if (debugGame == true) 
	{
		cout << "Displaying Clues and Answers: " << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cluePointer->displayClue();
			cluePointer->displayAnswer();
			cluePointer++;
		}
		cout << endl;
		cluePointer = start;
	}
	
	int count = 0;
	bool stop = false; 
	do
	{
	//player1 turn
		if (count != 0)
			cin.ignore();

		player1Turn(player1, cluePointer);
		player1.displayScore(1);
		player1.displayGuessList(); 
		
     //player 2 turn

		player2Turn(player2, cluePointer);
		player2.displayScore(2);
		player2.displayGuessList();

		count++;

		int userResponse = 0;
		cout << "Would you like to stop the game? Press 1 for yes, 0 for no." << endl;
		cin >> userResponse;
		if (userResponse == 1)
			stop = true;

	} while ((count < SIZE) && (stop == false));
	endgame(player1, player2);
	
	cluePointer = start;
	delete[] cluePointer;
}

//reads clues and answers from a file into dynamically allocated memory and returns pointer to the memory block
Clue* getClues()
{
	string fileLine;
	Clue* clues, *startArray;
	clues = new Clue[SIZE];
	startArray = clues; 

	ifstream inFile("Text.txt");
	if (inFile.fail())
		cout << "Error. File access failed." << endl;

	while (!inFile.eof())
	{
		getline(inFile, fileLine);
		if (fileLine.substr(0, 1) == "C")
		{
			clues->setClue(fileLine);
			clues++;
		}
	}
	clues = startArray; 
	
	inFile.close();

	ifstream readFile("Text.txt");
	while (!readFile.eof())
	{
		getline(readFile, fileLine);
		if (fileLine.substr(0, 1) == "A")
		{
			clues->setAnswer(fileLine);
			clues++;
		}
	}
	clues = startArray;
	readFile.close();

	return clues; 
}

//used to convert strings to all lowercase letters before comparison
void convertToLower(string& word)
{
	transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {return tolower(c); });
}

//player turn - get a player argument and uses it to display, mutate, or access data members
void player1Turn(Player& player1, Clue *cluePointer) 
{
	string ans, userAns;
	bool stopLoop = true;
	int randNum;
	do 
	{
		randNum = rand() % 16;

		for (int i : cluesUsed)
		{
			if (randNum == i)
			{
				stopLoop = false;
			}
		}
	} while (stopLoop == false);

	cluesUsed.push_back(randNum); 
	player1.displayName();
	cout << ", here's your clue" << endl << cluePointer[randNum].getClue();

	player1.askForAnswer();

	ans = cluePointer[randNum].getAnswer();
	convertToLower(ans);

	userAns = player1.getAnswer();
	convertToLower(userAns);
	
	if (debugGame == true)
	{
		cout << "Answer is: " << ans << endl;
		cout << "User entered: " << userAns << endl;
	}

	if (userAns == ans)
	{
		cout <<endl<< "Correct! You get 10 points." << endl;
		player1.updateScore(10);
	}
	else
	{
		cout << "Incorrect. You have one more try." << endl;
		player1.askForAnswer();
		
		userAns = player1.getAnswer();
		convertToLower(userAns);

		if (debugGame == true)
		{
			cout << "Answer is: " << ans << endl;
			cout << "User entered: " << userAns << endl;
		}

		if (userAns == ans)
		{
			cout << "Correct! You get 05 points." << endl;
			player1.updateScore(05);
		}
		else
			cout << "Incorrect. You get 0 points. Correct answer is " << ans << endl;
	}
	cout << endl;
}

//player turns - get a player argument and uses it to display, mutate, or access data members
void player2Turn(Player& player2, Clue* cluePointer)
{
	string ans, userAns;
	bool stopLoop = true;
	int randNum;
	do
	{
		randNum = rand() % 16;

		for (int i : cluesUsed)
		{
			if (randNum == i)
			{
				stopLoop = false;
			}
		}
			
	} while (stopLoop == false);

	cluesUsed.push_back(randNum);
	player2.displayName();
	cout << ", here's your clue" << endl
		<< cluePointer[randNum].getClue();

	player2.askForAnswer();

	ans = cluePointer[randNum].getAnswer();
	convertToLower(ans);

	userAns = player2.getAnswer();
	convertToLower(userAns);
	
	if (debugGame == true)
	{
		cout << "Answer is: " << ans << endl;
		cout << "User entered: " << userAns << endl;
	}

	if (userAns == ans)
	{
		cout << "Correct! You get 10 points." << endl;
		player2.updateScore(10);
	}
	else
	{
		cout << "Incorrect answer. You have one more try." << endl;
		player2.askForAnswer();

		userAns = player2.getAnswer();
		convertToLower(userAns);

		if (debugGame==true)
		{
			cout << "Answer is: " << ans << endl;
			cout << "User entered: " << userAns << endl;
		}

		if (userAns == ans)
		{
			cout << endl << "Correct! You get 05 points." << endl;
			player2.updateScore(05);
		}
		else
			cout << "Incorrect. You get 0 points. Correct answer was: " << ans << endl;
	}
	cout << endl;
}

//after player turns - used to present final scores and announce winner
void endgame(Player playerOne, Player playerTwo)
{
	cout << endl <<"Game over"
		<< endl
		<< "Score for player 1, " << playerOne.getName() << ": " << playerOne.getScore() << endl
	 << "Score for player 2, " << playerTwo.getName() << ": " << playerTwo.getScore() << endl;
	if (playerOne.getScore() > playerTwo.getScore())
		cout << playerOne.getName() << " wins!!!" << endl;
	else if (playerOne.getScore() < playerTwo.getScore())
		cout << playerTwo.getName() << " wins!!!" << endl;
	else
		cout << "It is a tie!!!" << endl; 
}