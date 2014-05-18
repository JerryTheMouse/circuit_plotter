#include "elements.h"
#include "circuit.h"
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
	Resistance r1(p6, p1, 2);
	v1.draw();
	v2.draw();
	r1.draw();
	c1.draw();
	c2.draw();
	c3.draw();
	c4.draw();
	Sleep(1000);
	cwin.clear();
	Circuit a("V1_C2_C3.6_R5_L4_V3");

	return 0;
}
