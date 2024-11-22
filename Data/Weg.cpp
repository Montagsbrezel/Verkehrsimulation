/*
 * Weg.cpp
 *
 *  Created on: 28.12.2023
 *      Author: morit
 */

#include <memory>
#include "Weg.h"
#include "Simulationsobjekt.h"
#include "Fahrausnahme.h"
#include "Parken.h"
#include "Fahrzeug.h"
#include "vertagt_liste.h"


//Default Konstrucktor
		Weg::Weg() : Simulationsobjekt("Default Weg") ,p_dLaenge(0.0), p_iTempolimit(3),p_bUeberholverbot(false), p_pZielKreuzung(std::weak_ptr<Kreuzung>()){

		}

	//Konstrucktor
		//Weg::Weg(const std::string sName, double dLaenge, int iTempolimit, bool bUeberholverbot)
			//	    : Simulationsobjekt(sName), p_dLaenge(dLaenge), p_iTempolimit(iTempolimit), p_bUeberholverbot(bUeberholverbot){


		Weg::Weg(const std::string sName, double dLaenge, int iTempolimit, bool bUeberholverbot, std::weak_ptr<Kreuzung> pZielKreuzung)
				: Simulationsobjekt(sName), p_dLaenge(dLaenge), p_iTempolimit(iTempolimit), p_bUeberholverbot(bUeberholverbot),
				p_pZielKreuzung(pZielKreuzung){

		}

	//Fügt ein Fahrzeug hinzu, welche in main.cpp genauer beschrieben wurde
		void Weg::addFahrzeug(std::unique_ptr<Fahrzeug>fahrzeug){
			p_pFahrzeuge.push_back(std::move(fahrzeug));
		}

		double Weg::dGetID()const{
			return p_iID;
		}

	//Gibt das Templimit von Innerorts, Landstraße oder Autobahn als konkrete Zahl aus. Wir hier aber unten gemacht
		double Weg::dGetTempolimit()const{
			switch (p_iTempolimit){
				case 1:
				{
					return double(Tempolimit::Innerorts);
					break;
				}
				case 2:
				{
					return double(Tempolimit::Landstrasse);
					break;
				}
				case 3:
				{
					return double(Tempolimit::Autobahn);
					break;
				}
				default :
						{
					std::cout << "Warnunung: default case!!!" << std::endl;
					return double(Tempolimit::Autobahn);
					break;
				}
			}
		}
	//Getter von der Länge des Weges
		double Weg::dGetLaenge() const {
			return p_dLaenge;
		}

	//Soll nur eine Ausgabe erlauben: falls benötigt
		bool nurEineAusgabe = true;

	//Wenn Fahrzeuge auf der Liste zeichne diese. Wird momentan in der Kreuzung aufgerufen
		void Weg::vZeichneFahrzeuge() {
			if (!p_pFahrzeuge.empty()){
				for (auto& it : p_pFahrzeuge){
					it->vZeichnen(*this);
				}
			}
		}

	//Es werden, solange Fahrzeuge auf der Liste sind, diese Simuliert. Catch wird nur ausgelößt, falls eine Ausnahme eintrifft
		void Weg::vSimulieren() {
	//Ohne vAktualisierenn würde es zu Fehlermeldungen kommen oder fehlende Simulationsschritte verursachen, da die z.b:Objekte nach hinten verschoben werden
			p_pFahrzeuge.vAktualisieren();
				if (!p_pFahrzeuge.empty()) {
					for (auto& it : p_pFahrzeuge) {
						try {
							it->vSimulieren();
						}
						catch (Fahrausnahme* fahrausnahme) {
							fahrausnahme->vBearbeiten();
							delete fahrausnahme;
						}
					}
					p_pFahrzeuge.vAktualisieren();
				}
		}
	//Definieren von der Kopfzeile für Wege
		void Weg::vKopf() {
			std::cout <<"\n" << std::setw(5) << " ID " << std::setw(5) <<"|"<< std::setw(15) << "Name" << std::setw(5)<<"|"<< std::setw(20) << "Länge" << std::setw(5)<<"|"<< std::setw(35) << "Maximalgeschwindigkeit(km/h)" << std::setw(10)<<"|"<<std::setw(20)<<"Fahrzeuge"<<"\n";
			std::cout << std::setfill('-') << std::setw(150) << "" << std::endl<< std::setfill(' ');
		}

		void Weg::vAusgeben(std::ostream& out) const {
	//Ausgabe der Wege
			Weg::vKopf();
				out << std::setw(4) << p_iID << std::setw(22) << p_sName << std::setw(24) << p_dLaenge << std::setw(39) <<dGetTempolimit();

	//Ausgabe der, dem Weg zugenwiesenen, Fahrzeugen
				out << std::setw(20)<<"(";
				for (auto& it : p_pFahrzeuge){
					out << (it)->sGetName() << ", ";
				}
				out << ")"<<std::endl;

	//Ausgabe der Fahrzeuge
				Fahrzeug::vKopf();
				for (const auto& it : p_pFahrzeuge){
					out << *it<<std::endl;
				}
		}

	//Annahme von Fahrenden FAhrzeugen
		void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug) {
	// Eintragen des Fahrzeugs in die Liste der Fahrzeuge auf diesem Weg
			pFahrzeug->vNeueStrecke(*this);
	// Dem Fahrzeug signalisieren, dass es sich auf einer neuen Strecke befindet
			p_pFahrzeuge.push_back(std::move(pFahrzeug));
		}

	//Überladene Funktion vAnnahme für das Parkende Fahrzeug
		void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt) {
			pFahrzeug->vNeueStrecke(*this, dStartzeitpunkt);
			pFahrzeug->vSetStartzeit(dStartzeitpunkt);
			p_pFahrzeuge.push_front(std::move(pFahrzeug));
		}

//Dient zur ändern des Fahrverhaltens und verändert die Liste
		std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fahrzeug) {
			for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
				{											//Objekt vom Iterator ist kein Null Pointer & Fahrzeug von Liste ist gleich dem gegeben Fahrzeug
				if (( *it != nullptr) && (**it == fahrzeug))//Adresse zeigt auf eine adresse. Lößt es als doppelten pointer aus.
				{
					std::unique_ptr<Fahrzeug>pFahrzeugLokal = move(*it); //Zwischenspeicherung
					p_pFahrzeuge.erase((it)); //Listenelement wird gelöscht
					return pFahrzeugLokal;
				}
			}
			return nullptr;
		}

/*		bool Weg::bLeer() {
			return p_pFahrzeuge.empty();
		}*/

	//Getter für die Kreuzung mit allen Wichtigen Werten
		std::shared_ptr<Kreuzung> Weg::getZielKreuzung() const {
			return p_pZielKreuzung.lock();
		}

	//Getter des Rückweges
		std::shared_ptr<Weg> Weg::getRueckweg(void) {
			return p_pRueckweg.lock();
		}

	//Getter von Überholverbot hier: keine Funktion, da es dür ein Überholverbot keine Logik gibt
		bool Weg::bGetUeberholverbot() const {
			return p_bUeberholverbot;
		}

	//Setter des Rückwegs
		void Weg::vSetRueckweg(std::weak_ptr<Weg> pRueckweg) {
			p_pRueckweg = pRueckweg;
		}

		Weg::~Weg() {}
