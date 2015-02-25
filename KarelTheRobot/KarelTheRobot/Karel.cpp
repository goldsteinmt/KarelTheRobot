#include "Karel.h"

Karel::Karel(int d, int b){}



void Karel::turnLeft(int& d){
	if (d == 1)
		d = 4;
	else d--;
}

void Karel::move(int x, int y, int d){
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

