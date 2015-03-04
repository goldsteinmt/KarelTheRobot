#include "Karel.h"

Karel::Karel(int newx, int newy, int newd, int newb){
	x = newx; y = newy; d = newd; b = newb;
}

int Karel::get_x()
{
	return x;
}

int Karel::get_y()
{
	return y;
}

void Karel::turnLeft(){
	if (d == 1)
		d = 4;
	else d--;
}

void Karel::move(){
	switch (d){
	case 1:
		y++;
		break;
	case 2:
		x++;
		break;
	case 3:
		y--;
		break;
	case 4:
		x--;
		break;
	}
}

void Karel::pickbeeper(){
	b++;
}

void Karel::putbeeper(){
	b--;
}

