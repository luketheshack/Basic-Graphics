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
		
		int val = c - '0';
		// clear screen
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
			triangle(xm, ym, SIZE/2);
		}
		// n-sided polygon
		else if ( val >= 3 && val <= 9 ) {
			gfx_color(255, 0, 255);
			polygon(xm, ym, val, SIZE/2);
		}
		// blue square
		else if ((int) c == 1) {
			gfx_color(0, 0, 255);
			square(xm, ym, SIZE/2);
		}
		else {
			printf("Bad input, please try again!\n");
		}
	}
	return 0;
}

void triangle(int xm, int ym, int radius) {
	polygon(xm, ym, 3, radius);
}

void square(int xm, int ym, int radius) {
	polygon(xm, ym, 4, radius);
}

void polygon(int xm, int ym, int sides, int radius) {
	float i, part, x1, x2, y1, y2;
	part = 2*PI/sides;
	
	for (i = 0; i <= 2*PI; i += part) {
		x1 = radius * cos(i) + xm;
		x2 = radius * cos(i + part) + xm;
		y1 = -1 * radius * sin(i) + ym;
		y2 = -1 * radius * sin(i + part) + ym;
		gfx_line(x2, y2, x1, y1);	
	}	
}
