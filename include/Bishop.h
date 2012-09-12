
#if !defined(BISHOP_H)
#define BISHOP_H

#include "../include/Square.h"
#include "Unit.h"

class Bishop : public Unit{
public:
	Bishop(bool,int);
	~Bishop();
	bool CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]);
};

#endif  //_BISHOP_H
