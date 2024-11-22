/*
 * Losfahren.cpp
 *
 *  Created on: 08.01.2024
 *      Author: Moritz
 */

#include "Losfahren.h"

	Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {

	}

	void Losfahren::vBearbeiten() {
		std::cout << "Name des Fahrzeuges in der die Ausnahme auftitt: " << p_pFahrzeug1.sGetName() << std::endl;
		std::cout << "Weg auf dem sich das Fahrzeug befindet: " << p_pWeg1.sGetName() << std::endl;
		std::cout << "Art der Ausnahme: Losfahren " << std::endl;
	//Fahrzeug wird abgegeben an pFahrzeugKopie
		auto pFahrzeugKopie = p_pWeg1.pAbgabe(p_pFahrzeug1);//Schieben der Refferenz des Fahrzeugs. Zeigen einen neuen Pointer und geben diesen weiter
		p_pWeg1.vAnnahme(move(pFahrzeugKopie));
	}
	Losfahren::~Losfahren() {

	}
