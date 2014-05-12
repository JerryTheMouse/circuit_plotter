#include "elements.h"

int ccc_win_main(){
	Point p1(0, 0);
	Point p2(6, 6);
	Point p3(3, 9);
	Point p4(0, 6);
	Point p5(-3, 9);
	Point p6(-6, 6);
	VoltageSource v1(p1,p2, 0.8);
	Capacitor c1(p2, p3, 1);
	Capacitor c2(p3, p4, 1);
	Capacitor c3(p4, p5, 1);
	Capacitor c4(p5, p6, 1);

	VoltageSource v2(p6, p1, 0.8);

	v1.draw();
	v2.draw();

	c1.draw();
	c2.draw();
	c3.draw();
	c4.draw();
	Point p7(-5, -5);
	Coil  co1(p6, p7, 0.8);
	co1.draw();
	return 0;
}