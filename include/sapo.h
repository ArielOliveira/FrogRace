#ifndef SAPOS_H
#define SAPOS_H

#include <random>

#include <string>
using std::string;

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

class Sapo {
	private:
		bool preloaded;

		string nome;

		short int id;

		int vitorias;
		int empates;
		int pulosDadosTotal;
		int provasDisputadas;
		int distanciaPercorrida;
		int pulosDados;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		static int distanciaCorrida;

		Sapo(string nome, short int id, int vitorias, int empates, int pulosDadosTotal, int provasDisputadas);
		Sapo();
		~Sapo();

		void pular();

		void setNome(string nome);
		string getNome();

		void setId(short int id);
		int getId();

		int getVitorias();
		int getEmpates();
		int getPulosDadosTotal();
		int getProvasDisputadas();
		int getDistanciaPercorrida();
		int getPulosDados();	

		friend istream& operator>> (istream &i, Sapo &_s);

		friend ostream& operator<< (ostream &o, const Sapo &_s);
};

#endif