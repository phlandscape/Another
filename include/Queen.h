
#if !defined(QUEEN_H)
#define QUEEN_H

#include "../include/Square.h"
#include "Unit.h"

class Queen : public Unit {
public:
	Queen(bool,int);
	~Queen();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_QUEEN_H
