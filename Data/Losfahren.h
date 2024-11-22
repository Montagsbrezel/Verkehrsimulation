/*
 * Losfahren.h
 *
 *  Created on: 08.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef MEINEDATEIEN_LOSFAHREN_H_
#define MEINEDATEIEN_LOSFAHREN_H_

#include "Fahrausnahme.h"
class Weg;

class Losfahren :public Fahrausnahme {

public:
	Losfahren(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Losfahren();
	void vBearbeiten() override;

};

#endif /* MEINEDATEIEN_LOSFAHREN_H_ */
