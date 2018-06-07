#ifndef CORRIDA_H
#define CORRIDA_H

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

class Corrida {
	private:
		string nome;

		int id;
		int tamanhoCircuito;
	public:
		Corrida(string nome, int id, int tamanhoCircuito);
		Corrida(ifstream &file, int line);
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

};

#endif