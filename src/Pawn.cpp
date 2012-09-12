
#include "../include/Pawn.h"

Pawn::Pawn(bool w,int t):
Unit(w,t)
{

}

Pawn::~Pawn() {

}

#define startunit(y,x) Board[y][x].occupiedBy

bool Pawn::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 Unit* starter = startunit(startY,startX);

 if(starter->isWhite){
  if(startX == destX && (destY-startY == 1)){
   if(startunit(destY,destX) == 0){
    return true;
   }
  }
  if(startunit(destY,destX) != 0){
   if((abs(startX-destX) == 1) && (destY - startY == 1)){
    if(startunit(destY,destX)->isWhite != starter->isWhite){
     return true;
    }
   }
  }
 }
 else{
  if(startX == destX && (startY - destY == 1)){
   if(startunit(destY,destX) == 0){
    return true;
   }
  }
  if(startunit(destY,destX) != 0){
   if((abs(startX-destX) == 1) && (startY - destY == 1)){
    if(startunit(destY,destX)->isWhite != starter->isWhite){
     return true;
    }
   }
  }
 }
 return false;
}

#undef startunit
