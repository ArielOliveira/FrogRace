/**
* @file 	sapo.h
* @brief 	Cabeçalho contendo a definição da classe sapo
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		16/06/2018
*/

#ifndef SAPOS_H
#define SAPOS_H

#include <random>

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

static const char *diretorioSapos = "./data/sapos.csv";

//!  Classe que representa um Sapo. 
/*!
  Uma classe com todos os devidos atributos e membros necessários
  para representar um Sapo na corrida.
*/
class Sapo {
	private:
		bool preloaded; /*!< bool Indica se a classe já foi construída. */ 

		string nome; /*!< string Guarda o nome do Sapo. */ 

		short int id; /*!< string Guarda o ID do Sapo. */ 

		int vitorias; /*!< int Guarda o número de vitórias. */ 
		int empates; /*!< int Guarda o número de empates. */ 
		int pulosDadosTotal; /*!< int Guarda o total de pulos. */ 
		int provasDisputadas; /*!< int Guarda o total de provas disputadas. */ 
		int distanciaPercorrida; /*!< int Guarda distância percorrida durante a corrida. */ 
		int pulosDados; /*!< int Guarda os pulos dados durante a corrida. */ 

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		static int distanciaCorrida; /*!< static int Variável estática contendo o tamanho da corrida. */ 

		Sapo(string nome, short int id, int vitorias, int empates, int pulosDadosTotal, int provasDisputadas);
		Sapo(int line);
		Sapo();
		~Sapo();

		int pular();

		void setNome(string nome);
		string getNome();

		void setId(short int id);
		int getId();

		void incrementarVitoria();
		void incrementarProvasDisputadas();

		int getVitorias();
		int getEmpates();
		int getPulosDadosTotal();
		int getProvasDisputadas();
		int getDistanciaPercorrida();
		int getPulosDados();	

		friend istream& operator>> (istream &i, Sapo &_s);

		friend ostream& operator<< (ostream &o, const Sapo &_s);

		friend ofstream& operator<< (ofstream &of, const Sapo &_s);
};

#endif