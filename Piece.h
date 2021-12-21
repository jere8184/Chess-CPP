#pragma once


#include "Board.h"
#include "Square.h"
#include<string>
#include<tuple>

using namespace std;

class Piece {


public:

	bool Moved = false;

	int RankIndex;

	int FileIndex;

	void Captured();

	bool IsCaptured = false;

	bool ValidateAttack(int destFile, int destRank);

	string Coordinate;

	string Symbol = "U";

	string Type = "U";

	string Colour;

	Square* Square;

	Piece(int fileIndex, int rankIndex, string colour);

	void Move(int file, int rank);

	void Attack(int file, int rank);

	static string To_Coordinate(int fileIndex, int rankIndex);

	static tuple<int, int> To_indexs(string coordinate);

	void Move(string coordinate);

	virtual void TryMove(int file, int rank);

	bool Search(int destFile, int destRank);

	bool ValidateMove(int destFile, int destRank);

};
