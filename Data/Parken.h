/*
 * Parken.h
 *
 *  Created on: 07.01.2024
 *      Author: Moritz
 */
#pragma once
#ifndef MEINEDATEIEN_PARKEN_H_
#define MEINEDATEIEN_PARKEN_H_

#include "Verhalten.h"
#include "Losfahren.h"
#include <cmath> // Für std::abs
class Fahrzeug;

class Parken : public Verhalten{
	public:
		Parken(Weg& weg, double dStartzeitpunkt);
		virtual ~Parken();
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall)override;

	private:
		double p_dStartzeitpunkt;

};

#endif /* MEINEDATEIEN_PARKEN_H_ */
//cmath erklärungIm Codebeispiel wird std::abs() verwendet, um den absoluten Wert der Differenz zwischen dGlobaleZeit und p_dStartzeitpunkt zu berechnen.
//Der Grund dafür ist, dass Vergleiche zwischen Gleitkommazahlen manchmal aufgrund von Rundungsfehlern oder Genauigkeitsproblemen problematisch sein können. Die Verwendung von std::abs()
//in diesem Kontext dient dazu, eine kleine Toleranz (in diesem Fall tolerance = 0.00001) zuzulassen und sicherzustellen, dass die beiden Werte nahe genug beieinander liegen, um als gleich betrachtet zu werden.
