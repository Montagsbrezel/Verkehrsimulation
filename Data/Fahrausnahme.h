/*
 * Fahrausnahme.h
 *
 *  Created on: 08.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception>
#include "Fahrzeug.h"
#include "Weg.h"
//using namespace std;

class Weg;
class Fahrzeug;

class Fahrausnahme : public std::exception {

public:
	Fahrausnahme(Fahrzeug& fahrzeug1, Weg& weg1);
	virtual void vBearbeiten();
	virtual ~Fahrausnahme();

protected:
	Fahrzeug& p_pFahrzeug1 ;
	Weg& p_pWeg1 ;
};

#endif /* FAHRAUSNAHME_H_ */

//throw lößt eine Ausnahme bei einem Problem aus
//catchFängt eine Ausnahme mit Ausnahmehandlung an der Stelle des Programms an , an der das Problem behandelt werden soll
