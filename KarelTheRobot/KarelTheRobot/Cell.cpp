#include "Cell.h"
#include <ctype.h>

Cell::Cell(int n){
	num_beepers = n;
	if (n > 0){
		doesContainBeeper = true;
	}
}

void Cell::setWall(char w){
	switch (tolower(w)){
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
}

//
void Cell::DrawWalls(Graphics^ g, Rectangle r){
	if (!MoveDown){
		g->DrawLine(wall, r.Bottom, r.Left, r.Bottom, r.Right);
	}
	if (!MoveLeft){
		g->DrawLine(wall, r.Left, r.Top, r.Left, r.Bottom);
	}
	if (!MoveUp){
		g->DrawLine(wall, r.Top, r.Left, r.Bottom, r.Top);
	}
	if (!MoveRight){
		g->DrawLine(wall, r.Right, r.Top, r.Right, r.Bottom);
	}
}

void Cell::DrawCell(Graphics^ g, Rectangle r){
	g->FillRectangle(cellColor, r);
	DrawWalls(g, r);
}

void Cell::setBeeper(){
	doesContainBeeper = true;
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