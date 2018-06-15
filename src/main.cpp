/**
* @file 	main.cpp
* @brief 	Programa que simula uma corrida de
*			sapos
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		15/06/2018
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include "dataManager.h"

enum Menu {
	NULO,
	SAPO_STATS,
	CORRIDA_STATS,
	INICIAR,
	CRIAR_SAPO,
	CRIAR_CORRIDA,
	SAIR
};

int Sapo::distanciaCorrida = 0;

bool venceu(Sapo *sapo) {
	return (sapo->getDistanciaPercorrida() >= Sapo::distanciaCorrida);
}

void mostrarRanking(List<Sapo*> *vencedores) {
	cout << "<<><><><><><>> VENCEDORES <<><><><><><>>" << endl;
	for (List<Sapo*>::iterator it = vencedores->getBegin(); it != vencedores->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

void determinaVencedor(List<Sapo*> *s) {
	List<Sapo*> *vencedores = new List<Sapo*>();
	int pulo = 0, valor = 0;
	bool pausar = true;

	string dummy;
	while(s->getSize()) {
		for (List<Sapo*>::iterator it = s->getBegin(); it != s->getEnd(); it++) {
			Sapo *sapo = *it;

			pulo = sapo->pular();

			cout << *sapo << endl;
			cout << "Pulo atual: " << pulo << endl << endl;
			cout << "Restam: " << Sapo::distanciaCorrida-sapo->getDistanciaPercorrida() << endl;

			if (pausar) {
				cout << "Pressione enter para ver o próximo pulo." << endl << "Digite 1 para o resultado." << endl << endl;
				getline(cin, dummy);
				stringstream(dummy) >> valor;

				if (valor == 1) {pausar = false;}
			}

			if (venceu(sapo)) {
				cout << sapo->getNome() << " cruzou a linha de chegada!" << endl;
				vencedores->insertAtTail(sapo);
				s->removeMember(it.getNode());
			}
		}
	}

	cout << vencedores->getData(1)->getNome() << " Venceu!" << endl;

	vencedores->getData(1)->incrementarVitoria();
	mostrarRanking(vencedores);
	atualizarDados<Sapo*>(vencedores, diretorioSapos);

	delete vencedores;

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
	int i = 1;

	cout << "<><><> Escolha sua corrida <><><>" << endl;
	for (it = c->getBegin(); it != c->getEnd(); it++) {
		cout << i << " - " << *(*it) << endl;
		i++;
	}

	int escolha = -1;
	string valor = "";

	while (escolha < 1 || escolha > c->getSize()) {
		getline(cin, valor);
		stringstream(valor) >> escolha;
	}

	i = 0;
	Corrida *corrida;
	for (it = c->getBegin(); (it != c->getEnd()) && (i != escolha-1); it++) {
		i++;	
	}
	corrida = *it;

	return corrida->getTamanhoCircuito();
}

void menu() {
	cout << "><><><><> Menu da Corrida dos Sapos <><><><><" << endl;
	cout << "1 - Ver Estatísticas dos Sapos" << endl;
	cout << "2 - Ver Estatísticas das Corridas" << endl;
	cout << "3 - Iniciar um corrida" << endl;
	cout << "4 - Criar Sapo" << endl;
	cout << "5 - Criar Corrida" << endl;
	cout << "6 - Sair" << endl;
}

int main() {

	List<Sapo*> *sapos = new List<Sapo*>();
	int proximoSapo = carregarDados<Sapo*, Sapo>(sapos, diretorioSapos);

	List<Corrida*> *corridas = new List<Corrida*>();
	int proximaCorrida = carregarDados<Corrida*, Corrida>(corridas, diretorioCorridas);

	Menu m;

	do {
		menu();

		string opcao = "";
		int valor = 0;

		getline(cin, opcao);
		stringstream(opcao) >> valor;

		m = (Menu)valor;

		switch(m) {
			case SAPO_STATS: exibirSaposStats(sapos);
				break;
			case CORRIDA_STATS: exibirCorridasStats(corridas);
				break;
			case INICIAR: Sapo::distanciaCorrida = escolherCorrida(corridas);
						  determinaVencedor(sapos);
						  
						  carregarDados<Sapo*, Sapo>(sapos, diretorioSapos);
				break;
			case CRIAR_SAPO: criarSapo(sapos, proximoSapo);
				break;
			case CRIAR_CORRIDA: criarCorrida(corridas, proximaCorrida);
				break;
			default:
				break;
		} 

	} while(m != SAIR);

	delete sapos;
	delete corridas;

	return 0;
}