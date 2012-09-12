/* Author: Philipp
 * Project: my recreation of Chess in the command prompt
 * developed on a Windows 7 x64 machine
   and a spiral notepad
 * used editors/programs
   Code::Blocks, StarUML
 *
*/
/***
  The Game should always be ready for build & run
  after each successfully implemented feature
*/

/// the macro startunit(y,x) takes y first, all member functions take x values first!

#include <iostream>
#include "include\Chess.h"

void PlayChess();

int main(){

 std::string input;

 while(true){
  getline(std::cin,input);
  if(input == "chess"){PlayChess();}

  system("cls");
}

 return 0;
}


void PlayChess(){
 Chess ChGame;
 std::string input;
 while(ChGame.CheckState()){
  while(ChGame.GetInput()){
  }
 }
}
