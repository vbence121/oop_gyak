#include <iostream>
#include <fstream>
using namespace std;

struct kocsi {
	double sebesseg=0, mass, acl;
};

struct sim {
	kocsi k;
	double steps, tfinal, dt;
};

double vlaszlo(const kocsi k, double ml) {
	return sqrt((k.mass*pow(k.sebesseg, 2)) / ml);
}

double fektav(const double v, const double u, const double g) {
	return pow(v, 2) / (2 * u*g);
}


int main() {

	const double g = 9.81, u = 0.6;
	double ml=80;
	//kocsi k;
	/*cout << "Adja meg a kocsi es Laszlo sulyat kg-ban\n";
	cin >> k.mass >> ml;
	k.sebesseg = 0;

	cout << "Adja meg a kocsi gyorsulasat\n";
	cin >> k.acl;

	double steps = 100, tfinal = 10;
	*/

	ifstream be;
	be.open("be3.txt");

	while (!be.eof()) {
		sim s;
		be >> s.k.acl >> s.k.mass >> s.tfinal >> s.steps;
		s.dt = s.tfinal / s.steps;
		for (int i = 0; i < s.steps; i++) {
			s.k.sebesseg += s.k.acl * s.dt;
			cout << "A " << i << ". iteracioban a kocsi jelenlegi sebessege" << s.k.sebesseg << endl;
			double vl = vlaszlo(s.k, ml);
			cout << "Laszlo az adott pilanatban " << vl << " sebessegel repulne\n";
		}

		double d = fektav(s.k.sebesseg, u, g);
		cout << "A fektav: " << d << "m.\n";
	}

	int temp;
	cin >> temp;
	cout << temp;
}