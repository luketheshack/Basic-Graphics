// Luke Marushack
// Fundamentals of Computing : Lab #9
// funanim.c

#include "gfx.h"
#define ROT 50
 
// rotation circle width (ROT)

int main() {
	
	int pausetime = 20000;
	char c;
	int wd = 500, ht = 400;
	gfx_open(wd, ht, "Fun Animation");

	float xstart_sq = wd/2-100;
	float xstart_tr = wd/2+100;
	float ystart = ht/2;

	float xm_s = 0, ym_s = 0; 
	float xm_t = 0, ym_t = 0;
	float radians = 0;

	while (1) {
		gfx_clear();

		gfx_color(255, 0, 0);
		square(xstart_sq + xm_s, ystart+ym_s, SIZE/2);
		gfx_color(0, 255, 0);
		triangle(xstart_tr + xm_t, ystart+ym_t, SIZE/2);

		// Update square and triangle locations
		circularmotion(&xm_s, &ym_s, xstart_sq, ystart, &radians);
		circularmotion(&xm_t, &ym_t, xstart_tr, ystart, &radians);

		usleep(pausetime);
		gfx_flush();	
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

void circularmotion(float *xm, float *ym, float xstart, float ystart, float *radians) {
	float pi = 3.14159;

	*xm = ROT*cos(*radians);
	*ym = ROT*cos(*radians);
	if (*radians >= pi) {
		*xm *= -1;
	}
	if (*radians >= pi/2 && *radians < 3*pi/2) {
		*ym *= -1;
	}
	*radians += 0.01;
}
