/*
 * Fahrrad.h
 *
 *  Created on: 21.11.2023
 *      Author: Moritz
 */
#pragma once
#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include <cmath>
#include "Fahrzeug.h"

//Vererbung
class Fahrrad : public Fahrzeug{
private:


public:
	Fahrrad(const std::string& sName, double dMaxGeschwindigkeit);
	//Deklaration der Funktionen
		virtual double dGeschwindigkeit() const override;
		virtual void vSimulieren()override;
	//dGesamtverbrauch gibt den Gesamtverbrauch an. Bei Fahrrädern jedoch Null
		virtual double dGesamtverbrauch() const override;
	//Gibt das maximale Tankvolumen an. Bei Fahrräder jedoch Null
		virtual double dTankvolumen() const override;
	//Gibt den aktuellen Tankinhalt an daktuellerTank wird nicht verwendet, weil es für mich zu verwirrend wäre
		virtual double dTankinhalt() const override;
	//Fahhrad kann nicht tanken
		virtual double dGetankteMenge() const override;
	//Ausgabe ob der Tank Voll oder Leer ist. Bei Fahrrad Null, da kein Tank vorhanden ist
		virtual std::string dTankVollOderLeer()const override;
	//Fahrrad::Ausgeben wurde erst nachträglich Hinzugefügt. Ein alternatives ausgeben ist noch Möglich
		void vAusgeben(std::ostream& out) const override;
	//Deklaration für Fahrrad Zeichnen
		void vZeichnen(const Weg& weg) const override;
	//Vergleichsoperator
		bool operator<(const Fahrrad& andere) const;
	//Verbieten von Copy-Konstroucktor
		Fahrrad(const Fahrrad& andere) = delete;
	//Zuweisungsoperator
		Fahrrad& operator=(const Fahrrad& andere);
	//Dekontruktor
		virtual ~Fahrrad();
};


#endif /* FAHRRAD_H_ */
