#include "corrida.h"

#include "fileHandler.h"

#include <iostream>

Corrida::Corrida(string nome, int id, int tamanhoCircuito) : nome(nome), id(id), tamanhoCircuito(tamanhoCircuito) {preloaded = true;}

Corrida::Corrida(int line) {
	ifstream file;
	file.open(diretorioCorridas);

	if (!file) {
		std::cout << "Erro ao abrir arquivo!" << std::endl;
	} else {
		readCSVFile(file, line);
		file >> *this;
	}

	preloaded = true;

	file.close();
}

Corrida::Corrida() {
	nome = "";
	id = 0;
	tamanhoCircuito = 0;

	preloaded = false;
}

Corrida::~Corrida() {}

void Corrida::setNome(string nome) {if (!preloaded) this->nome = nome;}
string Corrida::getNome() {return nome;}

void Corrida::setId(int id) {if (!preloaded) this->id = id;}
int Corrida::getId() {return id;}

void Corrida::setTamanhoCircuito(int tamanhoCircuito) {if (!preloaded) this->tamanhoCircuito = tamanhoCircuito;}
int Corrida::getTamanhoCircuito() {return tamanhoCircuito;}

istream& operator>> (istream &i, Corrida &_c) {
	string valor;

	getline(i, valor, ';');
	_c.nome = valor;

	i >> _c.id;
	i.ignore();

	i >> _c.tamanhoCircuito;

	return i;

}

ostream& operator<< (ostream &o, const Corrida &_c) {
	o << "Nome: " << _c.nome << std::endl
	  << "Tamanho do Circuito: " << _c.tamanhoCircuito << std::endl;

	return o;
}

ofstream& operator<< (ofstream &of, const Corrida &_c) {
	of << std::to_string(_c.id) << ';'
	   << _c.nome << ';'
	   << std::to_string(_c.id) << ';'
	   << std::to_string(_c.tamanhoCircuito) << ';' << std::endl;

	return of;

}