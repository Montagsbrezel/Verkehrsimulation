/*
 * Fahren.cpp
 *
 *  Created on: 07.01.2024
 *      Author: Moritz
 */

#include "Fahren.h"
#include "Streckenende.h"


Fahren::Fahren(Weg& weg) : Verhalten(weg) {

}



double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
	if (p_pWeg->dGetLaenge() > aFzg.getAbschnittStrecke()) {
		double dMoeglicheStrecke = dZeitIntervall * aFzg.dGeschwindigkeit();
		double dAbstandStrecke = p_pWeg->dGetLaenge() - aFzg.getAbschnittStrecke();
		if (dMoeglicheStrecke <= dAbstandStrecke) {
			return dMoeglicheStrecke;
		}
		return dAbstandStrecke;
	}
	else {
		std::cout << "=> " << aFzg.sGetName() << " ist am Ende des Weges angekommen" << std::endl;
		Streckenende* streckenende= new Streckenende(aFzg,*p_pWeg);
		throw streckenende;
	}
}

Fahren::~Fahren() {

}
