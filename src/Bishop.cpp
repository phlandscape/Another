
#include "../include/Bishop.h"

Bishop::Bishop(bool w,int t):
 Unit(w,t)
{

}

Bishop::~Bishop() {

}

#define startunit(y,x) Board[y][x].occupiedBy


bool Bishop::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 if(!MovesOnEnemy(destX,destY,startunit(startY,startX)->isWhite,Board)){
   return false;
  }
 int x(startX), y(startY);
 //bot left
 if(startX > destX && startY > destY){
  while(x < destX && y < destY){
   if(CheckPos(--x,--y,Board)){
    return false;
   }
  }
  if(x == destX && y == destY){
   return true;
  }else{
   return false;}
 }
 //top left
 if(startX > destX && startY < destY){
  while(x < destX && y < destY){
   if(CheckPos(--x,++y,Board)){
    return false;
   }
  }
  if(x == destX && y == destY){
   return true;
  }else{
   return false;}
 }
 //bot right
 if(startX < destX && startY > destY){
  while(x < destX && y < destY){
   if(CheckPos(++x,--y,Board)){
    return false;
   }
  }
  if(x == destX && y == destY){
   return true;
  }else{
   return false;}
 }
 //top right
 if(startX < destX && startY < destY){
  while(x < destX && y < destY){
   if(CheckPos(++x,++y,Board)){
    return false;
   }
  }
  if(x == destX && y == destY){
   return true;
  }else{
   return false;}
 }
 return false;
}


#undef startunit
