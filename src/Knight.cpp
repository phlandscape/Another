
#include "../include/Knight.h"
Knight::Knight(bool w,int t):
Unit(w,t)
{

}

Knight::~Knight() {

}

#define startunit(y,x) Board[y][x].occupiedBy

bool Knight::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 if(!MovesOnEnemy(destX,destY,startunit(startY,startX)->isWhite,Board)){
   return false;
  }
 if(abs(startX-destX) == 1 && abs(startY-destY) == 2){
  return true;
 }
 if(abs(startX-destX) == 2 && abs(startY-destY) == 1){
  return true;
 }
 return false;
}


#undef startunit
