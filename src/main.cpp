/**
* @file 	main.cpp
* @brief 	Programa que simula uma corrida de
*			sapos
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		16/06/2018
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include "dataManager.h"

/** Enum Menu 
*   Uma enumeração com as opções do menu principal.
*/
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

/** 
* @brief Verifica se o sapo passou a linha de chegada
* @param *sapo Objeto da classe Sapo
* @return true Caso o sapo tenha ganhado
*/
bool venceu(Sapo *sapo) {
	return (sapo->getDistanciaPercorrida() >= Sapo::distanciaCorrida);
}

/** 
* @brief Verifica se o sapo s1 e s2 estão em condição de empate
* @param *s1 Objeto da classe Sapo
* @param *s2 Objeto da classe Sapo
* @return true Se os sapos estiverem na condição tratada
*/
bool empatou(Sapo *s1, Sapo *s2) {
	return (s1->getDistanciaPercorrida() == s2->getDistanciaPercorrida() && s1->getPulosDados() == s2->getPulosDados());
}


/** 
* @brief Mostra o ranking dos sapos na ordem de chegada
* @param *finalistas Objeto de uma TAD List
* @return void
*/
void mostrarRanking(List<Sapo*> *finalistas) {
	cout << "<<><><><><><>> Ranking <<><><><><><>>" << endl;
	for (List<Sapo*>::iterator it = finalistas->getBegin(); it != finalistas->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

/** 
* @brief Mostra a lista de sapos carregados no programa
* @param *s Objeto de uma TAD List
* @return void
*/
void exibirSaposStats(List<Sapo*> *s) {
	for (List<Sapo*>::iterator it = s->getBegin(); it != s->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

/** 
* @brief Mostra a lista de corridas carregadas no programa
* @param *c Objeto de uma TAD List
* @return void
*/
void exibirCorridasStats(List<Corrida*> *c) {
	for (List<Corrida*>::iterator it = c->getBegin(); it != c->getEnd(); it++) {
		cout << *(*it) << endl;
	}
}

/** 
* @brief Executa a corrida propriamente dita, determinando
		 o sapo vencedor.
* @param *s Objeto de uma TAD List contendo os sapos a competir
* @return void
*/
void determinarVencedor(List<Sapo*> *s) {
	string dummy;

	cout << "<><><><><>> Participantes <<><><><>>" << endl;
	exibirSaposStats(s);
	cout << "Enter para Iniciar a Corrida" << endl;
	getline(cin, dummy);

	dummy = "";

	List<Sapo*> *finalistas = new List<Sapo*>();
	int pulo = 0, valor = 0;
	bool pausar = true;

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
				sapo->incrementarProvasDisputadas();
				finalistas->insertAtTail(sapo);
				s->removeMember(it.getNode());

			}
		}
	}

	cout << finalistas->getData(1)->getNome() << " Venceu!" << endl;

	finalistas->getData(1)->incrementarVitoria();
	mostrarRanking(finalistas);
	atualizarDados<Sapo*>(finalistas, diretorioSapos);

	delete finalistas;

}

/** 
* @brief Mostra um menu de escolha das corridas para o usuário
* @param *  Objeto de uma TAD List contendo as corridas
* @return int Opção escolhida pelo usuário
*/
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

/** 
* @brief Exibe o menu principal do programa
* @return int Opção escolhida pelo usuário
*/
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
						  determinarVencedor(sapos);
						  
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