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
		// clear window
		if ((int) c == 27) {
			gfx_clear();
		}
		// white circle
		else if (c == 'c') {
			gfx_color(255, 255, 255);
			gfx_circle(xm, ym, SIZE/2);
			gfx_color(0, 0, 0);
			gfx_circle(xm, ym, SIZE/2 - 5);
		}
		

	}
}
