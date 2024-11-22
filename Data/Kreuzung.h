/*
 * Kreuzung.h
 *
 *  Created on: 17.01.2024
 *      Author: Moritz
 */
#pragma once

#ifndef DATA_KREUZUNG_H_
#define DATA_KREUZUNG_H_

#include "Simulationsobjekt.h"
#include "vertagt_liste.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Weg.h"

#include <memory>

class Weg;
class Fahrzeug;
class Fahrausnahme;

class Kreuzung : public Simulationsobjekt{
private:
	std::list<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle = 0;

protected:

public:
	Kreuzung()=delete;
	//Konstrucktor
		Kreuzung(const std::string& sName, double dTankstelle);
	//Deklaration von der Tankstelle an der Kreuzung
		void vTanken(Fahrzeug& fahrzeug);
	//Annahme von parkenden Fahrzeugen auf einer Kreuzung
		void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit);
	//Deklaration von vSimulieren für die Kreuzung
		virtual void vSimulieren();
	//Deklaration für die Funktion pZufaelligerWeg, welche die Referenz des Weges enthält von dedem aud die Kreuzung erreicht wurde
		std::shared_ptr<Weg>pZufaelligerWeg(Weg& pAktuellerWeg);
	//Deklaration einer Statischen Funktion zum Verbinden der Kreuzungen mittels Wege. Alle wichtigen Parameter von Weg werden hier eingefügt
		static void vVerbinde(std::string sHinwegName, std::string sRueckwegName, std::weak_ptr<Kreuzung> StartKreuzung, std::weak_ptr<Kreuzung> ZielKreuzung, double dWeglaenge, int iTempolimit, bool bUeberholverbot = false);
	//Getter für den Tankstelleninhalt
		double dGetTankstelle();
	//Dekonstrucktor
		virtual ~Kreuzung();
};

#endif /* DATA_KREUZUNG_H_ */
