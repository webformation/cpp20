#include <iostream>
#include <thread>
#include <syncstream>
using namespace std;

void g() {
	osyncstream sortie(cout);
	sortie << "thread fonction" << endl;
}
struct Foncteur {
	int k;
	void operator()() {
		osyncstream sortie(cout);
		sortie << "thread foncteur " << k << endl;
	};
};
int main() {
	auto f = []() {
		osyncstream sortie(cout);
		sortie << "thread fonction lambda" << endl;
	};
	jthread t1(f), t2(g), t3(Foncteur{ 10 });
	return 0;
}