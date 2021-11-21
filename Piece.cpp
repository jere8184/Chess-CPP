#include "Piece.h"

using namespace std;


	Piece::Piece(int fileIndex, int rankIndex) {
		this->RankIndex = rankIndex;
		this->FileIndex = fileIndex;
		this->Coordinate = To_Coordinate(FileIndex, RankIndex);
		this->Square = &Board::board[FileIndex][RankIndex];
		this->Square -> isOccupied = true;
		this->Square -> Occupiere = this;
	}

	string Piece::To_Coordinate(int fileIndex, int rankIndex) {

		string coordinate;
		switch (fileIndex) {
		case 0:
			coordinate += "a";
			break;
		case 1:
			coordinate += "b";
			break;
		case 2:
			coordinate += "c";
			break;
		case 3:
			coordinate += "d";
			break;
		case 4:
			coordinate += "e";
			break;
		case 5:
			coordinate += "f";
			break;
		case 6:
			coordinate += "g";
			break;
		case 7:
			coordinate += "h";
			break;
		}
		return coordinate += to_string(rankIndex + 1); //chess coordinate = index + 1 as chess coordinate starts at 1 (i.e. a1)
	}

	tuple<int, int> Piece::To_indexs(string coordinate) {

		char fileChar = coordinate[0];
		int file = 0;
		char rankChar = coordinate[1];
		int rank = rankChar - '1'; //index = -1 chess coordinate as index begins at 0
		switch (fileChar) {
		case 'a':
			file = 0;
			break;
		case 'b':
			file = 1;
			break;
		case 'c':
			file += 2;
			break;
		case 'd':
			file += 3;
			break;
		case 'e':
			file += 4;
			break;
		case 'f':
			file += 5;
			break;
		case 'g':
			file += 6;
			break;
		case 'h':
			file += 7;
			break;
		}
		return make_tuple(file, rank);
	}

	void Piece::Move(int file, int rank) {
		this->Square->isOccupied = false;
		this->Square->Occupiere = nullptr;
		this->RankIndex = rank;
		this->FileIndex = file;
		this->Coordinate = To_Coordinate(file, rank);
		this->Square = &Board::board[file][rank];
		this->Square->isOccupied = true;
		this->Square->Occupiere = this;
	}


	void Piece::Move(string coordinate) {
		this->Square -> isOccupied = false;
		this->Square -> Occupiere = nullptr;
		int file = get<0>(To_indexs(coordinate));
		int rank = get<1>(To_indexs(coordinate));
		this->FileIndex = file;
		this->RankIndex = rank;
		this->Coordinate = coordinate;
		this->Square = &Board::board[file][rank];
		this->Square->isOccupied = true;
		this->Square->Occupiere = this;
	}

	bool Piece::ValidateMove(int fileDelta, int rankDelta) {

		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7) 
		{
			cout << "off the board";
			return false;
		}



		return true;
	}

