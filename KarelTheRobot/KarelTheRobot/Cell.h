#pragma once

ref class Cell{
private:
	bool MoveUp = true, MoveRight = true, MoveDown = true, MoveLeft = true, doesContainBeeper = false, doesContainKarel = false;
	System::Drawing::Pen ^wall = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	
public:
	Cell(char, bool, bool);
	void DrawWalls();
	void DrawCell();
	bool canMoveUp();
	bool canMoveRight();
	bool canMoveDown();
	bool canMoveLeft();
	bool containsBeeper();
	bool containsKarel();
};