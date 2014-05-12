#include "elements.h"
#include<math.h>
#include <vector>

void rotate(Point*& p,float angle,Point* axis){
	float new_x =axis->get_x() + ( (p->get_x() -axis->get_x()) *cos(angle) - (p->get_y()- axis->get_y())*sin(angle));
	float new_y = axis->get_y() + ((p->get_x() - axis->get_x()) *sin(angle) + (p->get_y() - axis->get_y())*cos(angle));

	p = new Point(new_x, new_y);
}

void draw_partial_circle(Point center, float radius, float start_angle, float end_angle){
	float angle = start_angle;
	float angle_range = end_angle - start_angle;
	int iterations = 100;
	float	d_theta = angle_range / iterations;
	Point* Previous = new Point();
	for (int i = 0; i < iterations; i++)
	{
		Point* p = new Point(center);
		p->move(radius, 0);
		rotate(p, angle, &center);

		if (i != 0)
		{
			Line l(*Previous, *p);
			cwin << l;
		}
		*Previous = *p;
		angle += d_theta;

	}
};


Element::Element(Point start, Point end, float v,string u) :unit(u){
	start_point = start;
	end_point = end;
	value = v;
	calculate_length();
	calculate_angle_with_x();
};

Point Element::get_start_point() { return start_point; }
Point Element::get_end_point() { return end_point; }
float Element::get_value(){ return value; }
string Element::get_unit(){ return unit; }

void Element::calculate_length(){

	float dx = start_point.get_x() - end_point.get_x();
	float dy = start_point.get_y() - end_point.get_y();
	length = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
}

void Element::calculate_angle_with_x(){
	float dx = end_point.get_x() - start_point.get_x();
	float dy = end_point.get_y() - start_point.get_y();
	angle = atan2(dy , dx);
}
Resistance::Resistance(Point start,Point end, float v) :Element(start,end,v,"Kohm"){


};
void Resistance::draw(){
};

Capacitor::Capacitor(Point start, Point end, float v) :Element(start, end, v, "nF"){

	

};
void Capacitor::draw(){
	vector<Point**>points_to_rotate;
	float element_width = 0.5;
	float element_height = 1.0;
	float wire_length = (length - element_width) / 2.0;

	//Now we will calculate the first piece of wire points
	// Note we won't rotate wire_1_start because it's the start of the element
	Point *wire_1_start = new Point(start_point);
	Point* wire_1_end = new Point( start_point);
	wire_1_end->move(wire_length, 0);
	points_to_rotate.push_back(&wire_1_end);

	//Now we will calculate the first side of capacitor points
	Point* first_side_top  = new Point(*wire_1_end);
	first_side_top->move(0, element_height/ 2);
	Point* first_side_bottom = new Point(*wire_1_end);
	first_side_bottom->move(0, -element_height / 2);

	points_to_rotate.push_back(&first_side_top);
	points_to_rotate.push_back(&first_side_bottom);

	//Now we will calculate the second side of capacitor points

	Point* second_side_top = new Point(*first_side_top);
	second_side_top->move(element_width, 0);
	Point* second_side_bottom = new Point(*first_side_bottom);
	second_side_bottom->move(element_width, 0);

	points_to_rotate.push_back(&second_side_top);
	points_to_rotate.push_back(&second_side_bottom);

	//Now we will calculate the second piece of wire points
	// Note we won't rotate wire_2_end because it's the start of the element
	Point *wire_2_start = new Point(*second_side_top);
	wire_2_start->move(0, -element_height / 2);
	Point* wire_2_end = new Point(end_point);
	points_to_rotate.push_back(&wire_2_start);
	for (std::vector<Point**>::iterator it = points_to_rotate.begin(); it != points_to_rotate.end(); ++it)
	{
		rotate(**it,angle,wire_1_start);
	}

	// Now we will begin the Drawing..
	Line wire_1(*wire_1_start, *wire_1_end);
	Line first_side(*first_side_top, *first_side_bottom);
	Line second_side(*second_side_top, *second_side_bottom);
	Line wire_2(*wire_2_start, *wire_2_end);
	cwin << wire_1 << first_side << second_side << wire_2;

};
Coil::Coil(Point start, Point end, float v) :Element(start, end, v,"mH"){

};
void Coil::draw(){
	//{
	//	vector<Point**>points_to_rotate;
	//	float coil_turn_radius = 0.3;
	//	int coil_turns = 4;
	//	float wire_length = (length - (2 * coil_turns+2)*coil_turn_radius) / 2.0;

	//	//Now we will calculate the first piece of wire points
	//	// Note we won't rotate wire_1_start because it's the start of the element
	//	Point *wire_1_start = new Point(start_point);
	//	Point* wire_1_end = new Point(start_point);
	//	wire_1_end->move(wire_length, 0);
	//	points_to_rotate.push_back(&wire_1_end);

	//	//Now we will calculate the first side of capacitor points
	//	Point *coil_center = new Point(*wire_1_end);
	//	coil_center->move(0, -radius);

	//	draw_partial_circle(coil_center, radius, -0.25*PI, PI / 2);

	//	for (int i = 0; i < 5; i++)
	//	{

	//		coil_center.move(dx, 0);
	//		draw_partial_circle(coil_center, radius, -0.25*PI, 1.25*PI);

	//	}

	//	//Now we will calculate the second piece of wire points
	//	// Note we won't rotate wire_2_end because it's the start of the element
	//	Point *wire_2_start = new Point(*circle_center);
	//	wire_2_start->move(circle_radius, 0);
	//	Point* wire_2_end = new Point(end_point);
	//	points_to_rotate.push_back(&wire_2_start);

	//	// Now we rotate them
	//	for (std::vector<Point**>::iterator it = points_to_rotate.begin(); it != points_to_rotate.end(); ++it)
	//	{
	//		rotate(**it, angle, wire_1_start);
	//	}

	//	// Now we will begin the Drawing..
	//	Line wire_1(*wire_1_start, *wire_1_end);
	//	Circle source(*circle_center, circle_radius);
	//	Line wire_2(*wire_2_start, *wire_2_end);
	//	cwin << wire_1 << source << wire_2;
	//};

};
VoltageSource::VoltageSource(Point start, Point end, float v) :Element(start, end, v,"V"){

};
void VoltageSource::draw(){
	vector<Point**>points_to_rotate;
	float circle_radius = 0.8;
	float wire_length = (length - 2 * circle_radius) / 2.0;

	//Now we will calculate the first piece of wire points
	// Note we won't rotate wire_1_start because it's the start of the element
	Point *wire_1_start = new Point(start_point);
	Point* wire_1_end = new Point(start_point);
	wire_1_end->move(wire_length, 0);
	points_to_rotate.push_back(&wire_1_end);

	//Now we will calculate the first side of capacitor points
	Point* circle_center = new Point(*wire_1_end);
	circle_center->move(circle_radius,0);
	points_to_rotate.push_back(&circle_center);



	//Now we will calculate the second piece of wire points
	// Note we won't rotate wire_2_end because it's the start of the element
	Point *wire_2_start = new Point(*circle_center);
	wire_2_start->move(circle_radius,0);
	Point* wire_2_end = new Point(end_point);
	points_to_rotate.push_back(&wire_2_start);

	// Now we rotate them
	for (std::vector<Point**>::iterator it = points_to_rotate.begin(); it != points_to_rotate.end(); ++it)
	{
		rotate(**it, angle, wire_1_start);
	}

	// Now we will begin the Drawing..
	Line wire_1(*wire_1_start, *wire_1_end);
	Circle source(*circle_center, circle_radius);
	Line wire_2(*wire_2_start, *wire_2_end);
	cwin << wire_1 << source  << wire_2;
};