#pragma once

ref class Karel{
private:
	int isFacing = 1, hasBeeper = 0;
	// starts facing north with no beepers
	
	int x=0, y=0;

public:
	Karel(int,int);

	void turnLeft(int&);
	void move(int, int, int)
};