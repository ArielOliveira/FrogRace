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
int carregarDados(List<T> *l, const char *c) {
	ifstream file;
	file.open(c);

	string dummy;
	int linhas;

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		resetStreamCursor(file);
		linhas = 0;
		dummy = "";
		while(getline(file, dummy, '\n')) {linhas++;}

		for (int i = 0; i < linhas; i++) {
			l->insertAtTail(new Y(i));
		}
	}
	file.close();

	return linhas+1;
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

void criarSapo(List<Sapo*> *s, int &id) {
	string nome;

	while(nomeExiste(s, nome, "do seu sapo")) cout << "Nome já existe. Tente outro nome!" << endl;

	s->insertAtTail(new Sapo(nome, id, 0, 0, 0, 0));
	salvarDado<Sapo>(*s->getData(s->getSize()), diretorioSapos);
}

void criarCorrida(List<Corrida*> *c, int &id) {
	string nome, valor;

	int tamanho = 0;

	while(nomeExiste(c, nome, "da sua corrida")) cout << "Nome já existe. Tente outro nome!" << endl;

	while((tamanho < TAMANHO_MINIMO_CORRIDA || tamanho > TAMANHO_MAXIMO_CORRIDA)) {
		cout << "<><> Insira um valor entre 100 e 500 para o tamanho da sua corrida <><>" << endl;
		getline(cin, valor);
		stringstream(valor) >> tamanho;
	}

	c->insertAtTail(new Corrida(nome, id, tamanho));
	salvarDado<Corrida>(*c->getData(c->getSize()), diretorioCorridas);
}

#endif