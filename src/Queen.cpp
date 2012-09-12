
#include "../include/Queen.h"

Queen::Queen(bool w,int t):
Unit(w,t)
{

}

Queen::~Queen() {

}

#define startunit(y,x) Board[y][x].occupiedBy
bool Queen::CheckMove(int startX, int startY, int destX, int destY, const Square Board[][boardsize]) {
 if(!MovesOnEnemy(destX,destY,startunit(startY,startX)->isWhite,Board)){
  return false;
 }

 int y(startY+1);
 //left'n'right
 if(destX == startX){
  if(startY < destY){
   while(y < destY){
    if(!CheckPos(startX,y++,Board)){
     return false;
    }
   }
  }else{ // >
   while(y < destY){
    if(!CheckPos(startX,y--,Board)){
     return false;
    }
   }
  }
  return true;
 }
 int x(startX+1);
 // up'n'down
 if(startY == destY){
  if(startX < destX){
   while(x < destX){
    if(!CheckPos(x++,startY,Board)){
     return false;
    }
   }
  }else{ // >
   while(x < destX){
    if(!CheckPos(x--,startY,Board)){
     return false;
    }
   }
  }
 return true;
 }
 //Diagonals
 x = startX+1; y = startY+1;
 //bot left
 if(startX > destX && startY > destY){
  while(x < destX && y < destY){
   if(CheckPos(x--,y--,Board)){
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
   if(CheckPos(x--,y++,Board)){
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
   if(CheckPos(x++,y--,Board)){
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
   if(CheckPos(x++,y++,Board)){
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
