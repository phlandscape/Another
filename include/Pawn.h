
#if !defined(PAWN_H)
#define PAWN_H

#include "../include/Square.h"
#include "Unit.h"

class Pawn : public Unit {
public:
	Pawn(bool,int);
	~Pawn();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_PAWN_H
