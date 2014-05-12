#include "elements.h"
#define PI 3.1428571428571428571

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
	float radius = 0.4;
	float dx = sqrt(2 * radius*radius);
	Point wire_1_start (0, -5);
	Point wire_1_end(wire_1_start);
	wire_1_end.move(3, 0);
	Line wire(wire_1_end, wire_1_start);
	cwin << wire;

	Point coil_center(wire_1_end);
	coil_center.move(0, -radius);

	draw_partial_circle(coil_center, radius, -0.25*PI, PI/2);

	for (int i = 0; i < 1; i++)
	{
		Point * test = new Point(0, -1);

	}
	return 0;
}