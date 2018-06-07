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

#include "sapo.h"

#include "lista.h"

#define TAMANHO_TOTAL_CORRIDA 100

int Sapo::distanciaCorrida = TAMANHO_TOTAL_CORRIDA;


/*
bool venceu(Sapo *sapo) {
	sapo->pular();

	return (sapo->getDistanciaPercorrida() >= TAMANHO_TOTAL_CORRIDA);
}

Sapo* determinaVencedor(Sapo *sapo_1, Sapo *sapo_2, Sapo *sapo_3) {
	Sapo *sapo_ptr;

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

*/

int main() {

	List<Sapo*> *sapos = new List<Sapo*>();


	/*
	Sapo *sapo_1, *sapo_2, *sapo_3;
	
	
	sapo_1 = new Sapo(1);
	sapo_2 = new Sapo(2);
	sapo_3 = new Sapo(3);

	Sapo *sapo_ptr = determinaVencedor(sapo_1, sapo_2, sapo_3);

	cout << "O sapo " << sapo_ptr->getId() << " venceu com "
		 << sapo_ptr->getPulosDados() <<" pulos, percorrendo " 
		 << sapo_ptr->getDistanciaPercorrida() << endl;
	*/
	return 0;
}