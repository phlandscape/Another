
#if !defined(SQUARE_H)
#define SQUARE_H

#include "Unit.h"

class Square {
public:
	bool isWhite;
	Unit *occupiedBy;
	Square();
	~Square();
	void AddUnit();
	void RemoveUnit();
};

#endif  //_SQUARE_H
