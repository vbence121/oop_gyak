#include <iostream>
#include <fstream>
using namespace std;

struct harom {
	double a, b, c, t, s;
};

double heron(const harom& k) {
	return sqrt(k.s*(k.s - k.a)*(k.s - k.b)*(k.s - k.c));
}

int main() {

	ifstream fin;
	fin.open("be2.txt");
	while (!fin.eof()) {
		harom k;

		//cout << "Adja meg az oldalak nagysagat cm-ben\n";
		fin >> k.a >> k.b >> k.c;

		if (((k.a + k.b) > k.c) && ((k.a + k.c) > k.b) && ((k.c + k.b) > k.a)) {
			k.s = (k.a + k.b + k.c) / 2;
			k.t = heron(k);

			cout << "A(z) ("<<k.a<<","<<k.b<<","<<k.c<<") haromszog terulete " << k.t << endl;
		}
		else cout << "A(z) (" << k.a << "," << k.b << "," << k.c << ") haromszog nem letezik\n";
	}
	
	int temp;
	cin >> temp;
	cout << temp;
}