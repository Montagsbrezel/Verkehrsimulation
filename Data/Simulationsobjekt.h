/*
 * Simulationsobjekt.h
 *
 *  Created on: 28.12.2023
 *      Author: morit
 */
#pragma once
#ifndef MEINEDATEIEN_SIMULATIONSOBJEKT_H_
#define MEINEDATEIEN_SIMULATIONSOBJEKT_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <vector>
#include <iomanip>
#include <list>
#include <random>



//Oberklasse von Fahrzeug und Weg und somit in der Hirachie ganz oben
class Simulationsobjekt {
private:
	static inline int p_iMaxID = 1;

protected:

		const std::string p_sName;
		const int p_iID = p_iMaxID++;
		double p_dLokaleZeit = 0;

public:
		Simulationsobjekt(const std::string& sName);
		Simulationsobjekt();
		virtual ~Simulationsobjekt();
	//Freundschaft wird angefragt
		friend std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& simObjekt);
		std::ostream& operator<<(std::ostream& out);
	//Funktion fürs Simulieren
		virtual void vSimulieren();
	//Funktion für die Überschrift setw statt setiosflags genommen, da ich den nicht ganz verstanden habe
		static void vKopf();
	// Funktion zum Ausgeben der Daten
		virtual void vAusgeben(std::ostream& out) const;
//Deklaration der Getter
	//Deklaration für sGetName
		std::string sGetName() const;
	//Getter für die ID
		virtual double dGetID()const;
	//Getter für das Tempolimit
		virtual double dGetTempolimit()const;
	//Getter für die Länge des Weges
		virtual double dGetLaenge() const;
		/*virtual void vGetTanken();
		virtual double dGetTankstelle() const;*/
	//RandDouble wird für zufällige Werte Deklariert
		double randDouble(int lower, int upper);
	//Vergleichsoperator soll bei zwei gleichen IDs den Wert true ausgeben
		bool operator==(const Simulationsobjekt& andere) const;
	//verbieten des Copy-Konstruktor
		Simulationsobjekt(const Simulationsobjekt& andere) = delete;
	//Zuweisungsoperator noch unfertig
		Simulationsobjekt& operator=(const Simulationsobjekt& andere) /*= delete*/;

};

#endif /* MEINEDATEIEN_SIMULATIONSOBJEKT_H_ */
