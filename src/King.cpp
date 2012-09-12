
#include "../include/King.h"

King::King(bool w,int t):
 Unit(w,t)
{

}

King::~King() {

}
#define startunit(y,x) Board[y][x].occupiedBy

bool King::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 Unit* starter = startunit(startY,startX);

 //if(CheckCheckmate) [== true] return false;

 //is it moving onto own unit
 if(startunit(destY,destX) != 0){
  if(startunit(destY,destX)->isWhite == starter->isWhite){
   return false;
  }
 }

 //checking for move range
 //checks diagonals
 if(abs(destX-startX) == 1 && (abs(destY-startY) == 1)){
    return true;
   }
 //checks for up'n'down
 if(startX == destX && abs(destY - startY) == 1){
  return true;
 }
 //checks for left'n'right
 if(abs(startX-destX) == 1 && destY == startY){
  return true;
 }
 return false;
}

#undef startunit
