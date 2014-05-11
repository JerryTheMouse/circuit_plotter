#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "ccc_msw.h"
class Element{
public:
	Point get_start_point();
	Point get_end_point();
	string get_unit();
	float get_value();

	virtual void draw() = 0; // Pure Virtual Function will not allow inialization 
protected:
	Element(string u);

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