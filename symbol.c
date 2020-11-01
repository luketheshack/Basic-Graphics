// Luke Marushack
// Fundamentals of Computing : Lab #9
// symbol.c

#include "gfx.h"

int main() {
	int wd = 500; // width
	int ht = 400; // height
	char c;
	int xm, ym;

	gfx_open(wd, ht, "Symbol");
	
	while (1) {
		gfx_flush();
		c = gfx_wait();
		xm = gfx_xpos();
		ym = gfx_ypos();
		// quit
		if (c == 'q') break;
		
		if ((int) c == 27) {
			gfx_clear();
		}
		// white circle
		else if (c == 'c') {
			gfx_color(255, 255, 255);
			gfx_circle(xm, ym, SIZE/2);
		}
		// green triangle
		else if (c == 't') {
			gfx_color(0, 255, 0);
			polygon(xm, ym, SIZE/2, 3);
		}

	}
	return 0;
}

void polygon(int xm, int ym, int sides, int radius) {
	float i, part, x1, x2, y1, y2;
	part = 2*PI/sides;
	
	for (i = 0; i <= 2*PI; i += part) {
		x1 = radius * cos(i) + xm;
		x2 = radius * cos(i + part) + xm;
		y1 = radius * sin(i) + ym;
		y2 = radius * sin(i + part) + ym;
		gfx_line(x1, y1, x2, y2);	
	}	
}
