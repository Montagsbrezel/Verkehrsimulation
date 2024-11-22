/*
 * Fahren.h
 *
 *  Created on: 07.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef MEINEDATEIEN_FAHREN_H_
#define MEINEDATEIEN_FAHREN_H_

#include "Verhalten.h"
#include "Streckenende.h"

class Fahren : public Verhalten{
	public:
		Fahren(Weg& weg);
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override ;
		virtual ~Fahren();

};

#endif /* MEINEDATEIEN_FAHREN_H_ */
