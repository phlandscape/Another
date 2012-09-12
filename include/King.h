
#if !defined(KING_H)
#define KING_H

#include "../include/Square.h"
#include "Unit.h"

class King : public Unit {
public:
	King(bool,int);
	~King();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_KING_H
