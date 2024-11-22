/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 28.12.2023
 *      Author: morit
 */

#include "Simulationsobjekt.h"

extern double dGlobaleZeit;
	//Konstruktor von Simulationsobjekt mit Name und Lokaler Zeit
		Simulationsobjekt::Simulationsobjekt(const std::string& sName): p_sName(sName), p_iID(p_iMaxID), p_dLokaleZeit(0.0) {
			p_iMaxID += 1;
			std::cout<< "Konstruktion von Objekt:"<< p_sName <<" mit der ID: "<< p_iID<<" und der Lokalen Zeit: "<< p_dLokaleZeit <<" Erfolgreich!"<<"\n"<< std::endl;
		}
	//Simulieren aktuell leer
		void Simulationsobjekt::vSimulieren(){

		}
		std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& simobjekt) {
			simobjekt.vAusgeben(out);
			return out;
		}
	//Funktion für die Überschrift setw statt setiosflags genommen, da ich den nicht ganz verstanden habe
		void Simulationsobjekt::vKopf() {
			std::cout <<"\n" << std::setw(5) << dGlobaleZeit << " Zeitangabe" << std::endl;
			std::cout <<"\n" << std::setw(5) << "ID" << std::setw(15) << "Name" << std::setw(20) << "MaxGeschwindigkeit" << std::setw(15) << "Gesamtstrecke" << std::setw(30) << "Aktuelle Geschwindigkeit" << std::setw(20) <<"Tankvolumen"<< std::setw(15) << "Tankinhalt" << std::setw(20) << "Gesamtverbrauch"<< std::setw(20) << "Getankte Menge" <<std::setw(40) << "Tank Voll/Leer"<<"\n";
			std::cout << std::setfill('-') << std::setw(210) << "" << std::endl<< std::setfill(' ');
		}
	//Funktion zum Ausgeben der Daten
		void Simulationsobjekt::vAusgeben(std::ostream& out) const {
			out << std::setw(5) << p_iID << std::setw(15) << p_sName ;
		}
	//Getter für sGetName
		std::string Simulationsobjekt::sGetName() const {
			return p_sName;
		}
	//Getter für dGetID
		double Simulationsobjekt::dGetID()const{
			return dGetID();
		}
	//Gibt das Templimit von Innerorts, Landstraße oder Autobahn als konkrete Zahl aus. Wir hier aber unten gemacht
		double Simulationsobjekt::dGetTempolimit()const{
			return dGetTempolimit();
		}
	//Getter, welcher die Länge des Weges zurückgibt
		double Simulationsobjekt::dGetLaenge() const {
			return dGetLaenge();
		}
		double randDouble(int lower, int upper){
			std::default_random_engine rnd{std::random_device{}()};
			std::uniform_real_distribution<double> dist(lower, upper);
			return dist(rnd);
		}

	//Definieren des Zuweisungsoperators bei zwei gleichen IDs soll true ausgeben werden
		bool Simulationsobjekt::operator==(const Simulationsobjekt& andere) const {
			return p_iID == andere.p_iID;
		}
	//Dekonstruktor von Simulationsobjekt
		Simulationsobjekt::~Simulationsobjekt() {
			std::cout << "Folgendes wurde Dekonstruiert: Der Name: " << p_sName << " und die ID: " << p_iID << std::endl;
		}
