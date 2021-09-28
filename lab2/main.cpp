#include <iostream>
#include <cmath>

#define  pi M_PI

#include "arch_spiral.h"

int main() {
	//using namespace Figure;
	Archimed_Spiral AS;
	/*
	float (*funcs[])() = {AS.dist_to_centre(),
		AS.square_of_sector(), AS.square_of_n_figure(),
		AS.square_of_n_spiral(), AS.lengh_of_arc(), 	
		AS.rad_of_curv()};*/
	int h;
	float f;
	while((h = AS.ask()) != 7){
		switch(h){
			case 1: f = AS.dist_to_centre(); break;
			case 2: f = AS.square_of_sector(); break;
			case 3: f = AS.square_of_n_figure(); break;
			case 4: f = AS.square_of_n_spiral(); break;
			case 5: f = AS.lengh_of_arc(); break;
			case 6: f = AS.rad_of_curv(); break;
		}cout << f << endl; 
	};
	
	cout << "BB...\n";
	return 0;
}