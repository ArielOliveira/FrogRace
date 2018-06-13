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

#include <sstream>
using std::stringstream;

#include "dataManager.h"

int Sapo::distanciaCorrida = 0;

bool venceu(Sapo *sapo) {
	
	sapo->pular();

	return (sapo->getDistanciaPercorrida() >= Sapo::distanciaCorrida);
}

List<Sapo*>* determinaVencedor(List<Sapo*> *s) {
	List<Sapo*> *vencedores = new List<Sapo*>();

	while(s->getSize()) {
		for (List<Sapo*>::iterator it = s->getBegin(); it != s->getEnd(); it++) {
			Sapo *sapo = *it;

			if (venceu(sapo)) {
				vencedores->insertAtTail(sapo);
				s->removeMember(it.getNode());
			}
		}
	}
	vencedores->getData(1)->incrementarVitoria();

	return vencedores;
}

void exibirSaposStats(List<Sapo*> *s) {
	for (List<Sapo*>::iterator it = s->getBegin(); it != s->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

void exibirCorridasStats(List<Corrida*> *c) {
	for (List<Corrida*>::iterator it = c->getBegin(); it != c->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

int escolherCorrida(List<Corrida*> *c) {
	List<Corrida*>::iterator it;
	int i = 0;

	cout << "<><><> Escolha sua corrida <><><>" << endl;
	for (it = c->getBegin(); it != c->getEnd(); it++) {
		cout << i << " - " << *(*it) << endl;
		i++;
	}
	i--;

	int escolha = -1;
	string valor = "";

	while (escolha < 0 || escolha > i) {
		getline(cin, valor);
		stringstream(valor) >> escolha;
	}

	i = 0;
	Corrida *corrida;
	for (it = c->getBegin(); (it != c->getEnd()) && (i != escolha); it++) {
		i++;	
	}
	corrida = *it;

	return corrida->getTamanhoCircuito();
}

int main() {

	List<Sapo*> *sapos = new List<Sapo*>();
	carregarDados<Sapo*, Sapo>(sapos, diretorioSapos);

	List<Corrida*> *corridas = new List<Corrida*>();
	carregarDados<Corrida*, Corrida>(corridas, diretorioCorridas);

	Sapo::distanciaCorrida = escolherCorrida(corridas);	

	List<Sapo*> *vencedores = determinaVencedor(sapos);

	cout << "<<><><><><><>> VENCEDORES <<><><><><><>>" << endl;
	for (List<Sapo*>::iterator it = vencedores->getBegin(); it != vencedores->getEnd(); it++) {
		cout << *(*it) << endl;
	}

	atualizarDados<Sapo*>(vencedores, diretorioSapos);

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