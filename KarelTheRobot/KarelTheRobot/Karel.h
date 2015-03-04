#pragma once

ref class Karel{
private:
	int d, b, x, y;

public:
	Karel(int,int, int, int);

	void turnLeft();
	void move();
	void putbeeper();
	void pickbeeper();
	int get_x();
	int get_y();

};