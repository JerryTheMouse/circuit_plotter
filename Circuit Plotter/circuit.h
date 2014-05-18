#ifndef CIRCUIT_H
#define CIRCUIT_H
#include<vector>
#include<string>
#include"elements.h"

class Circuit{

private:
	vector<Element*> elements;
public:
	Circuit();
	Circuit(string);
};
#endif