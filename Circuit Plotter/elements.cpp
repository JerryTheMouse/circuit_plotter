#include "elements.h"
Element::Element(string u) :unit(u){
};
Point Element::get_start_point() { return start_point; }
Point Element::get_end_point() { return end_point; }
float Element::get_value(){ return value; }
string Element::get_unit(){ return unit; }
Resistance::Resistance(Point p, float v, orientation o) :Element("Kohm"){
	start_point = p;
	value = v;
	orient = o;

};
void Resistance::draw(bool simulate){
};

Capacitor::Capacitor(Point p, float v, orientation o) :Element("nF"){
	start_point = p;
	value = v;
	orient = o;

};
void Capacitor::draw(bool simulate){
};
Coil::Coil(Point p, float v, orientation o) :Element("mH"){
	start_point = p;
	value = v;
	orient = o;
};
void Coil::draw(bool simulate){
};
VoltageSource::VoltageSource(Point p, float v, orientation o) :Element("V"){
	start_point = p;
	value = v;
	orient = o;
};
void VoltageSource::draw(bool simulate){
};