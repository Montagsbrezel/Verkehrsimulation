/*
 * Fahrrad.cpp
 *
 *  Created on: 21.11.2023
 *      Author: Moritz
 */

#include "Fahrrad.h"



//Konstrkutor mit initialisierungsliste
Fahrrad::Fahrrad(const std::string& sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit) {
}

	//Berechnet die aktuelle Geschwindigkeit, welche mit der Gesamtstrecke (also im laufe der Zeit) abnimmt. Diese wird von Fahrrad::vSimulieren verwendet
		double Fahrrad::dGeschwindigkeit() const {
			const double dMindestgeschwindigkeit = 12.0;
			double dGeschwindigkeitProzent = p_dMaxGeschwindigkeit * pow((0.9), p_dGesamtStrecke / 20.0); /*Nimm die 10% von dem abgezogenen Wert. Ansonsten wenn man immer von MaxGeschwindigkeit abzieht geht man immer von der Gesamtgeschwindigkeit runter*/;
			if(dGeschwindigkeitProzent <= dMindestgeschwindigkeit){
				dGeschwindigkeitProzent = dMindestgeschwindigkeit;
			}
			return dGeschwindigkeitProzent;
		}

	// Simuliert die Bewegung des Fahrrads basierend auf der aktuellen Zeit
		void Fahrrad::vSimulieren(){
			Fahrzeug::vSimulieren();
		}

	//dTankvolumend, dTankinhalt, dGesamtverbrauch und dGetankteMenge sind bei Fährräder immer NULL also 0, da sie sowas nich besitzen.
		double Fahrrad::dTankvolumen() const{
				return 0;
		}
		double Fahrrad::dTankinhalt() const{
			return 0;
		}
		double Fahrrad::dGesamtverbrauch() const{
			return 0;
		}
		double Fahrrad::dGetankteMenge() const{
			return 0;
		}

		std::string Fahrrad::dTankVollOderLeer()const{
					return ("Nicht vorhanden");
		}

		void Fahrrad::vAusgeben(std::ostream& out)const{
			out << std::setw(5) << p_iID << std::setw(15) << p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtStrecke << std::setw(30) << dGeschwindigkeit() <<
					std::setw(20) << dTankvolumen() << std::setw(15) << dTankinhalt()<< std::setw(20) << std::setw(20) << dGesamtverbrauch() << std::setw(20) << dGetankteMenge() << std::setw(40) << dTankVollOderLeer() << "\n";
			//std::cout << std::setw(5) << p_iID << std::setw(15) << p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtStrecke << std::setw(30) << dGeschwindigkeit() << std::setw(20) << dTankvolumen() << std::setw(15) << dTankinhalt()<< std::setw(20) << std::setw(20) << dGesamtverbrauch() << std::setw(20) << dGetankteMenge() << std::setw(40) << dTankVollOderLeer() << "\n";
		}

	//Funktion für das zeichen von Fahrrad
		void Fahrrad::vZeichnen(const Weg& weg) const{
			double dRelPosition = p_dAbschnittStrecke / weg.dGetLaenge();
			bZeichneFahrrad(p_sName, weg.sGetName(), dRelPosition, dGeschwindigkeit());
		}

	//Vergleichsoperator Definieren
		bool Fahrrad::operator<(const Fahrrad& andere)const{
			return p_dGesamtStrecke < andere.p_dGesamtStrecke;
		}

	//Zuweisungsoperator
		Fahrrad& Fahrrad::operator=(const Fahrrad& andere) {
			if(this != &andere){
				Fahrzeug::operator=(andere);
			}
			return *this;
		}

		Fahrrad::~Fahrrad(){

		}

