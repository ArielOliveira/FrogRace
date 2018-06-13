#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "fileHandler.h"

#include "lista.h"
#include "sapo.h"
#include "corrida.h"

#define TAMANHO_MINIMO_CORRIDA 100

#define TAMANHO_MAXIMO_CORRIDA 500

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

template <typename T>
void atualizarDados(List<T> *l, const char *c) {
	ofstream file;

	file.open(c, std::ios::trunc);

	if (!file) {
		cout << "Erro ao escrever no arquivo!" << endl;
	} else {
		for (typename List<T>::iterator it = l->getBegin(); it != l->getEnd(); it++) {
			file << *(*it);
		}
	}
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

#endif