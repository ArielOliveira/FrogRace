#include "sapos.h"

#include <stdlib.h>

#include <time.h>

#define PULO_MAXIMO 5

int randN(int MAX) {
	int n;
	do {
		n = rand()%MAX;
	} while (!n);

	return n;
}

Sapos::Sapos(short int id) {
	this->id = id;

	pulosDados = 0;
	distanciaPercorrida = 0;

	srand(time(NULL));
}

Sapos::Sapos() {
	id = 0;
	distanciaPercorrida = 0;
	pulosDados = 0;
}

Sapos::~Sapos() {}


void Sapos::setId(short int id) {
	if (!id)
	 	this->id = id;
}

int Sapos::getId() {return id;}

int Sapos::getDistanciaPercorrida() {return distanciaPercorrida;}

int Sapos::getPulosDados() {return pulosDados;}

void Sapos::pular() {
	distanciaPercorrida += randN(PULO_MAXIMO);
	pulosDados += 1;
}