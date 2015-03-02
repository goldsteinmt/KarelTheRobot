#include "Cell.h"

using namespace System::Drawing;

Cell::Cell(int x, int y){
	xLoc = x;
	yLoc = y;
}

void Cell::setWall(int w){
	switch (w){
	case 1:
		MoveUp = false;
		break;
	case 2:
		MoveRight = false;
		break;
	case 3:
		MoveDown = false;
		break;
	case 4:
		MoveLeft = false;
		break;
	}
}

//
void Cell::DrawWalls(Graphics^ g, Rectangle^ r){
	if (!MoveDown){
		g->DrawLine(wall, r->Bottom, r->Left, r->Bottom, r->Right);
	}
	if (!MoveLeft){
		g->DrawLine(wall, r->Left, r->Top, r->Left, r->Bottom);
	}
	if (!MoveUp){
		g->DrawLine(wall, r->Top, r->Left, r->Top, r->Right);
	}
	if (!MoveRight){
		g->DrawLine(wall, r->Right, r->Top, r->Right, r->Bottom);
	}
}

void Cell::DrawCell(Graphics^ g, Rectangle^ r){
	g->FillRectangle(cellColor, r->X, r->Y, r->Width, r->Height);
	DrawWalls(g, r);
}

void Cell::setBeeper(int b){
	num_beepers = b;
	if (b > 0)
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

int Cell::getBeepers(){
	return num_beepers;
}

int Cell::getX(){
	return xLoc;
}
int Cell::getY(){
	return yLoc;
}