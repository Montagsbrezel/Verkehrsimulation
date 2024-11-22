/*
 * Fahrzeug.cpp
 *
 *  Created on: 21.11.2023
 *      Author: Moritz
 */
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"

extern double dGlobaleZeit;

	// Konstruktor für Namen
		Fahrzeug::Fahrzeug(const std::string& sName) : Simulationsobjekt(sName), p_dMaxGeschwindigkeit(0.0),p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0), p_dZeit(0.0), p_dZeitintervall(0.0), p_dAbschnittStrecke(0.0), p_dZurückgelegteStrecke(0.0){
			//p_iMaxID += 1;
			//std::cout << "Konstruktor von: " << p_sName << " und von der ID: " << p_iID << " und der maximalen Gewschwindigkeit: "<< p_dMaxGeschwindigkeit<< " und der gesamten Strecke: "<< p_dGesamtStrecke<< " und der gesamt Zeit: "<<p_dGesamtZeit<< " und von der aktuellen Zeit: "<<p_dZeit<< "und von "<< p_dTankVollOderLeer <<"\n"<<std::endl;
		}

	// Default-Konstruktor
		Fahrzeug::Fahrzeug() :Simulationsobjekt(""), p_dMaxGeschwindigkeit(0.0),p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0), p_dZeit(0.0), p_dZeitintervall(0.0), p_dAbschnittStrecke(0.0), p_dZurückgelegteStrecke(0.0){
			//std::cout << "Default Konstruktor von: " << p_sName << " und der ID: " << p_iID << " und der maximalen Gewschwindigkeit: "<< p_dMaxGeschwindigkeit<< " und der gesamten Strecke: "<< p_dGesamtStrecke<< " und der gesamt Zeit: "<<p_dGesamtZeit<< " und von der aktuellen Zeit: "<<p_dZeit<<" und von " << p_dTankVollOderLeer << "\n"<<std::endl;
		}

	// Konstruktor mit Name und Maximalgeschwindigkeit
		Fahrzeug::Fahrzeug(const std::string& sName, double maxGeschwindigkeit): Simulationsobjekt(sName),
				p_dMaxGeschwindigkeit(maxGeschwindigkeit),p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0), p_dZeit(0.0), p_dZeitintervall(0.0), p_dAbschnittStrecke(0.0), p_dZurückgelegteStrecke(0.0){
	//Prüfen, ob die Geschwindigkeit positiv ist
			p_dMaxGeschwindigkeit = (maxGeschwindigkeit > 0.0) ? maxGeschwindigkeit : 0.0;
			//std::cout << "Konstruktor von: " << p_sName << " mit Maximalgeschwindigkeit "<< p_dMaxGeschwindigkeit << " und von der ID: " << p_iID << std::endl;
		}

	// Funktion zum Ausgeben der Daten
		void Fahrzeug::vAusgeben(std::ostream& out) const {
			out << std::setw(5) << p_iID << std::setw(15) << p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtStrecke; //<< "\n";
			//std::setw(30) << dGeschwindigkeit() << std::setw(20) << dTankvolumen() << std::setw(15) << dTankinhalt() << std::setw(20) << std::setw(20) << dGesamtverbrauch() << std::setw(20) << dGetankteMenge() << std::setw(40) << dTankVollOderLeer() << "\n";
		}
		std::string Fahrzeug::sGetName() const {
				return p_sName;
		}
	//Sorgt dafür, ob das Fahrzeug Parkend oder Fahrend ist
		void Fahrzeug::vNeueStrecke(Weg& weg) {
			p_pVerhalten = std::make_unique<Fahren>(weg); // Erzeugt ein neues Verhalten für den übergebenen Weg
			p_dAbschnittStrecke = 0.0; // Setzt die zurückgelegte Strecke auf dem aktuellen Weg auf 0
		}

		void Fahrzeug::vNeueStrecke(Weg& weg, double dStartzeitpunkt) {
			p_pVerhalten = std::make_unique<Parken>(weg, dStartzeitpunkt);
			p_dAbschnittStrecke = 0.0;
		}

		Verhalten* Fahrzeug::getVerhalten() const {
			return p_pVerhalten.get();
		}
	//Getter
		double Fahrzeug::getAbschnittStrecke() {
			return p_dAbschnittStrecke;
		}

	//Simulationsfunktion
		void Fahrzeug::vSimulieren(){
	//Vergangene Zeit seit der letzte Abfertigung
			double dZeitintervall = dGlobaleZeit - p_dZeit;
	//Simulation für Fahrzeuge
			p_dZurückgelegteStrecke = p_pVerhalten->dStrecke(*this, dZeitintervall);
			p_dAbschnittStrecke += p_dZurückgelegteStrecke;
			p_dGesamtStrecke += p_dZurückgelegteStrecke;
			p_dGesamtZeit += dZeitintervall; //Das nur fürs Fahrzeug, wenn benötigt später zur Globalzeit Gleichsetzen
			p_dZeit = dGlobaleZeit; //So kann durch das Abziehn am anfang die Zeit der letzten Abfertigung ermittelt werden
		}

		double Fahrzeug::dStreckeBerechnen(double dZeitintervall) {
			if (p_pVerhalten) {
				return p_pVerhalten->dStrecke(*this, dZeitintervall);
			}
			return 0.0;
		}

		void Fahrzeug::vSetStartzeit(double dStartZeit) {
			p_dZeit = dStartZeit;
		}

	//Werden alle überschrieben
		double Fahrzeug::dGeschwindigkeit() const {
			return dGeschwindigkeit();
		}
		double Fahrzeug::dGesamtverbrauch() const{
			return dGesamtverbrauch();
		}
		double Fahrzeug::dTankvolumen() const{
			return dTankvolumen();
		}
		double Fahrzeug::dTankinhalt() const{
			return dTankinhalt();
		}
		double Fahrzeug::dGetankteMenge()const{
			return dGetankteMenge();
		}
		std::string Fahrzeug::dTankVollOderLeer()const{
			return dTankVollOderLeer();
		}

		double Fahrzeug::dGetLaenge()const{
			return dGetLaenge();
		}
	//Sorg dafür, dass das Auftanken möglich ist, da nun andere Funktionen darauf zugreifen könen
		void Fahrzeug::vDoTanken(){

		}

	//Funktion zum überschreiben um PKW und Fahrrad zu zeichen
		void Fahrzeug::vZeichnen(const Weg& weg) const{
		}

	//Vergleichsoperator Definieren
		bool Fahrzeug::operator<(const Fahrzeug& andere)const{
			return p_dGesamtStrecke < andere.p_dGesamtStrecke;
		}

	//Zuweisungsoperator
		Fahrzeug& Fahrzeug::operator=(const Fahrzeug& andere) {
			if(this != &andere){
	//Wär kacke, wenn die ID einfach Kopiert werden könnte. Anfälligkeit für angriffe
				this->p_dMaxGeschwindigkeit = andere.p_dMaxGeschwindigkeit;
				this->p_dGesamtStrecke = andere.p_dGesamtStrecke;
			}
			return *this;
		}

	//Dekonstrucktor
		Fahrzeug::~Fahrzeug(){
			//std::cout <<"Folgendes wurde Dekonstruiert: 1.Der Name: " << p_sName << " und 2.Die ID: " << p_iID<<" und 3.Der maximalen Gewschwindigkeit: "<< p_dMaxGeschwindigkeit<< " und 4.Der gesamten Strecke: "<< p_dGesamtStrecke<< " und 5.Der gesamt Zeit: "<<p_dGesamtZeit<<" und 6.von der aktuellen Zeit: "<<p_dZeit << " und 7.ob der Tank Voll/Leer ist"<< p_dTankVollOderLeer << std::endl;
		}

