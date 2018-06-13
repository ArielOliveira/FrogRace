#include "sapo.h"

#include "fileHandler.h"

#include <iostream>

#include <sstream>
using std::stringstream;

#define PULO_MAXIMO 5

std::random_device Sapo::rd{};
std::mt19937 Sapo::gen(Sapo::rd());
std::uniform_int_distribution<> Sapo::dis(1, PULO_MAXIMO);

Sapo::Sapo(string nome, short int id, int vitorias, int empates, int pulosDadosTotal, int provasDisputadas) {
	this->nome = nome;
	this->id = id;
	this->vitorias = vitorias;
	this->empates = empates;
	this->pulosDadosTotal = pulosDadosTotal;
	this->provasDisputadas = provasDisputadas;

	pulosDados = 0;
	distanciaPercorrida = 0;

	preloaded = true;
}

Sapo::Sapo(int line) {
	ifstream file;
	file.open(diretorioSapos);

	if (!file) {
		std::cout << "Erro ao abrir arquivo!" << std::endl;
	} else {
		readCSVFile(file, line);
		file >> *this;
	}

	preloaded = true;

	file.close();
}

Sapo::Sapo() {
	id = 0;
	distanciaPercorrida = 0;
	pulosDados = 0;

	preloaded = false;
}

Sapo::~Sapo() {}

void Sapo::setNome(string nome) {if (!preloaded) this->nome = nome;}
string Sapo::getNome() {return nome;}


void Sapo::setId(short int id) {if (!preloaded) this->id = id;}
int Sapo::getId() {return id;}


void Sapo::incrementarVitoria() {vitorias++;}
int Sapo::getVitorias() {return vitorias;}
int Sapo::getEmpates() {return empates;}
int Sapo::getPulosDadosTotal() {return pulosDadosTotal;}
int Sapo::getProvasDisputadas() {return provasDisputadas;}

int Sapo::getDistanciaPercorrida() {return distanciaPercorrida;}

int Sapo::getPulosDados() {return pulosDados;}

int Sapo::pular() {
	int pulo = round(dis(gen));

	distanciaPercorrida += pulo;
	pulosDados += 1;

	return pulo;
}

 istream& operator>> (istream &i, Sapo &_s) {
 	string valor;

 	getline(i, valor, ';');
 	_s.nome = valor;

 	i >> _s.id;
 	i.ignore();

 	i >> _s.vitorias;
 	i.ignore();

 	i >> _s.empates;
 	i.ignore();

 	i >> _s.pulosDadosTotal;
 	i.ignore();

 	i >> _s.provasDisputadas;

 	return i;
 }

 ofstream& operator<< (ofstream &of, const Sapo &_s) {

 	of << std::to_string(_s.id) << ';'
 	   << _s.nome << ';'
 	   << std::to_string(_s.id) << ';'
 	   << std::to_string(_s.vitorias) << ';'
 	   << std::to_string(_s.empates) << ';'
 	   << std::to_string(_s.pulosDadosTotal) << ';'
 	   << std::to_string(_s.provasDisputadas) << ';' << std::endl;
	
 	return of;
 }

 ostream& operator<< (ostream &o, const Sapo &_s) {
 	o << "Nome: " << _s.nome << std::endl
 	  << "Vitorias: " << _s.vitorias << std::endl
 	  << "Empates: " << _s.empates << std::endl
 	  << "Pulos Totais: " << _s.pulosDadosTotal << std::endl
 	  << "Provas Disputadas: " << _s.provasDisputadas << std::endl;

 	  return o;

 }