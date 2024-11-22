/*
 * Tempolimit.h
 *
 *  Created on: 02.01.2024
 *      Author: morit
 */
#pragma once
#ifndef MEINEDATEIEN_TEMPOLIMIT_H_
#define MEINEDATEIEN_TEMPOLIMIT_H_

#include <limits>

// Definition des eigenen Enums für Tempolimit
enum class Tempolimit {
		Innerorts = 50,
		Landstrasse = 100,
		//Autobahn = std::numeric_limits<int>::max()
		Autobahn = 1000
};



#endif /* MEINEDATEIEN_TEMPOLIMIT_H_ */
