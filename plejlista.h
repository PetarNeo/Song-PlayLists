#ifndef _plejlista_h_
#define _plejlista_h_
#include "pesma.h";

class Plejlista {

	int min = 0, sec = 0; //stvara se prazna, receno u zadatku pa znamo odma da je pocetno trajanje 0

	struct Elem {
		Pesma* pes;
		Elem* sled;

		Elem(Pesma* p, Elem* s = nullptr) : pes(p), sled(s) {}
	};
	Elem* prvi = nullptr;
public:

	Plejlista() = default;         //morali so da navedemo jer ako navedemo ova 2 ispod ovaj podrazumevani se brise
	Plejlista(const Plejlista& p);
	Plejlista(Plejlista&& p);
	~Plejlista();

	void dodaj(Pesma* p);
	void uredi();
	void pisi() const;
};

#endif
