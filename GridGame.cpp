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
 
//----------------Default Constructor------------
GridGame::GridGame()
{
	for (int i = 0; i < 4; i++)
	{
		vector<int> gridRow;
		for (int j = 0; j < 4; j++)
		{
			gridRow.push_back(1);
		}
		grid_.push_back(gridRow);
	}
}
//-----------------------------------------------

//---------Method to check if a move is legal----
bool GridGame::isLegalMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn)
{
	int distanceBetweenRow, distanceBetweenColumn, middlePosRow, middlePosColumn;

	//-----------------Necessary Calculations------------------
	distanceBetweenRow = abs(endPosRow - startPosRow);
	distanceBetweenColumn = abs(endPosColumn - startPosColumn);
	middlePosRow = (endPosRow + startPosRow) / 2;
	middlePosColumn = (endPosColumn + startPosColumn) / 2;
	//---------------------------------------------------------

	//-----Check whether start and end exist on board-------
	if ((startPosRow > 3) || (startPosColumn > 3))
		return false;
	else if ((startPosRow < 0) || (startPosColumn < 0))
		return false;
	else if ((endPosRow > 3) || (endPosColumn > 3))
		return false;
	else if ((endPosRow < 0) || (endPosColumn < 0))
		return false;
	//------------------------------------------------------

	//------Check if a peg exists in starting position-----
	else if (grid_[startPosRow][startPosColumn] == 0)
		return false;
	//-----------------------------------------------------

	//------Check if a peg exists in the end position------
	else if (grid_[endPosRow][endPosColumn] == 1)
		return false;
	//-----------------------------------------------------

	//-----Check the distance between start and end--------
	else if ((distanceBetweenRow > 2) || (distanceBetweenColumn > 2))
		return false;
	else if ((distanceBetweenRow < 2) && (distanceBetweenColumn < 2))
		return false;
	//------------------------------------------------------

	//-----Check if a peg exists in middle position---------
	else if (grid_[middlePosRow][middlePosColumn] == 0)
		return false;
	else
		return true;
	//------------------------------------------------------

}
//-----------------------------------------------

//---Set the start position defined by the user--
void GridGame::startPosition(int startPosRow, int startPosColumn)
{
	grid_[startPosRow][startPosColumn] = 0;
}
//-----------------------------------------------

//-Apply the users move by updating grid_ vector-
void GridGame::applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn)
{
	int middlePosRow = (endPosRow + startPosRow) / 2;
	int middlePosColumn = (endPosColumn + startPosColumn) / 2;

	grid_[startPosRow][startPosColumn] = 0;
	grid_[middlePosRow][middlePosColumn] = 0;
	grid_[endPosRow][endPosColumn] = 1;
}
//-----------------------------------------------

//---Check if the game is still playable---------
int GridGame::movesLeft()
{
	int zeroCount = 0, oneCount = 0;

	//----Check if the user beat the game--------
	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 4; j++)
		{

			if (grid_[i][j] == 0)
				zeroCount = zeroCount + 1;
			else
				oneCount = oneCount + 1;
		}
	}

	if (oneCount == 1)
	{
		return 3;
	}
	//----------------------------------------------

}
//-----------------------------------------------

//----Facilitator to output grid and vector------
void GridGame::output(ostream& out)
{
	out << "     1  2  3  4" << endl;
	out << "  +-------------+" << endl;
	for (int i = 0; i < 4; i++)
	{
		out << i + 1 << " | ";
		for (int j = 0; j < 4; j++)
		{
			if (grid_[i][j] == 1)
				out << " X ";
			else
				out << " O ";
		}
		out << "| " << endl;
	}
	out << "  +-------------+" << endl;
}
//-----------------------------------------------

//--Method for overloading output operator-------
ostream& operator<<(ostream& out, GridGame& displayGrid)
{
	displayGrid.output(out);
	return out;
}
//-----------------------------------------------
