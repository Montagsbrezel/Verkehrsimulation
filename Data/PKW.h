/*
 * PKW.h
 *
 *  Created on: 21.11.2023
 *      Author: Moritz
 */
#pragma once
#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <limits>
#include <cmath>
#include <iomanip>

//Verebung
class PKW : public Fahrzeug {
private :
	const double p_dVerbrauch;
	const double p_dTankvolumen;
	double p_dTankinhalt;
	double p_dGesamtverbrauch = 0.0;
	double p_dGetankteMenge = 0.0;
	double p_dTankenNach = 0.0;


public:
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dMaxTankvolumen);
	//Deklarieren der Funktionen Tanken
		double dTanken(void);
	//Immer Tanken
		virtual void dImmerTanken();
	//Tanken bei Liegengebliebenen Fahrzeugn
		virtual void dLiegengebliebeneFahrzeugVolltanken();
	//Deklaration für Liegenbleiben
		virtual void dLiegenbleiben();
	//Tanken für Kreuzung
		virtual void vDoTanken()override;
//Wichtig das wurde eingefügt um die Ausgabe aller Werte in Fahrzeug zu ermöglichen, da es so für MICH übersichtlicher war. Die Ausgabefunktion der Unterklasse habe ich erst später gemacht
	//Für die Geschwindigkeit des Fahrzeugs die immer maximal ist (Deklaration)
		virtual double dGeschwindigkeit() const override;
	//dGesamtverbrauch gibt den Gesamtverbrauch an und überschreibt ihn in Fahrzeug. Hier aber nur die deklaration
		virtual double dGesamtverbrauch() const override;
	//Gibt das maximale Tankvolumen von PKWs an und überschreibt die Funktion in Fahrzeug
		virtual double dTankvolumen() const override;
	//Gibt den aktuellen Tankinhalt an dAktuellerTank wird nicht verwendet, weil es für mich zu verwirrend wäre
		virtual double dTankinhalt() const override;
	//Für die Ausgabe der getankten Menge
		virtual double dGetankteMenge() const override;
	//Ausgabe ob der Tank Voll oder Leer ist
		virtual std::string dTankVollOderLeer()const override;
	//Deklaration von dGeschwindigkeit und vSimulieren
		virtual void vSimulieren() override;
	//Falls gewünsch Backup Ausgabefunktion bei der man nicht auf Fahrzeug::vSimulieren wartet sondern diese Überschrieben wird hier Deklaration es muss const in Fahrzeug::vAusgabe und die Ausgabe muss gelöscht werden
		virtual void vAusgeben(std::ostream& out)const override;
	//PKW Deklaration für bZeichne PKW
		void vZeichnen(const Weg& weg)const override;
	//Vergleichsoperator
		bool operator<(const PKW& andere) const;
	//Verbieten von Copy-Konstroucktor
		PKW(const PKW& andere) = delete;
	//Zuweisungsoperator
		PKW& operator=(const PKW& andere);
		virtual ~PKW();
};


#endif /* PKW_H_ */
