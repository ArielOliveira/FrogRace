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

#include "fileHandler.h"
#include "sapo.h"
#include "corrida.h"

#include "lista.h"

#define TAMANHO_MINIMO_CORRIDA 100

#define TAMANHO_MAXIMO_CORRIDA 500

//int Sapo::distanciaCorrida = TAMANHO_TOTAL_CORRIDA;


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

template <typename T>
bool nomeExiste(List<T> *s, string &nome, const char *k) {

	cout << "<><><><> Insira o nome " << k << "<><><><>" << endl;
	cout << "Nome: ";
	getline(cin, nome);

	for (typename List<T>::iterator it = s->getBegin(); it != s->getEnd(); it++) {
		T sapo = *it;

		if (sapo->getNome() == nome) return true;
	}

	return false;
}

template <typename T, typename Y>
void carregarDados(List<T> *l, const char *c) {
	ifstream file;
	file.open(c);

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		resetStreamCursor(file);
		string dummy = "";
		int linhas = 0;
		while(getline(file, dummy, '\n')) {linhas++;}

		for (int i = 0; i < linhas; i++) {
			l->insertAtTail(new Y(i));
		}
	}
	file.close();
}

template <typename T>
void salvarDado(T obj, const char *c) {
	ofstream file;
	file.open(c, std::ios::app);

	if (!file) {
		cout << "Erro ao salvar sapo no arquivo!" << endl;
	} else {
		file << obj;
	}

	file.close();
}

void criarSapo(List<Sapo*> *s) {
	string nome;

	while(nomeExiste(s, nome, "do seu sapo")) cout << "Nome já existe. Tente outro nome!" << endl;

	if (s->getSize() > 0) {
		List<Sapo*>::iterator it = s->getEnd();
		it--;
		Sapo *sapo = *it;
		s->insertAtTail(new Sapo(nome, sapo->getId()+1, 0, 0, 0, 0));
		it++;
		salvarDado<Sapo>(*(*it), diretorioSapos);
	} else {
		s->insertAtTail(new Sapo(nome, 0, 0, 0, 0, 0));
		salvarDado<Sapo>(*s->getData(1), diretorioSapos);
	}
}

void criarCorrida(List<Corrida*> *c) {
	string nome, valor;
	int tamanho = 0;

	while(nomeExiste(c, nome, "da sua corrida")) cout << "Nome já existe. Tente outro nome!" << endl;

	while((tamanho < TAMANHO_MINIMO_CORRIDA || tamanho > TAMANHO_MAXIMO_CORRIDA)) {
		cout << "<><> Insira um valor entre 100 e 500 para o tamanho da sua corrida <><>" << endl;
		getline(cin, valor);
		stringstream(valor) >> tamanho;
	}

	if (c->getSize() > 0) {
		List<Corrida*>::iterator it = c->getEnd();
		it--;	
		Corrida *corrida = *it;
		c->insertAtTail(new Corrida(nome, corrida->getId()+1, tamanho));
		it++;
		salvarDado<Corrida>(*(*it), diretorioCorridas);
	} else {
		c->insertAtTail(new Corrida(nome, 0, tamanho));
		salvarDado<Corrida>(*c->getData(1), diretorioCorridas);
	}
}

int main() {

	List<Sapo*> *sapos = new List<Sapo*>();
	carregarDados<Sapo*, Sapo>(sapos, diretorioSapos);

	List<Corrida*> *corridas = new List<Corrida*>();
	carregarDados<Corrida*, Corrida>(corridas, diretorioCorridas);

	criarSapo(sapos);

	criarCorrida(corridas);

	
	for (List<Corrida*>::iterator it = corridas->getBegin(); it != corridas->getEnd(); it++) {
			cout << *(*it) << endl;
		}

	/*
	ofstream file;

	file.open(diretorioSapos, std::ios::trunc);

	if (!file) {
		cout << "Erro ao escrever no arquivo!" << endl;
	} else {
		for (List<Sapo*>::iterator it = sapos->getBegin(); it != sapos->getEnd(); it++) {
			file << *(*it);
		}
	}
	*/



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