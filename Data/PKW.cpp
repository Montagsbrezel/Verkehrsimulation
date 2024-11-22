/*
 * PKW.cpp
 *
 *  Created on: 21.11.2023
 *      Author: Moritz
 */

#include "PKW.h"
#include "Verhalten.h"

extern double dGlobaleZeit;
	//Konstrkutor mit initialisierungsliste
		PKW::PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dMaxTankvolume): Fahrzeug(sName, dMaxGeschwindigkeit),p_dVerbrauch(dVerbrauch),p_dTankvolumen(dMaxTankvolume), p_dTankinhalt(dMaxTankvolume / 2), p_dGesamtverbrauch(), p_dGetankteMenge(), p_dTankenNach(3){
		}
	//Definieren der Funktionen
		double PKW::dTanken(void){
			p_dGetankteMenge += (p_dTankvolumen - p_dTankinhalt);// Gibt die Getankte Menge an
			//double dAktuellerTank = p_dTankvolumen - p_dTankinhalt;
			p_dTankinhalt = p_dTankvolumen; //Füllt den Tank auf
			p_dTankVollOderLeer = "Voll";//Ändert Tankanzeige auf Voll
			return p_dGetankteMenge;
		}

		void PKW::dLiegenbleiben(){
	//Wenn der Tank leer ist fährt der PKW zum Anfang. Tank wird auf Null gesetzt, weil keine Negative Zahl als Tankinhalt möglich sein soll.
			p_dTankinhalt = 0;
	//Wenn der Tank leer ist, dann wird der Tank von Voll -> zu Leer umgeändert
			p_dTankVollOderLeer = "Leer : Fahrzeug bleibt stehen";
			//p_dTankenNach
			dTankVollOderLeer();
		}

	//PKWs fahren immer mit maximaler Geschwindigkeit (Hier Definition). Zudem noch die Definitionen für dTankvolumen, dTankinhalt und dGesamtverbrauch
		double PKW::dGeschwindigkeit() const{
			Weg* weg = p_pVerhalten->getWeg();
				double limit = weg->dGetTempolimit();
				if (p_dMaxGeschwindigkeit > limit) {
					return limit;
				}
				else {
					return p_dMaxGeschwindigkeit;
				}
		}

	//Getter
		void PKW::vDoTanken(){
			dTanken();
		}
		double PKW::dTankvolumen() const{
			return p_dTankvolumen;
		}
		double PKW::dTankinhalt() const{
			return p_dTankinhalt;
		}
		double PKW::dGesamtverbrauch() const{//Kann mehr sein als im Tank war, da die Runde noch zu ende gefahren wird und in der Zeit weiter Spritt verbraucht wird
			return p_dGesamtverbrauch;
		}
		double PKW::dGetankteMenge()const {
			return p_dGetankteMenge;
		}
		std::string PKW::dTankVollOderLeer()const{
			return p_dTankVollOderLeer;
		}
		void PKW::dImmerTanken(){
			if(p_dTankinhalt <= 0){
	//Bleibt liegen, wenn Leer
				dLiegenbleiben();
			//}
			//if(dGlobaleZeit == p_dTankenNach){
	//Führe das Volltanken, sowie das ermitteln der Getankten Menge aus
				dTanken();
			}
		}
		void PKW::dLiegengebliebeneFahrzeugVolltanken(){
	//Volltanken für liegengebliebene Fahrzeug
			if(p_dTankinhalt <= 0){
				dLiegenbleiben();
	//Nach drei Stunden Volltanken für alle Liegengebliebenen Fahrzeug
				if(dGlobaleZeit == p_dTankenNach){
	//Führe das Volltanken, sowie das ermitteln der Getankten Menge aus
					dTanken();
				}
			}
		}

	// Simuliert die Bewegung des PKWs basierend auf der aktuellen Zeit
		void PKW::vSimulieren(){
			p_dTankVollOderLeer = "Voll";
			//dLiegenbleiben();
			if(p_dTankinhalt > 0.0){
				Fahrzeug::vSimulieren();
	//Gesamtverbrauch berechnen und verringert den Tankinhalt beim fahren unfertig
						double Gesamtverbrauch = (p_dVerbrauch / 100)* p_dGesamtStrecke;
						p_dGesamtverbrauch = Gesamtverbrauch;//Vielleicht Reserve
						p_dTankinhalt -= (p_dVerbrauch / 100)*p_dZurückgelegteStrecke; /*p_dGesamtverbrauch;*/
						if(p_dTankinhalt<0.0){
							p_dTankinhalt = 0.0;
						}
	//Übergangsweise
						//dImmerTanken();
			}
			else {
				dLiegenbleiben();
					if (fabs(this->p_pVerhalten->getWeg()->dGetLaenge() - p_dAbschnittStrecke) < 1e-100) {
						Fahrzeug::vSimulieren(); //Fahrzeug "rollt" noch in nächsten Abschnitt
					}
					p_dZeit = dGlobaleZeit;
					//dImmerTanken();
			}
			//Fahrzeug::vSimulieren();
			/*p_dTankVollOderLeer = "Voll";
			double abfertigungszeit = dGlobaleZeit - p_dZeit;
			double geschwindigkeit = dGeschwindigkeit();
			double aktuellZurückgelegteStrecke = geschwindigkeit * abfertigungszeit;

			//double zwischenspeicherStrecke;
			if(p_dTankinhalt > 0){
			p_dGesamtStrecke += aktuellZurückgelegteStrecke;
			p_dGesamtZeit += abfertigungszeit;
			}
			p_dZeit = dGlobaleZeit;
	//Gesamtverbrauch berechnen und verringert den Tankinhalt beim fahren unfertig
			double Gesamtverbrauch = (p_dVerbrauch / 100)* p_dGesamtStrecke;
			p_dGesamtverbrauch = Gesamtverbrauch;//Vielleicht Reserve
			p_dTankinhalt -=(p_dVerbrauch / 100)*p_dZurückgelegteStrecke; p_dGesamtverbrauch;*/
			//dImmerTanken();
		//}
		}
	//Wurde erst nachträglich noch von mir ergänzt. Es ist noch möglich alle Werte in Fahrzeug::vAusgeben ausgeben zu lassen
		void PKW::vAusgeben(std::ostream& out)const{
			out << std::setw(5) << p_iID << std::setw(15) << p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtStrecke << std::setw(30) << dGeschwindigkeit() <<
					std::setw(20) << dTankvolumen() << std::setw(15) << dTankinhalt()<< std::setw(20) << std::setw(20) << dGesamtverbrauch() << std::setw(20) << dGetankteMenge() << std::setw(40) << dTankVollOderLeer() /*<< "\n"*/;
		}

	//Funktion für das zeichnen von PKW.
		void PKW::vZeichnen(const Weg& weg) const{
			double dRelPosition = p_dAbschnittStrecke / weg.dGetLaenge();
			bZeichnePKW(p_sName, weg.sGetName(), dRelPosition, dGeschwindigkeit(), p_dTankinhalt);

		}

	//Vergleichsoperator Definieren
		bool PKW::operator<(const PKW& andere)const{
			return p_dGesamtStrecke < andere.p_dGesamtStrecke;
		}
	//Zuweisungsoperator
		PKW& PKW::operator=(const PKW& andere) {
			if(this != &andere){
				Fahrzeug::operator=(andere);
			}
			return *this;
		}

	//Dekonstruktor
		PKW::~PKW(){
		}

