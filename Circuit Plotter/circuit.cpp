#include "circuit.h"
Circuit::Circuit(){

};
Circuit::Circuit(string input)
{
	vector<string>s_elements;
	char * pch;
	char * cstr = new char[input.length() + 1];
	std::strcpy(cstr, input.c_str());

	pch = strtok(cstr, "-_");
	while (pch != NULL)
	{
		string s(pch);
		s_elements.push_back(s);
		pch = strtok(NULL, "-_");
	}

	vector<int>max_side_elements(4, 0); // Each Element Represent side
	int horizontal = ceil(s_elements.size() *3.0 / 5.0);
	int vertical = floor(s_elements.size() * 2.0 / 5.0);
	max_side_elements[0] = ceil(vertical / 2.0);
	max_side_elements[1] = ceil(horizontal / 2.0);
	max_side_elements[2] = floor(vertical / 2.0);
	max_side_elements[3] = floor(horizontal / 2.0);

	//Now we will calculate the circuit Width & Height
	const int min_element_space = 4;
	const double circuit_height = max(min_element_space * max_side_elements[0],2);

	const double circuit_width = max (min_element_space * max_side_elements[1],3);

	Point start_point(-circuit_width / 2.0, -circuit_height / 2.0);
	vector<string>::iterator iter = s_elements.begin();
	for (int i = 0; i < 4; i++)
	{
		int dx, dy;
		switch (i)
		{
		case 0:
			dy = 1;
			dx = 0;
			break;
		case 1:
			dy = 0;
			dx = 1;
			break;
		case 2:
			dy = -1;
			dx = 0;
			break;
		case 3:
			dy = 0;
			dx = -1;

		}
		const double side_length = i % 2 == 0 ? circuit_height : circuit_width;

		int elements_count = max_side_elements[i];
		if (elements_count > 0){
			for (int j = 0; j < elements_count; j++)
			{
				Element* myElement = 0;
				double value = stod((*iter).substr(1));
				Point  end_point = Point(start_point);
				end_point.move(dx*side_length/elements_count, dy*side_length/elements_count);
				switch (tolower((*iter)[0]))
				{
				case 'c':
					myElement = new Capacitor(start_point, end_point, value);
					break;
				case 'l':
					myElement = new Coil(start_point, end_point, value);
					break;
				case 'v':
					myElement = new VoltageSource(start_point, end_point, value);
					break;
				case 'r':
					myElement = new Resistance(start_point, end_point, value);
				}
				elements.push_back(myElement);
				myElement->draw();
				start_point = end_point;
				iter++;
			}

		}
		else{
			Point  end_point = Point(start_point);
			end_point.move(dx*side_length , dy*side_length );
			Line wire(start_point, end_point);
			cwin << wire;
			start_point = end_point;

		}
	}
}