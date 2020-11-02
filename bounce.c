// Luke Marushack
// Fundamentals of Computing : Lab #9
// bounce.c

#include "gfx.h"

int main() {
	int wd = 500, ht = 400;
	char c = 0;
	float xc = 0, yc = 0; // ball x-pos and ball y-pos
	float vx = 0, vy = 0; // ball velocity x and velocity y
	int pausetime = 20000;
		
	gfx_open(wd, ht, "Bouncing Ball");
	randomizeball(&xc, &yc, &vx, &vy);
	xc = wd/2;
	yc = ht/2;
	while (c != 'q') {
		gfx_clear();
		gfx_circle(xc, yc, SIZE/2);
		gfx_flush();
		
		xc += vx;
		yc += vy;

		if (xc >= wd - SIZE/2 || xc <= SIZE/2) {
			vx = -vx;
		}

		if (yc >= ht - SIZE/2 || yc <= SIZE/2) {
			vy = -vy;
		}

		if (gfx_event_waiting()) {
			c = gfx_wait();
			xc = gfx_xpos();
			yc = gfx_ypos();
			randomizeball(&xc, &yc, &vx, &vy);
		}
		usleep(pausetime);
	}
	
	return 0;
}

void randomizeball(float *xc, float *yc, float *vx, float *vy) {
	*(xc) = gfx_xpos();
	*(yc) = gfx_ypos();
	*(vx) = (rand() % 12) - 6;
	*(vy) = (rand() % 12) - 6;
}
