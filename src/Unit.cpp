
//square includes unit
#include "../include/Square.h"

//constructors
Unit::Unit(bool w,int t):
 isWhite(w),
 isType(t)
{

}

Unit::~Unit() {

}
#define startunit(y,x) Board[y][x].occupiedBy

//checking
// true for enemey or empty field
bool Unit::MovesOnEnemy(int x, int y,bool travelColorW, const Square Board[][boardsize]) {
 if(startunit(y,x) != 0){
  if(startunit(y,x)->isWhite == travelColorW){
   return false;
  }
 }
 return true;
}
// true for empty field
bool Unit::CheckPos(int x,int y, const Square Board[][boardsize]){
 if(startunit(y,x) != 0){
  return false;
 }
 else{
  return true;}
}

#undef startunit
