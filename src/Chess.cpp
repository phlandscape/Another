
#include "../include/Chess.h"
#include "../include/Pawn.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"
#include <iostream>
#include <cstdlib>

Chess::Chess():
  WhiteKing(0),
  BlackKing(0),
  whoseTurnW(true)
{
 Init();
}
Chess::~Chess(){
}

#define startunit(y,x) Board[y][x].occupiedBy

void Chess::Refresh(){
 system("cls");
 PrintBoard();
}
bool Chess::GetInput() {
 bool invalid = true;
 std::string input;
 while(invalid){
  Refresh();
  std::cout << "Algebraic move instructions: " << std::endl;
  getline(std::cin,input);
  if(input[0]-48 >= 1 || input[0]-48 <= boardsize){ //int
   invalid = false;
  }else
  if(input[1] >= 97 || input[1] <= 104){ //char
   invalid = false;
  }else
  if(input[3]-48 >= 1 || input[3]-48 <= boardsize){ //int
   invalid = false;
  }else
  if(input[4] >= 97 || input[4] <= 104){ //char
   invalid = false;
  }
 }
  int startY(input[0]-49), startX(input[1]-97);
  int destY(input[3]-49), destX(input[4]-97);
  if(startunit(startY,startX) != 0){
   if(startunit(startY,startX)->isWhite == whoseTurnW){
    if(MakeMove(startX,startY,destX,destY)){
     whoseTurnW = !whoseTurnW;
    }
   }
  }
  return true;
}
void Chess::PrintBoard() {
 bool isColorW = true;
 int pos = 8;
 for(int y = 0; y < boardsize ; y++){
  std::cout << "   ";
  PrintWithout(isColorW);
  std::cout << " " << pos-y << " ";
  PrintWith(isColorW,pos-y-1);
  std::cout << "   ";
  PrintWithout(isColorW);
  isColorW = !isColorW;
 }
 std::cout << "   ";
 for(int x = 0; x < boardsize; x++){
  std::cout << " " << static_cast<char>(x+97) << "  ";
 }
 std::cout << std::endl;
}
void Chess::PrintWithout(bool gotColor){
 char s;
 for(int x = 0; x < boardsize; x++){
  if(gotColor){s = '=';}
  else{s = ' ';}
  std::cout << s << s << s << s;
  gotColor = !gotColor;
 }
 std::cout << std::endl;
}
void Chess::PrintWith(bool gotColor, int y){
 char s;
 for(int x = 0; x < boardsize; x++){

  if(gotColor){s = '=';}
  else{s = ' ';}
 char color = s;
 char unit = s;
  if(Board[y][x].occupiedBy != 0){
   if(Board[y][x].occupiedBy->isWhite == true){
    color = 'W';
   }else{color = 'B';}
   switch(Board[y][x].occupiedBy->isType){
    case Pawny:
     unit = 'P';
     break;
    case Knighty:
     unit = 'N';
     break;;
    case Rooky:
     unit = 'R';
     break;;
    case Bishopy:
     unit = 'B';
     break;;
    case Queeny:
     unit = 'Q';
     break;;
    case Kingy:
     unit = 'K';
     break;;
   }
  }
  std::cout << s << color << unit << s;
  gotColor = !gotColor;
 }
 std::cout << std::endl;
}

bool Chess::CheckState() {
 if(!CheckNofUnits()
  ||!CheckKings()){
  return false;
 }
 CheckPromote();
 return true;
}

bool Chess::MakeMove(int startX, int startY,int destX,int destY){
 if(startunit(startY,startX)->CheckMove(startX,startY,destX,destY,Board)){
  SwapPos(startX,startY,destX,destY);
  return true;
 }
 else{
  return false;
 }
}

void Chess::SwapPos(int startX, int startY,int destX,int destY){
 Board[destY][destX].RemoveUnit();
 startunit(destY,destX) = startunit(startY,startX);
 startunit(startY,startX) = 0;
}

//Function for promote
int Chess::GetNumberInput(int x, int y){
 bool looping = true;
 std::string input;
 int retType;
 while(looping){
  Refresh();
  std::cout << "Promote Pawn on ( " << x << " / " << y << " ) to:" << std::endl;
  getline(std::cin,input);
  retType = input[0];
  if(retType >= Rooky && retType <= Queeny){
   looping = false;
  }
 }
 return retType;
}
void Chess::PromoteUnit(int x, int y,bool isColorW){
 switch(GetNumberInput(x,y)){
  case Queeny:
   delete Board[y][x].occupiedBy;
   Board[y][x].occupiedBy = new Queen(isColorW,Queeny);
   break;
  case Rooky:
   delete Board[y][x].occupiedBy;
   Board[y][x].occupiedBy = new Rook(isColorW,Rooky);
   break;
  case Knighty:
   delete Board[y][x].occupiedBy;
   Board[y][x].occupiedBy = new Knight(isColorW,Knighty);
   break;
  case Bishopy:
   delete Board[y][x].occupiedBy;
   Board[y][x].occupiedBy = new Bishop(isColorW,Bishopy);
   break;
 }
}

void Chess::CheckPromote() {
 for(int i = 0; i < boardsize;i++){
  if(Board[0][i].occupiedBy->isType == Pawny){
   PromoteUnit(0,i,false);//is Black
  }
  if(Board[7][i].occupiedBy->isType == Pawny){
   PromoteUnit(0,i,true);//is White
  }
 }
}

bool Chess::CheckKings() {
 if(WhiteKing == 0 || BlackKing == 0){
  return false;
 }
 return true;
}

bool Chess::CheckNofUnits() {
 if(nOfWhite == 1 || nOfBlack == 1){
  return false;
 }
 return true;
}


void Chess::Init(){
  bool flip = true;
  for(int y = 0; y < boardsize; y++){
   for(int x = 0; x < boardsize; x++){
    Board[y][x].isWhite = flip;
    Board[y][x].occupiedBy = 0;
    flip = !flip;
   }
  }
  for(int i = 0; i < boardsize; i++){
   Board[1][i].occupiedBy = new Pawn(1,5);
   Board[6][i].occupiedBy = new Pawn(0,5);
  }
  for(int i = 1, y = 0; i >= 0;i--,y+=7){
   int typez = Rooky;
   Board[y][0].occupiedBy = new Rook(i,typez);
   Board[y][7].occupiedBy = new Rook(i,typez++);

   Board[y][1].occupiedBy = new Knight(i,typez);
   Board[y][6].occupiedBy = new Knight(i,typez++);

   Board[y][2].occupiedBy = new Bishop(i,typez);
   Board[y][5].occupiedBy = new Bishop(i,typez++);

   Board[y][3].occupiedBy = new Queen(i,typez++);

   Board[y][4].occupiedBy = new King(i,typez);
  }
  WhiteKing = Board[0][4].occupiedBy;
  BlackKing = Board[7][4].occupiedBy;
  nOfWhite = 16;
  nOfBlack = 16;
}

#undef startunit
