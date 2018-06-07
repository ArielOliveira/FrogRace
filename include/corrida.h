#ifndef CORRIDA_H
#define CORRIDA_H

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

static const char *diretorioCorridas = "./data/corridas.csv";

class Corrida {
	private:
		bool preloaded;

		string nome;

		int id;
		int tamanhoCircuito;
	public:
		Corrida(string nome, int id, int tamanhoCircuito);
		Corrida(int line);
		Corrida();
		~Corrida();

		void setNome(string nome);
		string getNome();

		void setId(int id);
		int getId();

		void setTamanhoCircuito(int tamanhoCircuito);
		int getTamanhoCircuito();

		friend istream& operator>> (istream &i, Corrida &_c);

		friend ostream& operator<< (ostream &o, const Corrida &_c);

		friend ofstream& operator<< (ofstream &of, const Corrida &_c);

};

#endif