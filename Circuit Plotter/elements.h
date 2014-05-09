#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "ccc_msw.h"
enum orientation { up, down, left, right };
class Element{
public:
	Point get_start_point();
	Point get_end_point();

	string get_unit();
	float get_value();
	virtual void draw(bool  simulate = false) = 0; // Pure Virtual Function will not allow inialization 
protected:
	Element(string u);
	Point start_point, end_point;
	float value;
	orientation orient;
	const string unit;

};
class Resistance :public Element {
public:

	Resistance(Point p, float v, orientation o);
	void draw(bool  simulate = false);
};
class Capacitor :public Element {
public:

	Capacitor(Point p, float v, orientation o);
	void draw(bool  simulate = false);

};
class Coil :public Element {
public:

	Coil(Point p, float v, orientation o);
	void draw(bool  simulate = false);

};
class VoltageSource :public Element {
public:

	VoltageSource(Point p, float v, orientation o);
	void draw(bool  simulate = false);

};
#endif