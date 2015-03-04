#pragma once

using namespace System::Drawing;

ref class Cell{
private:
	int num_beepers, xLoc, yLoc;
	bool MoveUp = true, MoveRight = true, MoveDown = true, MoveLeft = true, doesContainBeeper = false;
	Pen ^wall = gcnew Pen(Color::Black);
	SolidBrush ^cellColor = gcnew SolidBrush(Color::Bisque);
	
public:
	Cell(int, int);
	void DrawWalls(Graphics^, Rectangle^);
	void DrawCell(Graphics^, Rectangle^);
	void DrawCell(Graphics^, Rectangle^, Bitmap^ b);
	void setBeeper(int);
	void setWall(int);
	bool canMoveUp();
	bool canMoveRight();
	bool canMoveDown();
	bool canMoveLeft();
	int getBeepers();
	int getX();
	int getY();
};