#include "Rook.h"


Rook::Rook(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("R");
	SetType("Rook");
	IsWhite() ? SetTexture("white_rook.png") : SetTexture("black_rook.png");
}

bool Rook::ValidateMove(int destFile, int destRank)
{
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);
	if (IsLinearMove(fileDelta, rankDelta) && IsStraightMove(fileDelta, rankDelta))
	{
		return true;
	}
	return false;
}

