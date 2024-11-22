/*
 * Verhalten.cpp
 *
 *  Created on: 04.01.2024
 *      Author: Moritz
 */
#include "Verhalten.h"

Verhalten::Verhalten(Weg& weg) : p_pWeg(&weg)/*, weg(weg)*/{}

		double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
			return 0.0;
		}

		Weg* Verhalten::getWeg() const {
			return p_pWeg;
		}


	Verhalten::~Verhalten(){
	}
