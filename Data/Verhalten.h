/*
 * Verhalten.h
 *
 *  Created on: 04.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef MEINEDATEIEN_VERHALTEN_H_
#define MEINEDATEIEN_VERHALTEN_H_

#include "Fahrzeug.h" // Für die Fahrzeug-Klasse
#include "Weg.h"

class Weg; // Vorwärtsdeklaration für die Weg-Klasse
class Fahrzeug;

class Verhalten {
protected:

	Weg* p_pWeg;
private:
	//Weg& weg; // Referenz auf den Weg für dieses Verhalten

public:
	// Deklaration des Konstruktors
		Verhalten(Weg& weg);
		Weg* getWeg()const;
	// Deklaration der dStrecke-Funktion
		virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);
		virtual ~Verhalten();
};

#endif /* MEINEDATEIEN_VERHALTEN_H_ */
