/*
		Nezd meg a neten
*/

#include <iostream>
#include <random>
using namespace std;

constexpr int CHAIN_LENGTH = 100;

struct TemperatureElement {
	double temp, humidity;
	TemperatureElement* next;
};

struct TemperatureChain {
	TemperatureElement* next;
	TemperatureElement *first, *last;
	int cnt;
};

bool temperatureComfortable(const TemperatureElement& temp) {
	if (temp.temp < 15)
		return false;
	else if (temp.temp > 28)
		return false;
	else
		return true;
}

void print(TemperatureChain*& chain) {
	TemperatureElement* elem = chain->first;
	while (elem->next != NULL) {
		cout << "Temp: " << elem->temp << "Humid: " << elem->humidity << endl;
		elem=elem->next;
	}
}

bool checkTempreture(TemperatureChain*& chain) {
	TemperatureElement* elem = chain->first;
	while (elem->next != NULL) {
		if (!temperatureComfortable(*elem)) {

		}
	}
}

void appendlast(TemperatureChain*& chain, const double temp, const double humidity) {
	TemperatureElement* elem = new TemperatureElement();
	elem->next = NULL;
	if (chain == NULL) {
		chain = new TemperatureChain();
		chain->first = elem;
		chain->last = elem;
		chain->cnt = 1;
	}
	else {
		chain->last->next = elem;
		chain->last = elem;
		chain->cnt++;
	}
}

void addTemperatureElement(TemperatureChain*& chain) {
	//random numb. gen
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<double> dis_temp(10, 34);
	static std::uniform_real_distribution<double> dis_humidity(0.0, 1.0);
	appendlast(chain, dis_temp, dis_humidity);
}
void reset(TemperatureChain*&chain) {
	if (chain != NULL)
		TemperatureElement* elem = chain->first;
	while (elem != NULL) {
		TemperatureElement* tmp = elem;
		elem = elem->next;
		delete tmp;
		}
	delete chain;
	chain = NULL;
}

int main() {
	TemperatureChain* chain = NULL;
	const double min = 14, max = 28;
	for (int i = 0; i < CHAIN_LENGTH - 1; i++) {
		addTemperatureElement(chain);
	}
	print(chain);
	if (checkTemperature(chain)) {
		cout << "Temperature OK\n";
	}
	else
	{
		cout << "Temperature is uncomfortable\n";
	}
	int temp;
	cin >> temp;
	cout << temp;
}