#include "izvodjac.h"
#include <iostream>
using namespace std;

string Izvodjac::str_zanr[] = { "pop","rep","rok" };

void Izvodjac::pisi() const {
	cout << naziv << "(" << str_zanr[zanr] << ")";
}