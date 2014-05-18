#ifndef ELEMENTS_H
#define ELEMENTS_H
#define PI 3.14285714

#include "ccc_msw.h"

void rotate(Point*& p, float angle, Point* axis);
void draw_partial_circle(Point center, float radius, float start_angle, float end_angle);

class Element{

public:
	Point get_start_point();
	Point get_end_point();
	string get_unit();
	float get_value();

	virtual void draw() = 0; // Pure Virtual Function will not allow initialization 
protected:
	Element(Point start, Point end, float v,string u);

	void calculate_angle_with_x();
	float angle;

	Point start_point, end_point;
	float value;

	void calculate_length();
	float length;
	const string unit;

};
class Resistance :public Element {
public:

	Resistance(Point start,Point end, float v );
	void draw();
};
class Capacitor :public Element {
public:

	Capacitor(Point start, Point end, float v);
	void draw();

};
class Coil :public Element {
public:

	Coil(Point start, Point end, float v);
	void draw();

};
class VoltageSource :public Element {
public:

	VoltageSource(Point start, Point end, float v);
	void draw();

};
#endif