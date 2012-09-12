
#if !defined(ROOK_H)
#define ROOK_H

#include "../include/Square.h"
#include "Unit.h"

class Rook : public Unit {
public:
	Rook(bool,int);
	~Rook();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_ROOK_H
