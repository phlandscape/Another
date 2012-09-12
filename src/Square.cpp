

#include "../include/Square.h"

Square::Square():
 occupiedBy(0)
{

}

Square::~Square() {
 RemoveUnit();
}

void Square::AddUnit() {

}

void Square::RemoveUnit() {
 delete occupiedBy;
}

