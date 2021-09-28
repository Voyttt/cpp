#ifndef arch_spiral_h
#define arch_spiral_h

using namespace std;

class Archimed_Spiral{
	int k;
	float r;

	private:
	
		template <typename T>
		T get_value(T n, const char* k){
			while(true) {
        		cout << k;
        		cin >> n;
        		if (cin.fail()) {
        		    cin.clear();
        		    cin.ignore(5534, '\n');
					cout << "Try again: ";
        		}
       			else return n;
    		}
		}

		float get_phi(){
			cout << "Enter a and b to receive angle in form (pi * a) / b.\n";
			int a = get_value(a, "Enter a: ");
			int b = get_value(b, "Enter b: ");
			return (pi * a) / b;
		}

	public:
		
		Archimed_Spiral(){
			k = get_value(k, "Enter k: ");
			r = 2 * pi * k;
		};

		float dist_to_centre(){
			float phi = get_phi();
			return k * phi;
		}

		float square_of_sector(){
			float a = get_value(a, "Enter first radium: ");
			float b = get_value(b, "Enter second radium: ");
			float phi = (a > b ? a : b) / k;
			return (phi * (pow(a, 2) + pow(b, 2) + a * b)) / 6;
		}

		float square_of_n_figure(){
			int n = get_value(n, "Enter n: ");
			return (pow(n, 3) - pow(n - 1, 3)) / 3 * pi * pow(r, 2);
		}

		float square_of_n_spiral(){
			int n = get_value(n, "Enter n: ");
			return 2 * n * pi * pow(r, 2);
		}

		float lengh_of_arc(){
			float phi = get_phi();
			float f = sqrt(pow(phi, 2) + 1);
			return (k / 12.0) * (phi * f + log(phi + f));
		}

		float rad_of_curv(){
			float phi = get_phi();
			float f = pow(phi, 2) + 1;
			return k * pow(f, 3 / 2) / (f + 1);
		}

		int ask(){
			int h;
			do{
				cout << "What do you want?\n1) Distance from centre to point of spiral with angel.\n2) Square of sector between two polar radius.\n3) Square of figure limitted by n-turn of spiral.\n4) Square of n-ring of spiral.\n5) Arc lengh to a given polar radium.\n6) Curvature radium of spiral with given polar angle.\n7) Exit...\n";
			}while (((h = get_value(h, "Your choice: ")) < 1 && h > 7));
			return h; 
		}

};

#endif //arch_spiral_h