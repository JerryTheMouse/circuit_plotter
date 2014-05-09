#include "elements.h"
int ccc_win_main(){
	Point p(2, 3);
	cwin << p;
	Element *e = new Resistance(p, 2.5, orientation::up);

	return 0;
}