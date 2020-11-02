// Luke Marushack
// Fundamentals of Computing : Lab #9
// funanim.c

#include "gfx.h"
#define ROT 50
 
// rotation circle width (ROT)

int main() {
	
	char c;
	int wd = 500, ht = 400;
	gfx_open(wd, ht, "Fun Animation");

	float xstart_sq = wd/2-100;
	float xstart_tr = wd/2+100;
	float ystart = ht/2;
	float radians = 0;

	circularmotion(xstart_sq, xstart_tr, ystart, radians);
	
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

void circularmotion(float xstart_sq, float xstart_tr, float ystart, float radians) {
	int x_offset = 0, y_offset = 0, pausetime = 15000;
	while (1) {
		gfx_clear();

		if (radians > 2*PI) {
			radians -= 2*PI;
		}
		
		gfx_color(255, 0, 0);
		triangle(xstart_tr + x_offset, ystart + y_offset, SIZE/2);
		gfx_color(0, 255, 0);
		square(xstart_sq + x_offset, ystart + y_offset, SIZE/2);

		gfx_flush();
		x_offset = ROT*cos(radians);
		y_offset = ROT*sin(radians);

		radians += 0.01;
		usleep(pausetime);
	}
		
}
