

#include "../include/Rook.h"

Rook::Rook(bool w,int t):
Unit(w,t)
{

}

Rook::~Rook() {

}

#define startunit(y,x) Board[y][x].occupiedBy
bool Rook::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 if(!MovesOnEnemy(destX,destY,startunit(startY,startX)->isWhite,Board)){
  return false;
 }

 int y(startY+1);
 if(destX == startX){
  if(startY < destY){
   while(y < destY){
    if(!CheckPos(startX,y++,Board)){
     return false;
    }
   }
  }else{ // >
   while(y < destY){
    if(!CheckPos(startX,y++,Board)){
     return false;
    }
   }
  }
  return true;
 }
 int x(startX+1);
 if(startY == destY){
  if(startX < destX){
   while(x < destX){
    if(!CheckPos(x++,startY,Board)){
     return false;
    }
   }
  }else{ // >
   while(x < destX){
    if(!CheckPos(x++,startY,Board)){
     return false;
    }
   }
  }
 return true;
 }
 return false;
}


#undef startunit
