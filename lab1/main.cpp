#include <iostream>
//#include <cstdlib>
#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC



#include "funcs.h"

using namespace Data;
using namespace std;

int info(){
	int h;
	do{
		cout << "What do you want me to do?\n" << "1) Read matrix.\n2) Read real matrix.\n3) Read modified matrix.\n4) Exit...\n";
	}while ((h = get_value("Your choise: ")) < 1 && h > 4);
	return h;
}

int main(){
    int n, m;
    n = get_value("Enter n: ");
    m = get_value("Enter m: ");
    Matrix* M = init_matrix(n, m, 1);
	read_matrix(M, m);
	Matrix* NM = mod_matrix(M);
	int h;
	while ((h = info())){
		switch (h){
			case 1: read_matrix(M, m); break;
			case 2: read_real_matrix(M, 1); break;
			case 3: read_real_matrix(NM, 0); break;
			case 4:
				clear_matrix(M);
				clear_matrix(NM);
				//free(NM);
				cout << "Adios!\n";
				return 0;
		}
	}
}
