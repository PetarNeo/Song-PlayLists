#ifndef _izvodjac_h_
#define _izvodjac_h_

#include <string>
using namespace std;

enum Zanr{POP,REP,ROK};

class Izvodjac {
	string naziv;
	Zanr zanr;
	static string str_zanr[];
public:
	Izvodjac(string naz, Zanr z) : naziv(naz), zanr(z) {};

	Zanr dogvZanr() const { return zanr; }
	void pisi() const;
};



#endif