#pragma once

#include "vertagt_aktion.h"
#include <list>
//#include <memory>


namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = default;
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}

		void clear()
		{
			vAktualisieren();
			p_objekte.clear(); 	
		}

		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.cbegin();
		}
		const_iterator end() const
		{
			return p_objekte.cend(); 
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end(); 
		}
		bool empty() const
		{
			return p_objekte.empty(); 
		}

		// Schreibfunktionen
		void push_back(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushBack<T>>(p_objekte,std::move(obj)));
		}

		void push_front(T obj)
		{
			// Aktionselement für PushFront auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushFront<T>>(p_objekte,std::move(obj)));
		}

		void erase(iterator it)
		{
			// Aktionselement für Erase auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(std::make_unique<VErase<T>>(p_objekte, it));
		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren()
		{
			while (!p_aktionen.empty())
			{
				// Aktionszeiger auf 1. Element bestimmen
				std::unique_ptr <VAktion<T>> p_aktion = std::move(*(p_aktionen.begin()));

				// Aktion ausführen
				p_aktion->vAusfuehren();
				p_aktionen.pop_front();
			
			}
			// Liste leeren
			p_aktionen.clear();
		}
	};
} // namespace vertagt
