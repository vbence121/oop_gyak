#include <iostream>
#include <fstream>
using namespace std;

int main() {
	double betett, kivant, kamat, i;
//	float osszeg;
//	i = 0;
/*
	cout << "Adja meg a betett osszeget!\n";
	cin >> betett;
//	osszeg = betett;
	cout << "Adja meg a kamatot!\n";
	cin >> kamat;
	kamat = kamat / 100;
	cout << "Adja meg a kivant osszeget!\n";
	cin >> kivant;
	*/

	ifstream fin;
	fin.open("be.txt");
	while (!fin.eof()) {
		fin >> betett;
		fin >> kamat;
		fin >> kivant;
	}

/*	while (osszeg < kivant) {
		osszeg = osszeg * kamat;
		i++;
	}
	cout << i << " év utan kapjuk meg a kivant osszeget";
		*/

	i=(log(kivant / betett))/(log(1 + kamat));
	cout << i << " ev utan kapjuk meg a kivant osszeget\n";

	/*
	ofstream fout;
	fout.open("ki.txt");
	fout << betett << endl << kamat << endl << kivant;
	*/

	int temp;
	cin >> temp;
	cout << temp;
}