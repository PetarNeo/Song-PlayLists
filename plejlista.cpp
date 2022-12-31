#include "plejlista.h"

Plejlista::Plejlista(const Plejlista& p) {
	min = p.min;
	sec = p.sec;
	Elem* tek = p.prvi;
	Elem* novi = nullptr, *posl = nullptr;
	while (tek) {
		novi = new Elem(tek->pes);
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
		tek = tek->sled;
	}
}

Plejlista::Plejlista(Plejlista&& p) {
	min = p.min;
	sec = p.sec;
	prvi = p.prvi;         //plitke kopije ovde
	p.prvi = nullptr;
}

Plejlista::~Plejlista() {
	Elem* tek = prvi, * stari;
	while (tek) {
		stari = tek;
		tek = tek->sled;
		delete stari;
	}
}

void Plejlista::dodaj(Pesma* p) {
	prvi = new Elem(p, prvi);
	min = min + p->dohvMin() + (sec + p->dohvSec()) / 60;
	sec = (sec + p->dohvSec()) % 60;
}

void Plejlista::uredi() {
	for (Elem *t1 = prvi; t1->sled; t1 = t1->sled )
		for (Elem* t2 = t1->sled; t2; t2 = t2->sled) {
			if (duze(*t1->pes, *t2->pes)) {
				Pesma* p = t1->pes;
				t1->pes = t2->pes;
				t2->pes = p;
			}
		}
}

void Plejlista::pisi() const {
	cout << "Lista - trajanje: " << min << ":" << sec << endl;
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		tek->pes->pisi();
	}
}