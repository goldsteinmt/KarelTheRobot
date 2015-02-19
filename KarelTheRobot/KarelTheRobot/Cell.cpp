#include "Cell.h"

Cell::Cell(char w, bool b, bool k){
	switch (w){
	case 'u':
		MoveUp = false;
		break;
	case 'r':
		MoveRight = false;
		break;
	case 'd':
		MoveDown = false;
		break;
	case 'l':
		MoveLeft = false;
		break;
	}

	if (b){
		doesContainBeeper = true;
	}
	if (k){
		doesContainKarel = true;
	}
}

void Cell::DrawWalls(){

}

void Cell::DrawCell(){

}

bool Cell::canMoveDown(){
	return MoveDown;
}

bool Cell::canMoveUp(){
	return MoveUp;
}

bool Cell::canMoveLeft(){
	return MoveLeft;
}

bool Cell::canMoveRight(){
	return MoveRight;
}

bool Cell::containsKarel(){
	return doesContainKarel;
}

bool Cell::containsBeeper(){
	return doesContainBeeper;
}