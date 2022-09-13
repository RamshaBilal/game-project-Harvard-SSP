# game-project-Harvard-SSP
Final Project 
Ramsha Bilal

Game Structure: 
A Movie Trivia game that displays clues and prompts user to enter answer.
Two guesses per clue and scores are given accordingly.
Uses a Clue class to store clues along with answers as members.
Appropriate methods to get clue, display clue, get answer and display, etc.
Uses a player class to instantiate player objects.
Each player has a name, a list of guesses(vector), and score.
Appropriate methods in Player class are used to update score, get or set name, get answer, display members, etc. 
A function to convert strings to all lowercase letters so answer can be compared to stored answer without the comparison being case sensitive. 
Functions to perform player’s turns.
Function to end the game and display final statistics and winners.
Clues and answers read from a file and saved in a dynamic memory block(array) of Clues.
Get clues function to generate and return the pointer to the dynamic memory block.
Pointers used and updated to access the memory block locations.
Random number generation to randomly pick and clue from the array.

Instructions:
Two players.
Each enter their name.
One clue (randomly generated) for each player one by one.
Each player has two guesses.
If guessed correctly on first try – 10 points.
If guessed correctly on second try – 5 points.
If guessed incorrectly both times- 0 points.
Players can play up to 16 rounds.
At end of each round, players have a choice to continue or stop the game there and then.
At the end of game – final statistics for each player displayed and winner announced.
