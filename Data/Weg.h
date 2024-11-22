/*
 * Weg.h
 *
 *  Created on: 28.12.2023
 *      Author: morit
 */
#pragma once
#ifndef MEINEDATEIEN_WEG_H_
#define MEINEDATEIEN_WEG_H_

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"
#include "Fahrausnahme.h"
#include "vertagt_liste.h"
#include "Kreuzung.h"

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <list>
#include <stdexcept>
#include <mutex>
#include <random>


class Fahrzeug;
class Fahrausnahme;
class Kreuzung;

class Weg : public Simulationsobjekt {
private:
		double p_dLaenge; // Länge in km
		const int p_iTempolimit;
		bool p_bUeberholverbot;


protected:
				vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge; //Fahrzeugliste
				const std::weak_ptr<Kreuzung> p_pZielKreuzung; //Für den Fall, dass er wieder auf sich selbst verweist
				std::weak_ptr<Weg> p_pRueckweg; //Warum shared Pointer?

public:

		Weg(); // Standardkonstruktor
		//Weg(const std::string sName, double dLaenge, int iTempolimit , bool bUeberholverbot);

		Weg(const std::string sName, double dLaenge, int iTempolimit = 3, bool bUeberholverbot = false, std::weak_ptr<Kreuzung> pZielKreuzung = std::weak_ptr<Kreuzung>());/*, std::weak_ptr<Kreuzung> pZielKreuzung)*/;

	//Funktion zum Hinzufügen eines Fahrzeugs auf den Weg
		virtual void addFahrzeug(std::unique_ptr<Fahrzeug> fahrzeug);
	//Deklaration von der Funktion, welche die Fahrzeuge auf dem Weg zeichnen soll
		void vZeichneFahrzeuge();
	//Überschriebene Simulationsfunktion
		virtual void vSimulieren() override;
	//Kopf-Funktion
		static void vKopf();
	//Implementierung von vAusgeben für Weg
		virtual void vAusgeben(std::ostream& out) const override;
	// Neue Funktion, um ein Fahrzeug auf dem Weg anzunehmen
		void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);
	//Deklaration für das parkende Fahrzeug
		void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt);
	//Getter für die ID
		virtual double dGetID()const override;
	//Getter für die Länge
		virtual double dGetLaenge() const override;
	//Getter für das Tempolimit
		Tempolimit getTempolimit() const;
	//Getter, welcher zur Umwandlung des Tempolimits in eine Geschwindigkeit dient
		virtual double dGetTempolimit()const;
	//Umwandlung des Fahrverhaltens und bearbeitung der Liste
		std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);
	//Gibt eine leere Fahrzeugliste
		//bool bLeer();
	//Getter für die Zielkreuzung
		std::shared_ptr<Kreuzung> getZielKreuzung() const;
	//Getter für den Rückweg
		std::shared_ptr<Weg> getRueckweg(void);
	//Setter für den Rückweg
		void vSetRueckweg(std::weak_ptr<Weg> pRueckweg);
	//Getter für das Überholverbot: Hinfällig
		virtual bool bGetUeberholverbot() const;
	//Dekonstruktor
		virtual ~Weg();
};

#endif /* MEINEDATEIEN_WEG_H_ */
