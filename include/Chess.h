
#if !defined(CHESS_H)
#define CHESS_H

#include "King.h"


class Chess {
public:
  Chess();
  ~Chess();

  //UI
	void Refresh();
	bool GetInput(); // CALLS REFRESH
	bool CheckState();
private:
	void PrintBoard();

	//variables
	Square Board[boardsize][boardsize]; // boardsize == 8, defined in unit.h, defined in square.h
	Unit *WhiteKing;
	Unit *BlackKing;
	int nOfWhite;
	int nOfBlack;
	bool whoseTurnW;
	//friends
	friend class Unit;

  //Move
	bool MakeMove(int,int,int,int);
	void SwapPos(int,int,int,int);

  //EoT functions
	void CheckPromote();
	bool CheckCheckmate(); ///NYI
	bool CheckKings();
	bool CheckNofUnits();
  void PromoteUnit(int, int,bool);

  //startup
	void Init();

	//
	int GetNumberInput(int,int);

  //PrintBoard
  void PrintWith(bool,int);
  void PrintWithout(bool);
};
#endif  //_CHESS_H
