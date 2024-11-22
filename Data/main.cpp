/*
 * main.cpp
 *
 *  Created on: 15.11.2023
 *      Author: Moritz
 */
//#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <list>
#include <cmath>
#include <filesystem>
#include <random>
#include <exception>
#include <string>

#include "Simulationsobjekt.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Weg.h"
#include "Tempolimit.h"
#include "Parken.h"
#include "Fahren.h"
#include "Losfahren.h"
#include "Streckenende.h"
#include "SimuClient.h"
#include "vertagt_liste.h"
#include "Kreuzung.h"


double dGlobaleZeit = 0.0; //Funktioniert glaube ich noch nicht

//Definition des Operators für die Ausgabe
/*void console_clear_screen(void) {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}*/
/*void vAufgabe_1(std::ostream& out){

	//Statische Elemente
		Fahrzeug stehendesKnecht1(" Gerry ");
		Fahrzeug stehendesKnecht2;

	//Dynamisches Element (Merke (new)=kacke)
		Fahrzeug* bewegendesKnecht1 = new Fahrzeug(" BewegendesKnecht1 ");
		Fahrzeug* bewegendesKnecht2 = new Fahrzeug;

	//Löschen der Elemente mit delete
		delete bewegendesKnecht1;
		delete bewegendesKnecht2;

	//Vektor von unique_prt
		std::unique_ptr<Fahrzeug>BMWT = std::make_unique<Fahrzeug>("M");
		std::unique_ptr<Fahrzeug>BenzT = std::make_unique<Fahrzeug>("S-Kla");
		std::unique_ptr<Fahrzeug>PorscheT = std::make_unique<Fahrzeug>("Box");

		std::vector<std::unique_ptr<Fahrzeug>> uniquePtrVektor;
		uniquePtrVektor.push_back(std::move(BMWT));
		uniquePtrVektor.push_back(std::move(BenzT));
		uniquePtrVektor.push_back(std::move(PorscheT));

	// Löschen des Vektoren
		uniquePtrVektor.clear();

	//Shared Pointer hinzufügen
		auto sharedPtr1 = std::make_shared<Fahrzeug>(" Ford ");
		auto sharedPtr2 = std::make_shared<Fahrzeug>(" Jaguar ");
	//Anzahl der Referenzen von sharedPtr vor Zuweisung
			out <<" Die Anzahl der Referenzen vor der Zuweisung mit use_count: " <<sharedPtr1.use_count() << "\n\n";
		auto sharedPtr3 = sharedPtr1;
	//Anzahl der Referenzen von sharedPtr nach Zuweisung
			out <<" Die Anzahl der Referenzen nach der Zuweisung mit use_count: " <<sharedPtr1.use_count() << "\n\n";

	//Vektor von shared_Ptr mit und ohne move
		std::vector<std::shared_ptr<Fahrzeug>> sharedPtrVektor;
		sharedPtrVektor.push_back(std::move(sharedPtr1));
		sharedPtrVektor.push_back(sharedPtr2);

	//Löschen der Vektoren sharedPtrVektor
		sharedPtrVektor.clear();

    }
void vAufgabe_1a(std::ostream& out){
//Clear screen
//out<<"cls";
	//Die Simulierte Zeitspanne. Hier:10 Stunden. Gibt die Zeitspanne an die das Programm läuft. Wichtig für Globale Zeit
		const double zeitspanne = 10.0;
		const double zeittakt = 0.1; //Zudem noch der Zeittakt mit 0.1
		std::vector<std::unique_ptr<Fahrzeug>> uniquePtrVektor;
	//Einlesen der Fahrzeug
		std::unique_ptr<Fahrzeug>BMW = std::make_unique<Fahrzeug>("M3", 20);
		std::unique_ptr<Fahrzeug>Benz = std::make_unique<Fahrzeug>("S-Klasse",100);
		std::unique_ptr<Fahrzeug>Porsche = std::make_unique<Fahrzeug>("Boxer", 200);

		uniquePtrVektor.push_back(std::move(BMW));
		uniquePtrVektor.push_back(std::move(Benz));
		uniquePtrVektor.push_back(std::move(Porsche));
	//Globale Uhr
		while(dGlobaleZeit < zeitspanne){
			dGlobaleZeit += zeittakt;

	//Simulationsaufruf
			for (const auto& fahrzeuge : uniquePtrVektor) {
				fahrzeuge->vSimulieren();
			}
	//Ausgabe
				Fahrzeug::vKopf();

			for (const auto& fahrzeuge : uniquePtrVektor) {
				fahrzeuge->vAusgeben(std::cout);//Die Ausgabe für alle Fahrzeuge der vAufgabe_1a
			}
		}
		dGlobaleZeit = 0.0;
		console_clear_screen();
}*/
void vAufgabe_2(std::ostream& out){
//Clear screen
//out<<"cls";
	//Neuer Vektor für PKW und Fahrrad
		std::vector<std::unique_ptr<Fahrzeug>> uniqueBewegungsmittelVektor;
	//Einlesen  und erzeugung der PKWs
		std::unique_ptr<Fahrzeug>Koenigsegg = std::make_unique<PKW>("Koenigsegg", 320.0, 15.6, 90.0);//Konsolenausgabe falsch Ausgabe generell bearbeiten, da Fahrrad und PKW verschiedene brauchen
		std::unique_ptr<Fahrzeug>VW = std::make_unique<PKW>("VW", 90.2, 7.3, 55.5);//Werte anpassen
		std::unique_ptr<Fahrzeug>Nissan = std::make_unique<PKW>("Nissan", 254.7, 13.4, 80.0);
		std::unique_ptr<Fahrzeug>Audi = std::make_unique<PKW>("Audi", 150.0, 8.0, 55.0);

		uniqueBewegungsmittelVektor.push_back(std::move(Koenigsegg));
		uniqueBewegungsmittelVektor.push_back(std::move(VW));
		uniqueBewegungsmittelVektor.push_back(std::move(Nissan));
		uniqueBewegungsmittelVektor.push_back(std::move(Audi));

	//Einlesen und erzeugen der Fahrräder
		std::unique_ptr<Fahrzeug>BMX = std::make_unique<Fahrrad>("BMX", 20.0);
		std::unique_ptr<Fahrzeug>Hollandrad = std::make_unique<Fahrrad>("Hollandrad", 19.4);
		std::unique_ptr<Fahrzeug>Drathesel = std::make_unique<Fahrrad>("Drathesel", 22.4);

		uniqueBewegungsmittelVektor.push_back(std::move(BMX));
		uniqueBewegungsmittelVektor.push_back(std::move(Hollandrad));
		uniqueBewegungsmittelVektor.push_back(std::move(Drathesel));
	//Die Simulierte Zeitspanne. Hier:10 Stunden. Gibt die Zeitspanne an die das Programm läuft. Wichtig für Globale Zeit. ACHTUNG!!! ES STEHT IN AUFGABE 1 EBENFALLS ABER HIER FUNKTIONALITÄT AUFGABE 2
		const double zeitspanne = 7.0;
		const double zeittakt = 1.0; //Zudem noch der Zeittakt mit 1.0
	//Globale Uhr?
		while(dGlobaleZeit < zeitspanne){
			dGlobaleZeit += zeittakt;
	//Simulationsaufrufe
			for(const auto& fahrzeug : uniqueBewegungsmittelVektor){
				fahrzeug->vSimulieren();
			}

		Fahrzeug::vKopf();

			for (const auto& fahrzeug : uniqueBewegungsmittelVektor) {
				fahrzeug->vAusgeben(std::cout);//Die Ausgabe für alle Fahrzeuge der vAufgabe_2
			}
		}
		dGlobaleZeit = 0.0;
		//console_clear_screen();

}
void vAufgabe_3(std::ostream& out){
		out<< "\n";
		Fahrzeug* Panzer1= new Fahrzeug ("Panzer 1",75.0 );
		Fahrzeug* Panzer2= new Fahrzeug("Panzer 2",70.0 );
	//Verwendung meines neuen Zuweisungsoperator
		Fahrzeug* Panzer3 = Panzer1;
		out<< "\n" << Panzer3 <<"wird ausgegeben, da alle Werte die hier übergeben werden könnten, verboten wurden. Somit dürfen die nicht geändert zu werden!!!"<<"\n"<<"\n";
	//Gibt nur den Pointer aus, da alle Werte die Übergeben werden könnten verboten wurde zu Übergeben
		Fahrzeug::vKopf();
	//Gibt Panzer 1 als Name aus, da Panzer3=Panzer1 gemacht wurde
		Panzer3->vAusgeben(std::cout);
	//Das hier zeigt es meiner Meinung nach besser
		delete Panzer1;
		delete Panzer2;
		delete Panzer3;
	//Panzer4 = Panzer2; würde einen Fehler auslösen, da der Copy Konstrucktor deaktiviert worden ist

}
void vAufgabe_4(std::ostream& out){
	Weg weg;
	out << weg ;

}
void vAufgabe_5(std::ostream& out){
	//Erzeugen eines Weges
		Weg weg("Nürnburgring", 1000.0, 2);

	//Erzeugen der Fahrzeuge
		std::unique_ptr<Fahrzeug> Koenigsegg = std::make_unique<PKW>("Koenigsegg", 320.0, 15.6, 90.0);
		std::unique_ptr<Fahrzeug> VW = std::make_unique<PKW>("VW", 256.0, 15.6, 90.0);
		std::unique_ptr<Fahrzeug> Porsche = std::make_unique<PKW>("Porsche 911", 290.0, 15.6, 90.0);
		std::unique_ptr<Fahrzeug>Nissan = std::make_unique<PKW>("Nissan", 254.7, 13.4, 80.0);
		std::unique_ptr<Fahrzeug>Audi = std::make_unique<PKW>("Audi", 150.0, 8.0, 55.0);

		weg.vAnnahme(move(Koenigsegg));
		weg.vAnnahme(move(VW));
		weg.vAnnahme(move(Porsche));
		weg.vAnnahme(move(Nissan));
		weg.vAnnahme(move(Audi));
	//Die Simulierte Zeitspanne. Hier:10 Stunden. Gibt die Zeitspanne an die das Programm läuft. Wichtig für Globale Zeit. ACHTUNG!!! ES STEHT IN AUFGABE 1 EBENFALLS ABER HIER FUNKTIONALITÄT AUFGABE 2
		const double zeitspanne = 7.0;
		const double zeittakt = 1.0; //Zudem noch der Zeittakt mit 1.0
	//Globale Uhr
		while(dGlobaleZeit < zeitspanne){
			dGlobaleZeit += zeittakt;
			weg.vSimulieren();
			out<<weg<<std::endl;
		}

}
void vAufgabe_5a(std::ostream& out){
	//Erzeugen eines Weges
		Weg weg1("Nürnburgring", 800.0, 2);
		Weg weg2("A4", 1200.0, 3);

	//Erzeugen der Fahrzeuge
			std::unique_ptr<Fahrzeug> Koenigsegg = std::make_unique<PKW>("Koenigsegg", 320.0, 15.6, 90.0);
			std::unique_ptr<Fahrzeug> VW = std::make_unique<PKW>("VW", 256.0, 15.6, 90.0);
			std::unique_ptr<Fahrzeug> Porsche = std::make_unique<PKW>("Porsche 911", 290.0, 15.6, 90.0);
			std::unique_ptr<Fahrzeug>Nissan = std::make_unique<PKW>("Nissan", 254.7, 13.4, 80.0);
			std::unique_ptr<Fahrzeug>Audi = std::make_unique<PKW>("Audi", 150.0, 8.0, 55.0);
			std::unique_ptr<Fahrzeug>BMX = std::make_unique<Fahrrad>("BMX", 20.3);
			std::unique_ptr<Fahrzeug>Hollandrad = std::make_unique<Fahrrad>("Hollandrad", 17.5);

			weg1.vAnnahme(move(Koenigsegg));
			weg1.vAnnahme(move(VW));
			weg1.vAnnahme(move(Porsche), 3);
			weg2.vAnnahme(move(Nissan));
			weg2.vAnnahme(move(Audi));
			weg2.vAnnahme(move(BMX));
			weg1.vAnnahme(move(Hollandrad));

			const double zeitspanne = 7.0;
			const double zeittakt = 0.5; //Zudem noch der Zeittakt mit 1.0
	//Globale Uhr
			while(dGlobaleZeit < zeitspanne){
				dGlobaleZeit += zeittakt;
				weg1.vSimulieren();
				weg2.vSimulieren();

				out<<weg1<<std::endl<<std::endl<<weg2<<std::endl<<std::endl;
				//out<<weg2<<std::endl;
			}

}
void vAufgabe_6(std::ostream& out){
	dGlobaleZeit = 0.0;
	//Ausgabe des aktuellen Pfades der SImuServer.jar zur Kontrolle
		std::filesystem::path currentPath = std::filesystem::current_path();
		std::cout << "Current Working Directory: " << currentPath << std::endl;
	//Initalisiere die Wege
		Weg weg1("Ring", 500, 2);
		Weg weg2("A4", 500, 3);
	//Verbinden mit Grafikserver und initalisierung des Grafikfensters
		bInitialisiereGrafik(1600, 1000);
		int iKoordinaten[] = { 700, 250, 100, 250 };
	//Zeichnen der Straße
		bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), 500, 2, iKoordinaten);
		//bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), weg1.dGetLaenge() , weg2.dGetLaenge(), iKoordinaten);
		//bZeichneStrasse("A4","A2", 500, 2, iKoordinaten);

	//Erzeugen der Fahrzeuge
		std::unique_ptr<Fahrzeug> Koenigsegg = std::make_unique<PKW>("Koenigsegg", 295, 15, 130);
		std::unique_ptr<Fahrzeug> VW = std::make_unique<PKW>("VW", 256, 15, 90);
		std::unique_ptr<Fahrzeug> Porsche = std::make_unique<PKW>("Porsche911", 290, 15, 130);
		std::unique_ptr<Fahrzeug>Nissan = std::make_unique<PKW>("Nissan", 254, 13, 80);
		std::unique_ptr<Fahrzeug>Audi = std::make_unique<PKW>("Audi", 150, 8, 55);
		std::unique_ptr<Fahrzeug>BMX = std::make_unique<Fahrrad>("BMX", 20);
		std::unique_ptr<Fahrzeug>Hollandrad = std::make_unique<Fahrrad>("Hollandrad", 17);

		weg1.vAnnahme(move(Koenigsegg));
		weg1.vAnnahme(move(VW));
		weg1.vAnnahme(move(Porsche), 3);
		weg1.vAnnahme(move(Hollandrad));
		weg2.vAnnahme(move(Nissan));
		weg2.vAnnahme(move(Audi));
		weg2.vAnnahme(move(BMX));

		//static mt19937 device(0);
			//uniform_int_distribution<int> dist(1, 10);
	//Startsignal
		std::cout << std::endl;
		std::cout << "=== Start ===" << std::endl;
		std::cout << std::endl;

	//Angeben der zu simulierenden Zeitspanne und der Zeitintervalle
		const double zeitspanne = 15.0;
		const double zeittakt = 0.01; //Zudem noch der Zeittakt mit 1.0
	//Globale Uhr
		while(dGlobaleZeit < zeitspanne){
			dGlobaleZeit += zeittakt;
	//Setzte vSetzeZeit auf Globale Zeit
			vSetzeZeit(dGlobaleZeit);
			weg1.vSimulieren();
			weg2.vSimulieren();

			weg1.vZeichneFahrzeuge();
			weg2.vZeichneFahrzeuge();
	//Ausgabe durch den outputstream
			out<<weg1<<std::endl<<weg2<<std::endl<<std::endl;

			std::cout<<"Ende des Zyklus"<<std::endl;
	//Weitere Programmausführung wird um (hier 1) Millisekunden verzögert
		vSleep(10);
		}

		char c;
		std::cin >> c;
		vBeendeGrafik();
		dGlobaleZeit = 0.0;
}

void vAufgabe_6a(std::ostream& out){
	dGlobaleZeit = 0.0;
	//Erzeugen eines pseudo random Generator
	//Erzeugen einer statischen Varriabel mit dem Algorithmus 19937 = Mersenne Twister Engine + der seed
		static std::mt19937 device(0);
	//Gleichverteilung mit Integerzahlen. Hier wird das Intervall festgelegt
		std::uniform_int_distribution<int> dist(1, 10);
		/*int zuf = dist(device); // Beispiel aus Skript
		out << zuf << std::endl;*/
		vertagt::VListe<int> liste1;
		for (int i = 0; i < 10; i++)
		{
			liste1.push_back(dist(device));
		}
		liste1.vAktualisieren();
		out << "Liste mit einlesen der Zahlen nach aktualisieren:  " << std::endl;
		for (auto it = liste1.begin(); it != liste1.end(); it++)
		{
			out << *it << std::endl;
		}
		out << std::endl;
		for (auto it = liste1.begin(); it != liste1.end(); it++)
		{
	//Alle Werte die Größer sind als 5 werden gelöscht
			if (*it > 5)
			{
				liste1.erase(it);
			}
		}
		out << "Liste nach erase vor aktualisieren: " << std::endl;
		for (auto it = liste1.begin(); it != liste1.end(); it++)
		{
			out << *it << std::endl;
		}
		out << std::endl;
		out << "Liste nach erase nach aktualsieren: " << std::endl;
		liste1.vAktualisieren();
		for (auto it = liste1.begin(); it != liste1.end(); it++)
		{
			out << *it << std::endl;
		}
		out << std::endl;
		liste1.push_front(9);
		liste1.push_back(2);
		liste1.vAktualisieren();
		out << "Liste mit neuen Zahlen aktualisieren: " << std::endl;
		for (auto it = liste1.begin(); it != liste1.end(); it++)
		{
			out << *it << std::endl;
		}
		out << std::endl;
}

void vAufgabe_7(std::ostream& out){
	dGlobaleZeit = 0.0;

	//Ausgabe des aktuellen Pfades der SimuServer.jar zur Kontrolle
			std::filesystem::path currentPath = std::filesystem::current_path();
			std::cout << "Current Working Directory: " << currentPath << std::endl;

	//Einfügen von randDouble um zufällige Werte zu erzeugen
			double randDouble(int lower, int upper);

	//Verbinden mit Grafikserver und initalisierung des Grafikfensters
			bInitialisiereGrafik(1600, 1000);

	//Initialisiere die Kreuzungen
			std::shared_ptr<Kreuzung> kr1 = std::make_shared<Kreuzung>("Kr1", 0.0);
			std::shared_ptr<Kreuzung> kr2 = std::make_shared<Kreuzung>("Kr2", 1000.0);
			std::shared_ptr<Kreuzung> kr3 = std::make_shared<Kreuzung>("Kr3", 0.0);
			std::shared_ptr<Kreuzung> kr4 = std::make_shared<Kreuzung>("Kr4", 0.0);

	//Festlegen von dem Namen der Wege
			char cNamenDerWege1a[] = "BaumH";
			char cNamenDerWege1b[] = "BaumZ";
			char cNamenDerWege2a[] = "A4H";
			char cNamenDerWege2b[] = "A4Z";
			char cNamenDerWege3a[] = "WieseH";
			char cNamenDerWege3b[] = "WieseZ";
			char cNamenDerWege4a[] = "EckertH";
			char cNamenDerWege4b[] = "EckertZ";
			char cNamenDerWege5a[] = "A1H";
			char cNamenDerWege5b[] = "A1Z";
			char cNamenDerWege6a[] = "B12H";
			char cNamenDerWege6b[] = "B12Z";

	//Festlegen von den Längen der Wege
			double dLaengeVonWeg1 = 40.0;
			double dLaengeVonWeg2 = 115.0;
			double dLaengeVonWeg3 = 40.0;
			double dLaengeVonWeg4 = 55.0;
			double dLaengeVonWeg5 = 85.0;
			double dLaengeVonWeg6 = 130.0;

	//Festlegen der Koordinaten und zeichnen der Kreuzungen
			bZeichneKreuzung(680, 40);
			bZeichneKreuzung(680, 300);
			bZeichneKreuzung(680, 570);
			bZeichneKreuzung(320, 300);

	//Straßen erstellen und mit den Kreuzungen verbinden
			Kreuzung::vVerbinde(cNamenDerWege1a, cNamenDerWege1b, kr1, kr2, dLaengeVonWeg1, 1, false);
			Kreuzung::vVerbinde(cNamenDerWege2a, cNamenDerWege2b, kr2, kr3, dLaengeVonWeg2, 3, false);
			Kreuzung::vVerbinde(cNamenDerWege3a, cNamenDerWege3b, kr2, kr3, dLaengeVonWeg3, 1, false);
			Kreuzung::vVerbinde(cNamenDerWege4a, cNamenDerWege4b, kr2, kr4, dLaengeVonWeg4, 1, false);
			Kreuzung::vVerbinde(cNamenDerWege5a, cNamenDerWege5b, kr3, kr4, dLaengeVonWeg5, 3, false);
			Kreuzung::vVerbinde(cNamenDerWege6a, cNamenDerWege6b, kr4, kr4, dLaengeVonWeg6, 2, false);

	//Festlegen der Koordinaten zum zeichnen der Wege
			int iKoordinaten1[] = {680, 40, 680, 300};/*{ 700, 250, 100, 250 }*///Für einen Geraden Weg
			int iKoordinaten2[] = {680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
			int iKoordinaten3[] = {680, 300, 680, 570};
			int iKoordinaten4[] = {680, 300, 320, 300};
			int iKoordinaten5[] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300};
			int iKoordinaten6[] = {320, 300, 320, 150, 200, 60, 80, 90, 70, 250, 170, 300, 320, 300};

	//Zeichnen der Straße
			bZeichneStrasse(cNamenDerWege1a, cNamenDerWege1b, dLaengeVonWeg1, 2, iKoordinaten1);
			bZeichneStrasse(cNamenDerWege2a, cNamenDerWege2b, dLaengeVonWeg2, 6, iKoordinaten2);
			bZeichneStrasse(cNamenDerWege3a, cNamenDerWege3b, dLaengeVonWeg3, 2, iKoordinaten3);
			bZeichneStrasse(cNamenDerWege4a, cNamenDerWege4b, dLaengeVonWeg4, 2, iKoordinaten4);
			bZeichneStrasse(cNamenDerWege5a, cNamenDerWege5b, dLaengeVonWeg5, 5, iKoordinaten5);
			bZeichneStrasse(cNamenDerWege6a, cNamenDerWege6b, dLaengeVonWeg6, 7, iKoordinaten6);

	//Erzeugen der Fahrzeuge
			std::unique_ptr<Fahrzeug> Koenigsegg = std::make_unique<PKW>("Koenigsegg", 291, 15, 50);
			std::unique_ptr<Fahrzeug> Porsche = std::make_unique<PKW>("Porsche_911", 210, 15, 90);
			std::unique_ptr<Fahrzeug>Nissan = std::make_unique<PKW>("Nissan", 240, 13, 80);
			std::unique_ptr<Fahrzeug>BMX = std::make_unique<Fahrrad>("BMX", 20);
			std::unique_ptr<Fahrzeug> Mercedes = std::make_unique<PKW>("Mercedes", randDouble(50, 200), randDouble(4, 10),randDouble(70, 120));

			kr1->vAnnahme(move(Mercedes),0);
			kr1->vAnnahme(move(Koenigsegg), 1.0);
			kr1->vAnnahme(move(Porsche), 3.0);
			kr1->vAnnahme(move(Nissan), 2.0);
			kr1->vAnnahme(move(BMX), 4.0);


	//Startsignal
			std::cout << std::endl;
			std::cout << "=== Start ===" << std::endl;
			std::cout << std::endl;

	//Angeben der zu simulierenden Zeitspanne und der Zeitintervalle
			const double zeitspanne = 30.0;
			const double zeittakt = 0.01; //Zudem noch der Zeittakt mit 1.0
	//Globale Uhr
			while(dGlobaleZeit < zeitspanne){
				dGlobaleZeit += zeittakt;
	//Setzte vSetzeZeit auf Globale Zeit
				vSetzeZeit(dGlobaleZeit);
	//Simuliere Kreuzungen
				kr1->vSimulieren();
				kr2->vSimulieren();
				kr3->vSimulieren();
				kr4->vSimulieren();

				//std::cout<<"Ende des Zyklus"<<std::endl;
	//Weitere Programmausführung wird um (hier 10) Millisekunden verzögert
				vSleep(10);
			}

			char c;
			std::cin >> c;
			vBeendeGrafik();
}


int main(){

	//vAufgabe_1(std::cout);
	//vAufgabe_1a(std::cout);
	//vAufgabe_2(std::cout);
	//vAufgabe_3(std::cout);
	//vAufgabe_4(std::cout);
	//vAufgabe_5(std::cout);
	//vAufgabe_5a(std::cout);
	//vAufgabe_6(std::cout);
	//vAufgabe_6a(std::cout);
	vAufgabe_7(std::cout);
	return 0;
}
