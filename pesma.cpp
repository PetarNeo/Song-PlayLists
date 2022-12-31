#include <iostream>
#include "izvodjac.h"
#include "pesma.h"
using namespace std;

void Pesma::pisi()const {
	cout << "P(" << naziv << " - " << min << ":" << sec << ")" << endl;
	cout << "Izvodjaci: " << endl;
	for (int i = 0; i < br; i++) {
		izv[i]->pisi();
		cout << endl;
	}
}