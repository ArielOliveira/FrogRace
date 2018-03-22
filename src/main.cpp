/**
* @file 	main.cpp
* @brief 	Programa que simula uma corrida de
*			sapos
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
 * @date	22/03/2017
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "sapos.h"

#define TAMANHO_TOTAL_CORRIDA 100

int Sapos::distanciaCorrida = TAMANHO_TOTAL_CORRIDA;

bool venceu(Sapos *sapo) {
	sapo->pular();

	return (sapo->getDistanciaPercorrida() >= TAMANHO_TOTAL_CORRIDA);
}

Sapos* determinaVencedor(Sapos *sapo_1, Sapos *sapo_2, Sapos *sapo_3) {
	Sapos *sapo_ptr;

	bool continua = true;

	while(continua) {
		sapo_ptr = sapo_1;
		if (venceu(sapo_ptr)) {
			return sapo_ptr;	
		} 

		sapo_ptr = sapo_2;
		if (venceu(sapo_ptr)) {
			return sapo_ptr;		
		} 

		sapo_ptr = sapo_3;
		if (venceu(sapo_ptr)) {
			return sapo_ptr;
		}
	}

	return NULL;
}

int main() {
	Sapos *sapo_1, *sapo_2, *sapo_3;
	
	
	sapo_1 = new Sapos(1);
	sapo_2 = new Sapos(2);
	sapo_3 = new Sapos(3);

	Sapos *sapo_ptr = determinaVencedor(sapo_1, sapo_2, sapo_3);

	cout << "O sapo " << sapo_ptr->getId() << " venceu com "
		 << sapo_ptr->getPulosDados() <<" pulos, percorrendo " 
		 << sapo_ptr->getDistanciaPercorrida() << endl;

	return 0;
}