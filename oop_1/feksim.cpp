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

double vlaszlo(const kocsi& k, double ml) {
	return sqrt((k.mass*pow(k.sebesseg, 2)) / ml);
}

double fektav(const double& v, const double& u, const double& g) {
	return pow(v, 2) / (2 * u*g);
}

double accel(const sim& s) {
	return s.k.sebesseg + s.k.acl * s.dt;
};

void simul (sim s, double ml) {

};

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
	int si=0;
	while (!be.eof()) {
		sim s;
		si++;
		be >> s.k.acl >> s.k.mass >> s.tfinal >> s.steps;
		cout << "Szimulacio " << si << "acl: "<< s.k.acl << "mass: " << s.k.mass << "tfinal: " << s.tfinal << "steps: " << s.steps <<"\n\n";
		s.dt = s.tfinal / s.steps;
		for (int i = 0; i < s.steps; i++) {
			s.k.sebesseg = accel(s);
			cout << "A " << i << ". iteracioban a kocsi jelenlegi sebessege" << s.k.sebesseg << endl;
			double vl = vlaszlo(s.k, ml);
			cout << "Laszlo az adott pilanatban " << vl << " sebessegel repulne\n";
		}

		double d = fektav(s.k.sebesseg, u, g);
		cout << "A fektav: " << d << "m.\n";
		cout << endl;
	}

	int temp;
	cin >> temp;
	cout << temp;
}