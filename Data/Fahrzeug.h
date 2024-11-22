/*
 * Fahrzeug.h
 *
 *  Created on: 05.11.2023
 *      Author: Moritz
 */
#pragma once //Was ist das?
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_


#include <iostream>
#include <string>
#include <iomanip>
#include "Simulationsobjekt.h"
#include "Verhalten.h"
#include "SimuClient.h"

class Weg;
class Verhalten;
class Fahren;
class Parken;
class PKW;
	//wird der Abstrakten oberklasse Simulationsobjekt zugewiesen
class Fahrzeug : public Simulationsobjekt{
private:

protected :
	double p_dMaxGeschwindigkeit; //Const hat nicht geklappt
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dZeitintervall;
	std::string p_dTankVollOderLeer;
	double p_dAbschnittStrecke; // Neue Membervariable für die auf dem aktuellen Weg zurückgelegte Strecke
	double p_dZurückgelegteStrecke;
	std::unique_ptr<Verhalten> p_pVerhalten; // Hier wird der Smartpointer für das Verhalten hinzugefügt


public:
	// Konstruktor für Namen
		Fahrzeug(const std::string& sName);
	//Default-Konstruktor
		Fahrzeug();
	//Konstruktor mit Name und Maximalgeschwindigkeit
		Fahrzeug(const std::string& sName, double maxGeschwindigkeit);
	//Dekonstrucktor
		virtual ~Fahrzeug();
	// Funktion zum Ausgeben der Daten
		virtual void vAusgeben(std::ostream& out)const override;
	//Simulationsfunktion
		virtual void vSimulieren() override;
	//dGeschwindigkeit erstmal für Fahrräder
		virtual double dGeschwindigkeit() const;
	//dGesamtverbrauch für PKWs
		virtual double dGesamtverbrauch() const;
	//dTankvolumen für PKW und = Null für Fahrräder
		virtual double dTankvolumen() const;
	//Tankinhalt für PKWs
		virtual double dTankinhalt() const;
	//Getankte Menge
		virtual double dGetankteMenge()const;//Fixxen
	//Memberfunktion ob der Tank Voll oder Leer ist
		virtual std::string dTankVollOderLeer() const;
	//Für die Änderung des Verhaltens
	// Funktion, um die Strecke für ein gegebenes Zeitintervall zu berechnen
		double dStreckeBerechnen(double dZeitintervall);
	//Zum setzten der Startzeit
		void vSetStartzeit(double dStartzeit);
	//Funktion zum Setzen eines neuen Weges hier: Fahren
		virtual void vNeueStrecke(Weg& weg);
	//Funktion zum Setzen eines neuen Weges hier: Parken
		virtual void vNeueStrecke(Weg& weg, double dStartzeitpunkt);
		Verhalten* getVerhalten() const;
	// Getter für die Strecke auf dem aktuellen Weg
		double getAbschnittStrecke();
		virtual double dGetLaenge()const;
	//Deklaration der virtuellen Funktion vDoTanken
		virtual void vDoTanken();
	//PKW Deklaration für bZeichne PKW
		virtual void vZeichnen(const Weg& weg)const ;
	//Vergleichsoperator
		bool operator<(const Fahrzeug& andere) const;
	//Verbieten von Copy-Konstroucktor
		Fahrzeug(const Fahrzeug& andere) = delete;
	//Zuweisungsoperator
		Fahrzeug& operator=(const Fahrzeug& andere);
		std::string sGetName() const;

};

#endif /* FAHRZEUG_H_ */
