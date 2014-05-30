//-----------------------------------------------------------
//Program Name: Grid Game
//Author: Nischaal Cooray
//Desciption: Simulates a game of 'pegs' on a square board. Similar to a game of checkers, pieces are eliminated if they are 'jumped' over.
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "GridGame.h"

using namespace std;

//----------Prototypes------------
bool wantToQuit(int quitNum, int quitCol);
string test();
//--------------------------------

int main(void)
{
	//-----Local Variables----------------
	GridGame myGrid;
	int startRow, startCol, endRow, endCol;
	ofstream outFile("ouput.txt");
	int useFile;
	string fileName;
	ifstream inFile;
	//------------------------------------

	//-----Introduction and Guide---------
	cout << "Welcome to the Grid Game!" << endl;
	cout << "The aim of the game is simple: Simply try and remove all the X's from the grid\nbelow." << endl;
	cout << "Use the grid coordinates provided to indicate which X you want to move. Keep in mind that there must be an O in the position you want to move it to, and there\nmust also be an X inbetween these two points." << endl;
	cout << "Format for entering coordinates is: startRow startColumn endRow endColumn. For\nexample: 2 0 2 2 moves an X from (2,0) to (2,2)." << endl;
	cout << "Enter \"99 99\" at any time to quit." << endl << endl;
	//------------------------------------

	cout << myGrid << endl;			//Generate the initial grid
	outFile << myGrid << endl;

	cout << "Use file or console input? (1 for file, 2 for console): ";
	cin >> useFile;
	
	if (useFile == 1)
	{
		cout << "Enter filename: ";
		cin >> fileName; 

		inFile.open(fileName);

		inFile >> startRow >> startCol;
		bool quit = wantToQuit(startRow, startCol);		//Check if the user wants to quit

		if (quit == false)				//Only proceed if the user does not want to quit
		{
			myGrid.startPosition(startRow - 1, startCol - 1);		//Update the start position by calling the appropriate method

			while (quit == false)		//Only execute this loop if the user does not want to quit
			{
				bool legalMove = false;

				cout << myGrid << endl;		//Update the displayed grid
				outFile << myGrid << endl;

				while (legalMove == false)		//Loop will continue to execute indefinitely
				{

					int complete = myGrid.movesLeft();

					if (complete == 3)
					{
						cout << "You beat the game!" << endl;
						return 0;
					}

					cout << "Enter move (four values): ";		//Request a move from the user
					inFile >> startRow >> startCol;
					quit = wantToQuit(startRow, startCol);		//Check if the user wants to quit

					if (quit == false)
					{
						inFile >> endRow >> endCol;
						cout << endl;

						legalMove = myGrid.isLegalMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1); //Check if this was a legal move

						if (legalMove == false)
						{
							cout << "There is an error in your file!" << endl << endl;
							return 0;
						}
						else
						{
							legalMove = true;
							myGrid.applyMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1);		//Apply the move only if it was legal
						}

					}
					else
					{
						cout << "Thanks for Playing!" << endl;
						return 0;
					}

				}

			}
		}


	}

	else if (useFile == 2)
		{

			cout << "Enter starting position (only two values): ";		//Request for position to remove first peg from

			cin >> startRow >> startCol;
			bool quit = wantToQuit(startRow, startCol);		//Check if the user wants to quit

			if (quit == false)				//Only proceed if the user does not want to quit
			{
				myGrid.startPosition(startRow - 1, startCol - 1);		//Update the start position by calling the appropriate method

				while (quit == false)		//Only execute this loop if the user does not want to quit
				{
					bool legalMove = false;

					cout << myGrid << endl;		//Update the displayed grid
					outFile << myGrid << endl;

					while (legalMove == false)		//Loop will continue to execute indefinitely
					{

						int complete = myGrid.movesLeft();

						if (complete == 3)
						{
							cout << "You beat the game!" << endl;
							return 0;
						}

						cout << "Enter move (four values): ";		//Request a move from the user
						cin >> startRow >> startCol;
						quit = wantToQuit(startRow, startCol);		//Check if the user wants to quit

						if (quit == false)
						{
							cin >> endRow >> endCol;
							cout << endl;

							legalMove = myGrid.isLegalMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1); //Check if this was a legal move

							if (legalMove == false)
							{
								cout << "Please enter a valid move!" << endl << endl;
							}
							else
							{
								legalMove = true;
								myGrid.applyMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1);		//Apply the move only if it was legal
							}

						}
						else
						{
							cout << "Thanks for Playing!" << endl;
							return 0;
						}

					}

				}
			}

			else
				cout << "Thanks for Playing!" << endl;
		}


	outFile.close();

	return 0;
}

/*
Checks parameter values to check whether the user has indicated that they want to quit
@param quitRow, quitCol: the values input by the user
*/
bool wantToQuit(int quitRow, int quitCol)
{
	if ((quitRow == 99) && (quitCol == 99))
		return true;
	else
		return false;
}