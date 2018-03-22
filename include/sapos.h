#ifndef SAPOS_H
#define SAPOS_H

class Sapos {
	private:	
		short int id;
		int distanciaPercorrida;
		int pulosDados;

	public:
		static int distanciaCorrida;

		Sapos();
		Sapos(short int id);
		~Sapos();

		void setId(short int id);

		int getId();
		int getDistanciaPercorrida();
		int getPulosDados();

		void pular();
	
};

#endif