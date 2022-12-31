#ifndef _pesma_h_
#define _pesma_h_
#include <iostream>
#include <string>
#include "izvodjac.h"
using namespace std;

class Pesma {

	string naziv;
	int min, sec, kap, br; //br je br trenutninh dodatih izvodajca
	Izvodjac** izv;

public:
	Pesma(int m, int s, string naz, int k) : min(m), sec(s), naziv(naz) {
		izv = new Izvodjac * [kap = k];
	}
	Pesma(const Pesma& p) = delete; //zabranili smo da se poziva kopirajuci konstruktor

	int dohvMin() const { return min; }
	int dohvSec() const { return sec; }

	friend bool duze(const Pesma& p1, const Pesma& p2) {
		if (p1.min == p2.min) {
			return p1.sec > p2.sec;
		}
		else return p1.min > p2.min;
	}

	void dodaj(Izvodjac* i) {
		if (br < kap)
			izv[br++] = i;
	}
	void pisi() const;
};
#endif