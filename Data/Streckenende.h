/*
 * Streckenende.h
 *
 *  Created on: 08.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef MEINEDATEIEN_STRECKENENDE_H_
#define MEINEDATEIEN_STRECKENENDE_H_

#include "Fahrausnahme.h"

//class Fahrzeug;

class Streckenende :public Fahrausnahme{
public:
	void vBearbeiten() override;
	void vTankenInKreuzung();
	Streckenende(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Streckenende();

};

#endif /* MEINEDATEIEN_STRECKENENDE_H_ */
