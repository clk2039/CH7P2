/*
File name: CH7P2.cpp
Github URL:
Programmer: Kit Miller
Date: December 2025
Requirements: Write a modular procedural program that displays the contents of the Teams.txt file
on the screen and prompts the user to enter the name of one of the teams.
The program should then display the number of times that team has won the World Series in the
time period from 1903 to 2012, note that the World Series was not played in 1904 and 1994.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function prototypes
void getTeams(const string& filename, vector<string>& data);
int findWinner(const string& teamName, const vector<string>& winners);
void displayTeams(const vector<string>& teams);

int main()
{
	vector<string> teams;
	vector<string> winners;
	string teamsFile = "Teams.txt";
	string winnersFile = "WorldSeriesWinners.txt";

	//Read the files into vectors
	getTeams(teamsFile, teams);
	getTeams(winnersFile, winners);

	//Display all the teams
	displayTeams(teams);

	//Sentinel controlled loop to get user input
	cout << "Which team's World Series wins would you like to know about? (Enter 'exit' to quit): ";
	string userTeam;
	getline(cin, userTeam);
	while (userTeam != "exit")
	{
		int wins = findWinner(userTeam, winners);
		cout << userTeam << " has won the World Series " << wins << " times from 1903 to 2012." << endl;
		cout << "Which team's World Series wins would you like to know about? (Enter 'exit' to quit): ";
		getline(cin, userTeam);
	}
	return 0;

}

/*
Function: getTeams
Purpose: To read team names from a file into a vector
Parameters: filename - the name of the file to read from
			data - the vector to store the team names
Returns: void
Preconditions: The file exists and is readable
Postconditions: The vector holds the team names from the file
*/
void getTeams(const string& filename, vector<string>& data)
{
	ifstream inputFile(filename);

	if (!inputFile)
	{
		cout << "Error opening file: " << filename << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line))
	{
		data.push_back(line);
	}
	inputFile.close();
}

/*
Function: findWinner
Purpose: To determine how many times a team has won the World Series
Parameters: teamName - the name of the team to search for
			winners - the vector containing the list of World Series winners
Returns: int - the number of times the team has won
Preconditions: The winner vector has valid data
Postconditions: The number of wins is returned
*/
int findWinner(const string& teamName, const vector<string>& winners)
{
	int winCount = 0;

	//Range-based for loop to count wins
	for (const string& winner : winners)
	{
		if (winner == teamName)
		{
			winCount++;
		}
	}
	return winCount;
}

/*
Function: displayTeams
Purpose: To display the list of teams
Parameters: teams - the vector containing the team names
Returns: void
Preconditions: The teams vector has valid data
Postconditions: The team names are displayed on the screen
*/
void displayTeams(const vector<string>& teams)
{
	cout << "Teams:" << endl;
	for (const string& team : teams)
	{
		cout << team << endl;
	}
}