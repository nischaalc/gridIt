//-----------------------------------------------------------
//Program Name: Grid Game
//Author: Nischaal Cooray
//Desciption: Simulates a game of 'pegs' on a square board. Similar to a game of checkers, pieces are eliminated if they are 'jumped' over.
//-----------------------------------------------------------

#ifndef __GRID__
#define __GRID__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class GridGame
{

public:
	//-----------Constructors--------
	GridGame();
	//-------------------------------

	//-----------Destructor----------
	//~GridGame();
	//-------------------------------
	
	//-----------Inspectors----------
	bool isLegalMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn);
	int movesLeft();
	//-------------------------------

	//-----------Mutators------------ 
	void applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn);
	void startPosition(int startPosRow, int startPosColumn);
	//-------------------------------

	//-----------Facilitators--------
	void output(ostream& out);
	//-------------------------------


private:
	vector<vector<int> > grid_;
};

//-------Operator Overloading--------
ostream& operator<<(ostream& out, GridGame& displayGrid);
//-----------------------------------

#endif 