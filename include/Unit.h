
#if !defined(UNIT_H)
#define UNIT_H
#include <cstdlib>
class Square;
enum dj{
 boardsize=8
};
enum units{
 Rooky,
 Knighty,
 Bishopy,
 Queeny,
 Kingy,
 Pawny
};

class Unit {
 public:
  //constructors
  Unit(bool,int);
  virtual ~Unit();

  //checking
	bool virtual CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize])=0;
	bool MovesOnEnemy(int x, int y, bool travelColorW, const Square Board[][boardsize]); // true for enemey or empty field
  bool CheckPos(int x,int y, const Square Board[][boardsize]); // true for empty field

  //variables
	bool isWhite;
	int isType;
};
#endif  //_UNIT_H
