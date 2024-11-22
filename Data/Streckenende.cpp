/*
 * Streckenende.cpp
 *
 *  Created on: 08.01.2024
 *      Author: Moritz
 */

#include "Streckenende.h"
#include "Weg.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"
#include <iostream>

extern double dGlobaleZeit;

	Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {

	}
	void Streckenende::vBearbeiten() {
		std::cout << "Name des Fahrzeuges in der die Ausnahme auftitt: " << p_pFahrzeug1.sGetName() << std::endl;
		std::cout << "Weg auf dem sich das Fahrzeug befindet: " << p_pWeg1.sGetName() << std::endl;
		std::cout << "Art der Ausnahme: Streckenende " << std::endl<< std::endl;
		//bLoescheFahrzeug(p_pFahrzeug1.sGetName());
		//p_pWeg1.pAbgabe(p_pFahrzeug1);

	//Fahrzeug auf einen zufälligen Weg in der Kreuzung umsetzen
		std::shared_ptr<Kreuzung> kreuzung = p_pWeg1.getZielKreuzung();

	//Tanken
		kreuzung->vTanken(p_pFahrzeug1);//Wenn aufgetank werden soll
		std::shared_ptr<Weg> rueckweg = kreuzung->pZufaelligerWeg(p_pWeg1);

	//Ausgabe
		std::cout << std::endl<<"ZEIT : " << dGlobaleZeit << std::endl;
		std::cout << "KREUZUNG : " << p_pWeg1.getZielKreuzung()->sGetName() << " Tankstelle: " << kreuzung->dGetTankstelle() << std::endl;
		std::cout << "WECHSEL : " << p_pWeg1.sGetName() << " → " << rueckweg->sGetName() << std::endl;
		std::cout << "FAHRZEUG : ";
		Fahrzeug::vKopf();
		std::cout<< p_pFahrzeug1 << std::endl<< std::endl;

	//Fahrzeug auf den neuen Weg umsetzen
		rueckweg->vAnnahme(p_pWeg1.pAbgabe(p_pFahrzeug1));

	}


	Streckenende::~Streckenende() {

	}

