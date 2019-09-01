#include <iostream>
#include "TicTacToeUtilities.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "main.h"
#include <random>
#include <stdlib.h> 
#include <windows.h>

using namespace std;

auto playerOneTime = 0;
auto playerTwoTime = 0;

char letters[] = "RTYFGHVBN";

char location;

string playerOneName;
string playerTwoName;

string CPU = "CPU";

TicTacToePositions northwest;
TicTacToePositions north;
TicTacToePositions northeast;

TicTacToePositions west;
TicTacToePositions center;
TicTacToePositions east;

TicTacToePositions southwest;
TicTacToePositions south;
TicTacToePositions southeast;


ifstream readplayerOneFile;
ifstream readplayerTwoFile;

ofstream writeplayerOneFile;
ofstream writeplayerTwoFile;

int playerOneWins;
int playerOneLosses;
int playerOneDraws;

int playerTwoWins;
int playerTwoLosses;
int playerTwoDraws;

//The function at the start that takes in players names
void intro()
{
	
	system("CLS");
	
	cout << "Enter the name of player one. Type 'CPU' for computer to play" << endl;
	cin >> playerOneName;
	
	//make file for player one
	readplayerOneFile.open(playerOneName + ".txt");
	readplayerOneFile >> playerOneWins;
	readplayerOneFile >> playerOneLosses;
	readplayerOneFile >> playerOneDraws;
	readplayerOneFile.close();

	cout << endl << playerOneName << " has " << playerOneWins << " wins, " << playerOneLosses << " losses and " << playerOneDraws << " ties so far!"<<endl;
	system("pause");
	
	
	system("CLS");

	cout << "Enter the name of player two. Type 'CPU' for computer to play" << endl;
	cin >> playerTwoName;

	//make file for player two
	readplayerTwoFile.open(playerTwoName + ".txt");
	readplayerTwoFile >> playerTwoWins;
	readplayerTwoFile >> playerTwoLosses;
	readplayerTwoFile >> playerTwoDraws;
	readplayerTwoFile.close();
	
	cout << endl << playerTwoName << " has " << playerTwoWins << " wins, " << playerTwoLosses << " losses and " << playerTwoDraws << " ties so far!"<<endl;
	system("pause");

	

	system("CLS");
	cout <<"Players have 10 seconds to make their decisions for the entire game <3" << endl;
	system("Pause");
}

//drawing the bits of the board
void renderBoard()
{
	system("CLS");

	cout << northwest.getLetter() << " | " << north.getLetter() << " | " << northeast.getLetter() << endl << west.getLetter() << " | " << center.getLetter() << " | " << east.getLetter() << endl << southwest.getLetter() << " | " << south.getLetter() << " | " << southeast.getLetter() << endl;
}

//writing to a file that player one won
void writePlayerOneWin()
{
	writeplayerTwoFile.open(playerTwoName + ".txt");
	writeplayerTwoFile << playerTwoWins + 0 << endl;
	writeplayerTwoFile << playerTwoLosses + 1 << endl;
	writeplayerTwoFile << playerTwoDraws + 0 << endl;
	writeplayerTwoFile.close();

	writeplayerOneFile.open(playerOneName + ".txt");
	writeplayerOneFile << playerOneWins + 1 << endl;
	writeplayerOneFile << playerOneLosses + 0 << endl;
	writeplayerOneFile << playerOneDraws + 0 << endl;
	writeplayerOneFile.close();
}

//writing to a file that player two one
void writePlayerTwoWin()
{
	writeplayerTwoFile.open(playerTwoName + ".txt");
	writeplayerTwoFile << playerTwoWins + 1 << endl;
	writeplayerTwoFile << playerTwoLosses + 0 << endl;
	writeplayerTwoFile << playerTwoDraws + 0 << endl;
	writeplayerTwoFile.close();

	writeplayerOneFile.open(playerOneName + ".txt");
	writeplayerOneFile << playerOneWins + 0 << endl;
	writeplayerOneFile << playerOneLosses + 1 << endl;
	writeplayerOneFile << playerOneDraws + 0 << endl;
	writeplayerOneFile.close();
}

//checking if player one won
void checkPlayerOneWin()
{
	//xxx
	//
	//
	if ((northwest.getLetter() == north.getLetter() && north.getLetter() == northeast.getLetter() && northeast.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";

		writePlayerOneWin();
		
		system("pause");
		std::exit(0);
	}
	//
	//xxx
	//
	if ((west.getLetter() == center.getLetter() && center.getLetter() == east.getLetter() && east.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	//
	//
	//xxx
	if ((southwest.getLetter() == south.getLetter() && south.getLetter() == southeast.getLetter() && southeast.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	//x
	//x
	//x
	if ((northwest.getLetter() == west.getLetter() && west.getLetter() == southwest.getLetter() && southwest.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	// x
	// x
	// x
	if ((north.getLetter() == center.getLetter() && center.getLetter() == south.getLetter() && south.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	//  x
	//  x
	//  x
	if ((northeast.getLetter() == east.getLetter() && east.getLetter() == southeast.getLetter() && southeast.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	//x
	// x
	//  x
	if ((northwest.getLetter() == center.getLetter() && center.getLetter() == southeast.getLetter() && southeast.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
	//  x
	// x
	//x
	if ((southwest.getLetter() == center.getLetter() && center.getLetter() == northeast.getLetter() && northeast.getLetter() == 'X'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerOneWin();
		system("pause");
		std::exit(0);
	}
}

//checking if player two won
void checkPlayerTwoWin()
{
	//xxx
	//
	//
	if ((northwest.getLetter() == north.getLetter() && north.getLetter() == northeast.getLetter() && northeast.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();
		system("pause");
		std::exit(0);
	}
	//
	//xxx
	//
	if ((west.getLetter() == center.getLetter() && center.getLetter() == east.getLetter() && east.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	//
	//
	//xxx
	if ((southwest.getLetter() == south.getLetter() && south.getLetter() == southeast.getLetter() && southeast.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	//x
	//x
	//x
	if ((northwest.getLetter() == west.getLetter() && west.getLetter() == southwest.getLetter() && southwest.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	// x
	// x
	// x
	if ((north.getLetter() == center.getLetter() && center.getLetter() == south.getLetter() && south.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	//  x
	//  x
	//  x
	if ((northeast.getLetter() == east.getLetter() && east.getLetter() == southeast.getLetter() && southeast.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	//x
	// x
	//  x
	if ((northwest.getLetter() == center.getLetter() && center.getLetter() == southeast.getLetter() && southeast.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
	//  x
	// x
	//x
	if ((southwest.getLetter() == center.getLetter() && center.getLetter() == northeast.getLetter() && northeast.getLetter() == 'O'))
	{
		renderBoard();

		cout << "Winner!";
		writePlayerTwoWin();

		system("pause");
		std::exit(0);
	}
}

//the function to handle the cpu
void cpuBestMove()
{
	//initialzing random function
	srand(time(NULL));
	location = letters[rand() % 8];

	//simulates the CPU thinking
	Sleep(1000);


	//I tried to come up with all the possible board confiurations for the cpu to react to
	//It will obviously check for them in the order I have written here
	//I have them ordered in how I wrote them up on a spread sheet

	//Y
	if ((northwest.getLetter() == north.getLetter() && (north.getLetter() == 'X'))||(northwest.getLetter() == north.getLetter() && north.getLetter()== 'O'))
	{
		if (northeast.getLetter() != 'X' && northeast.getLetter() != 'O')
		{
			location = 'Y';
		}
	}
	else if ((southwest.getLetter() == center.getLetter() && center.getLetter() == 'X') || (southwest.getLetter() == center.getLetter() && center.getLetter() == 'O'))
	{
		if (northeast.getLetter() != 'X' && northeast.getLetter() != 'O')
		{
			location = 'Y';
		}
	}

	//T
	else if ((south.getLetter() == center.getLetter() && center.getLetter() == 'X') || (south.getLetter() == center.getLetter() && center.getLetter() == 'O'))
	{
		if (north.getLetter() != 'X' && north.getLetter() != 'O')
		{
			location = 'T';
		}
	}
	else if ((northwest.getLetter() == northeast.getLetter() && northeast.getLetter() == 'X') || (northwest.getLetter() == northeast.getLetter() && northeast.getLetter() == 'O'))
	{
		if (north.getLetter() != 'X' && north.getLetter() != 'O')
		{
			location = 'T';
		}
	}

	//R
	else if ((north.getLetter() == northeast.getLetter() && northeast.getLetter() == 'X') || (north.getLetter() == northeast.getLetter() && northeast.getLetter() == 'O'))
	{
		if (northwest.getLetter() != 'X' && northwest.getLetter() != 'O')
		{
			location = 'R';
		}
	}
	else if ((southwest.getLetter() == west.getLetter() && west.getLetter() == 'X') || (southwest.getLetter() == west.getLetter() && west.getLetter() == 'O'))
	{
		if (northwest.getLetter() != 'X' && northwest.getLetter() != 'O')
		{
			location = 'R';
		}
	}

	//H
	else if ((northeast.getLetter() == southeast.getLetter() && southeast.getLetter() == 'X') || (northeast.getLetter() == southeast.getLetter() && southeast.getLetter() == 'O'))
	{
		if (east.getLetter() != 'X' && east.getLetter() != 'O')
		{
			location = 'H';
		}
	}

	//G
	else if ((northwest.getLetter() == southeast.getLetter() && southeast.getLetter() == 'X') || (northwest.getLetter() == southeast.getLetter() && southeast.getLetter() == 'O'))
	{
		if (center.getLetter() != 'X' && center.getLetter() != 'O')
		{
			location = 'G';
		}
	}
	else if ((north.getLetter() == south.getLetter() && south.getLetter() == 'X') || (north.getLetter() == south.getLetter() && south.getLetter() == 'O'))
	{
		if (center.getLetter() != 'X' && center.getLetter() != 'O')
		{
			location = 'G';
		}
	}
	else if ((southwest.getLetter() == northeast.getLetter() && northeast.getLetter() == 'X') || (southwest.getLetter() == northeast.getLetter() && northeast.getLetter() == 'O'))
	{
		if (center.getLetter() != 'X' && center.getLetter() != 'O')
		{
			location = 'G';
		}
	}
	else if ((west.getLetter() == east.getLetter() && east.getLetter() == 'X') || (west.getLetter() == east.getLetter() && east.getLetter() == 'O'))
	{
		if (center.getLetter() != 'X' && center.getLetter() != 'O')
		{
			location = 'G';
		}
	}

	//F
	else if ((northwest.getLetter() == southwest.getLetter() && southwest.getLetter() == 'X') || (northwest.getLetter() == southwest.getLetter() && southwest.getLetter() == 'O'))
	{
		if (west.getLetter() != 'X' && west.getLetter() != 'O')
		{
			location = 'F';
		}
	}

	//N
	else if ((northwest.getLetter() == center.getLetter() && center.getLetter() == 'X') || (northwest.getLetter() == center.getLetter() && center.getLetter() == 'O'))
	{
		if (southeast.getLetter() != 'X' && southeast.getLetter() != 'O')
		{
			location = 'N';
		}
	}
	else if ((northeast.getLetter() == east.getLetter() && east.getLetter() == 'X') || (northeast.getLetter() == east.getLetter() && east.getLetter() == 'O'))
	{
		if (southeast.getLetter() != 'X' && southeast.getLetter() != 'O')
		{
			location = 'N';
		}
	}
	else if ((southwest.getLetter() == south.getLetter() && south.getLetter() == 'X') || (southwest.getLetter() == south.getLetter() && south.getLetter() == 'O'))
	{
		if (southeast.getLetter() != 'X' && southeast.getLetter() != 'O')
		{
			location = 'N';
		}
	}

	//B
	else if ((north.getLetter() == center.getLetter() && center.getLetter() == 'X') || (north.getLetter() == center.getLetter() && center.getLetter() == 'O'))
	{
		if (south.getLetter() != 'X' && south.getLetter() != 'O')
		{
			location = 'B';
		}
	}
	
	//V
	else if ((northwest.getLetter() == west.getLetter() && west.getLetter() == 'X') || (northwest.getLetter() == west.getLetter() && west.getLetter() == 'O'))
	{
		if (southwest.getLetter() != 'X' && southwest.getLetter() != 'O')
		{
			location = 'V';
		}
	}
	else if ((northeast.getLetter() == center.getLetter() && center.getLetter() == 'X') || (northeast.getLetter() == center.getLetter() && center.getLetter() == 'O'))
	{
		if (southwest.getLetter() != 'X' && southwest.getLetter() != 'O')
		{
			location = 'V';
		}
	}
	
	else
	{
		location = letters[rand() % 9];
	}

	//testing location of cpu input
	cout << endl << location << endl;
}

//player one's turn function
void playerOneTurn()
{
	auto startplayerone = chrono::steady_clock::now();
	renderBoard();

	cout << endl << "Where will " << playerOneName << " place an 'X'?";

	if (playerOneName == CPU)
	{
		cpuBestMove();
	}
	else
	{
		cin >> location;
	}


	switch (location)
	{
	case 'R':
		if (northwest.getLetter() != 'O')
		{
			northwest.setLetter('X');
		}
		else if (northwest.getLetter() != 'R')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'r':
		if (northwest.getLetter() != 'O')
		{
			northwest.setLetter('X');
		}
		else if (northwest.getLetter() != 'r')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'T':
		if (north.getLetter() != 'O')
		{
			north.setLetter('X');
		}
		else if (north.getLetter() != 'T')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 't':
		if (north.getLetter() != 'O')
		{
			north.setLetter('X');
		}
		else if (north.getLetter() != 't')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'Y':
		if (northeast.getLetter() != 'O')
		{
			northeast.setLetter('X');
		}
		else if (northeast.getLetter() != 'Y')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'y':
		if (northeast.getLetter() != 'O')
		{
			northeast.setLetter('X');
		}
		else if (northeast.getLetter() != 'y')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'F':
		if (west.getLetter() != 'O')
		{
			west.setLetter('X');
		}
		else if (west.getLetter() != 'F')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'f':
		if (west.getLetter() != 'O')
		{
			west.setLetter('X');
		}
		else if (west.getLetter() != 'f')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'G':
		if (center.getLetter() != 'O')
		{
			center.setLetter('X');
		}
		else if (center.getLetter() != 'G')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'g':
		if (center.getLetter() != 'O')
		{
			center.setLetter('X');
		}
		else if (center.getLetter() != 'g')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}		break;

	case 'H':
		if (east.getLetter() != 'O')
		{
			east.setLetter('X');
		}
		else if (east.getLetter() != 'H')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'h':
		if (east.getLetter() != 'O')
		{
			east.setLetter('X');
		}
		else if (east.getLetter() != 'h')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}		
		break;

	case 'V':
		if (southwest.getLetter() != 'O')
		{
			southwest.setLetter('X');
		}
		else if (southwest.getLetter() != 'V')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}		
		break;

	case 'v':
		if (southwest.getLetter() != 'O')
		{
			southwest.setLetter('X');
		}
		else if (southwest.getLetter() != 'v')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}		
		break;

	case 'B':
		if (south.getLetter() != 'O')
		{
			south.setLetter('X');
		}
		else if (south.getLetter() != 'v')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}			
		break;

	case 'b':
		if (south.getLetter() != 'O')
		{
			south.setLetter('X');
		}
		else if (south.getLetter() != 'b')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}
		break;

	case 'N':
		if (southeast.getLetter() != 'O')
		{
			southeast.setLetter('X');
		}
		else if (southeast.getLetter() != 'N')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}		
		break;

	case 'n':
		if (southeast.getLetter() != 'O')
		{
			southeast.setLetter('X');
		}
		else if (southeast.getLetter() != 'n')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerOneTurn();
		}	
		break;

	default: cout << endl << "You didnt select anything!";
		playerOneTurn();
	}

	//Check for win or draw conditions

	checkPlayerOneWin();

	//checkDraw();

	auto endplayerone = chrono::steady_clock::now();
	auto diffplayerone = endplayerone - startplayerone;
	playerOneTime = playerOneTime + chrono::duration <double, milli>(diffplayerone).count();
	system("pause");
	if (playerOneTime > 10000)
	{
		cout << playerOneName << "Has run out of time";
		//add one loss to player 1 record
		//add one win to player 2 record
		system("pause");
		std::exit(0);
	}
}

//player two's turn function
void playerTwoTurn()
{
	auto startplayertwo = chrono::steady_clock::now();

	renderBoard();

	cout << endl << "Where will " << playerTwoName << " place an 'O'?";

	if (playerTwoName == CPU)
	{
		cpuBestMove();
	}
	else
	{
		cin >> location;
	}


	switch (location)
	{
	case 'R':
		if (northwest.getLetter() != 'X')
		{
			northwest.setLetter('O');
		}
		else if (northwest.getLetter() != 'R')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'r':
		if (northwest.getLetter() != 'X')
		{
			northwest.setLetter('O');
		}
		else if (northwest.getLetter() != 'r')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'T':
		if (north.getLetter() != 'X')
		{
			north.setLetter('O');
		}
		else if (north.getLetter() != 'T')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 't':
		if (north.getLetter() != 'X')
		{
			north.setLetter('O');
		}
		else if (north.getLetter() != 't')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'Y':
		if (northeast.getLetter() != 'X')
		{
			northeast.setLetter('O');
		}
		else if (northeast.getLetter() != 'Y')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'y':
		if (northeast.getLetter() != 'X')
		{
			northeast.setLetter('O');
		}
		else if (northeast.getLetter() != 'y')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'F':
		if (west.getLetter() != 'X')
		{
			west.setLetter('O');
		}
		else if (west.getLetter() != 'F')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'f':
		if (west.getLetter() != 'X')
		{
			west.setLetter('O');
		}
		else if (west.getLetter() != 'f')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'G':
		if (center.getLetter() != 'X')
		{
			center.setLetter('O');
		}
		else if (center.getLetter() != 'G')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'g':
		if (center.getLetter() != 'X')
		{
			center.setLetter('O');
		}
		else if (center.getLetter() != 'g')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}		break;

	case 'H':
		if (east.getLetter() != 'X')
		{
			east.setLetter('O');
		}
		else if (east.getLetter() != 'H')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'h':
		if (east.getLetter() != 'X')
		{
			east.setLetter('O');
		}
		else if (east.getLetter() != 'h')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'V':
		if (southwest.getLetter() != 'X')
		{
			southwest.setLetter('O');
		}
		else if (southwest.getLetter() != 'V')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'v':
		if (southwest.getLetter() != 'X')
		{
			southwest.setLetter('O');
		}
		else if (southwest.getLetter() != 'v')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'B':
		if (south.getLetter() != 'X')
		{
			south.setLetter('O');
		}
		else if (south.getLetter() != 'v')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'b':
		if (south.getLetter() != 'X')
		{
			south.setLetter('O');
		}
		else if (south.getLetter() != 'b')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'N':
		if (southeast.getLetter() != 'X')
		{
			southeast.setLetter('O');
		}
		else if (southeast.getLetter() != 'N')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	case 'n':
		if (southeast.getLetter() != 'X')
		{
			southeast.setLetter('O');
		}
		else if (southeast.getLetter() != 'n')
		{
			cout << "That space is already occupied!";
			system("pause");
			playerTwoTurn();
		}
		break;

	default: cout << endl << "You didnt select anything";
		playerTwoTurn();
	}
	//Check for win conditions

	checkPlayerTwoWin();
	
	

	auto endplayertwo = chrono::steady_clock::now();
	auto diffplayertwo = endplayertwo - startplayertwo;
	playerTwoTime = playerTwoTime + chrono::duration <double, milli>(diffplayertwo).count();
	system("pause");
	if (playerTwoTime > 10000)
	{
		cout << playerTwoName << "Has run out of time";
		//add one loss to player 2 record
		//add one win to player 1 record
		system("pause");
		std::exit(0);
	}
}

//player order function
void playerOrder()
{
	
	playerOneTurn();
	playerTwoTurn();
	playerOneTurn();
	playerTwoTurn();
	playerOneTurn();
	playerTwoTurn();
	playerOneTurn();
	playerTwoTurn();
	playerOneTurn();

}

int main()
{
	//setting data for our pointers
		northwest.letter = 'R';
		north.letter = 'T';
		northeast.letter = 'Y';

		west.letter = 'F';
		center.letter = 'G';
		east.letter = 'H';

		southwest.letter = 'V';
		south.letter = 'B';
		southeast.letter = 'N';
		
		intro();


		playerOrder();


		char playAgain;
		cout << "Draw!!!" << endl;

		//write player two tied to file
		writeplayerTwoFile.open(playerTwoName + ".txt");
		writeplayerTwoFile << playerTwoWins + 0 << endl;
		writeplayerTwoFile << playerTwoLosses + 0 << endl;
		writeplayerTwoFile << playerTwoDraws + 1 << endl;
		writeplayerTwoFile.close();

		//write player one tied to file
		writeplayerOneFile.open(playerOneName + ".txt");
		writeplayerOneFile << playerOneWins + 0 << endl;
		writeplayerOneFile << playerOneLosses + 0 << endl;
		writeplayerOneFile << playerOneDraws + 1 << endl;
		writeplayerOneFile.close();
		cout << "You wanna play again? Y or N" << endl;

		cin >> playAgain;
		switch (playAgain)
		{
		case 'Y':
			playerOneTime = 0;
			playerTwoTime = 0;
			main();
		case 'y':
			playerOneTime = 0;
			playerTwoTime = 0;
			main();
		case 'N':
			std::exit(0);
		case 'n':
			std::exit(0);
			
			break;
		}
		
	
	cout << "How did you get here...?";
	system("PAUSE");
}

