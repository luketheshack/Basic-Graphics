// Luke Marushack
// Fundamentals of Computing : Lab #9
// bounce.c

#include "gfx.h"

int main() {
	int wd = 500, ht = 400;
	char c = 0;
	float xc, yc; // ball x-pos and ball y-pos
	float vx, vy; // ball velocity x and velocity y
	int pausetime = 5000;
		
	gfx_open(wd, ht, "Bouncing Ball");

	while (c != 'q') {
		while (1) {

		}
		c = gfx_wait();
	}
	
	return 0;
}
