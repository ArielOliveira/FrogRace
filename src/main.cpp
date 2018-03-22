#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "sapos.h"

#define TAMANHO_TOTAL_CORRIDA 100

int Sapos::distanciaCorrida = TAMANHO_TOTAL_CORRIDA;

bool venceu(Sapos *sapo) {
	sapo->pular();
	if(sapo->getDistanciaPercorrida() >= TAMANHO_TOTAL_CORRIDA) {
		return true;
	} else {
		return false;
	}
}

int main() {
	Sapos *sapo_1, *sapo_2, *sapo_3;

	Sapos *sapo_ptr;

	bool continua = true;
	
	sapo_1 = new Sapos(1);
	sapo_2 = new Sapos(2);
	sapo_3 = new Sapos(3);

	while(continua) {
		sapo_ptr = sapo_1;
		if (venceu(sapo_ptr)) {
			break;	
		} 

		sapo_ptr = sapo_2;
		if (venceu(sapo_ptr)) {
			break;		
		} 

		sapo_ptr = sapo_3;
		if (venceu(sapo_ptr)) {
			break;
		}
	}

	cout << "O sapo " << sapo_ptr->getId() << " venceu com " << sapo_ptr->getPulosDados() << " pulos!" << endl;

	return 0;
}