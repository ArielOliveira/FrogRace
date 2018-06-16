/**
* @file 	dataManager.h
* @brief 	Responsável por carregar e salvar as informaçoes
*			das classes em arquivo.
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		16/06/2018
*/

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "fileHandler.h"

#include "lista.h"
#include "sapo.h"
#include "corrida.h"

#define TAMANHO_MINIMO_CORRIDA 100

#define TAMANHO_MAXIMO_CORRIDA 500

/** 
* @brief Recebe um objeto de Lista, Sapo ou Corrida, e verifica
*        se o nome já existe dentro da Lista
* @param *s Objeto genérico de uma TAD Lista
* @param &nome Uma string contendo o nome a ser comparado
* @param *k Uma constante de char que será impresso na tela
* @return true Se o nome existir. Caso contrário, retorna false.
*/
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

/** 
* @brief Azualiza os dados do arquivo
* @param *l Objeto genérico de uma TAD Lista
* @param *c Uma constante de char que contém o diretório do arquivo
* @return void
*/
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

/** 
* @brief Carrega os dados do arquivo em classes e
*		 os insere dentro da Lista	
* @param *l Objeto genérico de uma TAD Lista
* @param *c Uma constante de char que contém o diretório do arquivo
* @return void
*/
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


/** 
* @brief Salva um objeto T no arquivo (onde T pode ser um Sapo ou uma Corrida)
* @param obj Objeto de uma classe (Sapo ou Corrida)
* @param *c Uma constante de char que contém o diretório do arquivo
* @return void
*/
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

/** 
* @brief Cria uma classe sapo e a insere na Lista
* @param *s Objeto de uma classe (Sapo)
* @param &id Inteiro que representa o ID do próximo sapo
			 a ser inserido na lista
* @return void
*/
void criarSapo(List<Sapo*> *s, int &id) {
	string nome;

	while(nomeExiste(s, nome, "do seu sapo")) cout << "Nome já existe. Tente outro nome!" << endl;

	s->insertAtTail(new Sapo(nome, id, 0, 0, 0, 0));
	salvarDado<Sapo>(*s->getData(s->getSize()), diretorioSapos);

	id++;
}

/** 
* @brief Cria uma classe corrida e a insere na Lista
* @param *s Objeto de uma classe (Corrida)
* @param &id Inteiro que representa o ID da próximo corrida
			 a ser inserida na lista
* @return void
*/
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

	id++;
}

#endif