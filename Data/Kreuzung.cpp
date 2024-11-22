/*
 * Kreuzung.cpp
 *
 *  Created on: 17.01.2024
 *      Author: Moritz
 */

// Kreuzung.cpp
//#include "Simulationsobjekt.h"0
#include "Kreuzung.h"
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "vertagt_liste.h"

#include <memory>
#include <random>



		Kreuzung::Kreuzung(const std::string& sName, double dTankstelle) : Simulationsobjekt(sName), p_dTankstelle(dTankstelle){

		}

	//weak_ptr um zyklische Refferenzen zu brechen// wenn Wege
		void Kreuzung::vVerbinde(std::string sHinwegName, std::string sRueckwegName, std::weak_ptr<Kreuzung> StartKreuzung, std::weak_ptr<Kreuzung> ZielKreuzung, double dWeglaenge, int iTempolimit, bool bUeberholverbot) {
					std::shared_ptr<Weg> pWegRueckweg = std::make_shared<Weg>(sHinwegName, dWeglaenge, iTempolimit, bUeberholverbot, ZielKreuzung);
					std::shared_ptr<Weg> pWegHinweg = std::make_shared<Weg>(sRueckwegName, dWeglaenge, iTempolimit, bUeberholverbot, StartKreuzung);

					pWegHinweg->vSetRueckweg(pWegRueckweg);//Jeder Weg kennt seinen Rückweg
					pWegRueckweg->vSetRueckweg(pWegHinweg);

					StartKreuzung.lock()->p_pWege.push_back(move(pWegRueckweg));
					ZielKreuzung.lock()->p_pWege.push_back(move(pWegHinweg));

		}

	//vTanken wird in in Streckenende aufgerufen und sorgt dafür, dass die Fahrzeuge aufgetankt werden, solange eine TAnkstelle vorhanden ist an der Kreuzung und die Tankstelle noch Kraftstoff hat
		void Kreuzung::vTanken(Fahrzeug& fahrzeug) {
			if (p_dTankstelle > 0.0) {
				fahrzeug.vDoTanken();
				p_dTankstelle -= fahrzeug.dGetankteMenge();//Es kann ein Grenzfall entstehen, wenn die Tankstelle leer getank wird. Gegebenfalls anpassen
				if(p_dTankstelle <= 0.0){
					p_dTankstelle = 0.0;
				}
			}
		}

	//Getter für den Tankstelleninhalt
		double Kreuzung::dGetTankstelle(){
			return p_dTankstelle;
		}

	//Nimmt Fahrzeuge an und stellt diese parkend auf den ersten abgehenden Weg
		void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt) {
			p_pWege.begin()->get()->vAnnahme(move(pFahrzeug),dStartzeitpunkt);
		}

	//Simuliert alle von der Kreuzung abgehenden Wege
		void Kreuzung::vSimulieren(){
			for(std::shared_ptr<Weg>& pWeg : p_pWege) {
				pWeg->vSimulieren();
				pWeg->vZeichneFahrzeuge();
			}
		}

	//Soll nicht den gleichen Weg zurückfahren, es sei denn, eine Sackgasse Wurde erreicht. Enthält eine Refferenz von dem Weg von dem aus die Kreusung erreicht wurde
		std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& pAktuellerWeg){

	//Erstellen einer Liste mit allen möglichen Wegen
			std::list<std::shared_ptr<Weg>> moeglicheWege;

	//Erzeugt eine Liste aller Wge, solange welche vorhanden sind und, wenn einer der Wege mit dem Aktuellen Weg(Letzter befahrende) übereinstimmt, wird dieser Übersprungen und ignoriert
			for(std::list<std::shared_ptr<Weg>>::iterator pWeg = p_pWege.begin(); pWeg != p_pWege.end(); ++pWeg){
				if(pWeg->get()==pAktuellerWeg.getRueckweg().get()){continue;}//.get zum auflösen des Shared_ptr
				moeglicheWege.push_back(*pWeg);
			}

	//Wenn es keine alternativen Wege gibt, bleibt das Fahrzeug auf dem aktuellen Weg
			if(moeglicheWege.empty()) {
				return pAktuellerWeg.getRueckweg();
			}

	//Wenn Wege vorhanden sind
			if(!moeglicheWege.empty()){
	//Zufällige Auswahl eines Weges aus der Liste
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<int> distribution(0,moeglicheWege.size()-1);
				int index = distribution(gen);

	// Fortschritt des Iterators zum ausgewählten Index
				auto it = moeglicheWege.begin();
				std::advance(it, index);//advance wurde verwendet, um den Iterator zum ausgewählten Index vorzurücken. Ist in einer Doppelten verkettenten Liste effizient.

				return *it;//den Iterator auflösen
			}else {
				return nullptr;
			}
		}

	Kreuzung::~Kreuzung(){

	}
