/*
 * Parken.cpp
 *
 *  Created on: 07.01.2024
 *      Author: Moritz
 */

#include "Parken.h"


extern double dGlobaleZeit;
Parken::Parken(Weg& weg, double dStartzeitpunkt) : Verhalten(weg), p_dStartzeitpunkt(dStartzeitpunkt) {

}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
// Toleranz für Vergleiche
	constexpr double toleranz = 0.00001;
	if (dGlobaleZeit >= p_dStartzeitpunkt - toleranz) 	{
		std::cout << "=> " << aFzg.sGetName() << " hat Startzeitpunkt erreicht" << std::endl;
		Losfahren* losfahren= new Losfahren(aFzg, *p_pWeg);
		throw losfahren;
	}else {
		return 0.0;
	}
}

Parken::~Parken() {

}
