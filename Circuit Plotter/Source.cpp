#include "elements.h"
int ccc_win_main(){
	Point p(0, 0);
	Point p2(-3, 6);
	cwin << p;

	Capacitor c(p,p2,2.5);

	c.draw();
	return 0;
}