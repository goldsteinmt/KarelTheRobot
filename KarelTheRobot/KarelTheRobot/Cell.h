#pragma once

using namespace System::Drawing;

ref class Cell{
private:
	bool MoveUp = true, MoveRight = true, MoveDown = true, MoveLeft = true, doesContainBeeper = false;
	Pen ^wall = gcnew Pen(Color::Black);
	SolidBrush ^cellColor = gcnew SolidBrush(Color::Bisque);
	
public:
	Cell(char, bool, bool);
	void DrawWalls(Graphics^, Rectangle);
	void DrawCell(Graphics^, Rectangle);
	void setBeeper();
	bool canMoveUp();
	bool canMoveRight();
	bool canMoveDown();
	bool canMoveLeft();
	bool containsBeeper();
	bool containsKarel();
};