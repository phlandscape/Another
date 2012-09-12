
#if !defined(KNIGHT_H)
#define KNIGHT_H

#include "../include/Square.h"
#include "Unit.h"
class Knight : public Unit {
public:
	Knight(bool,int);
	~Knight();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_KNIGHT_H
