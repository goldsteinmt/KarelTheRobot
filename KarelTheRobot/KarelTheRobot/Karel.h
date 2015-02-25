#pragma once

ref class Karel{
private:
	int d, b;
	
	int x=0, y=0;

public:
	Karel(int,int, int, int);

	void turnLeft();
	void move();
	void putbeeper();
	void pickbeeper();
};