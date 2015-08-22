#include "elements.h"
#include "circuit.h"
int ccc_win_main(){
	while (true){
	Message m(Point(-10, 9), "Please Enter circuit elements to be drawn");
	cwin << m;
	string input = cwin.get_string("");
	cwin.clear();
	Circuit a(input);
	Circuit b(input);
	}
	return 0;
}
