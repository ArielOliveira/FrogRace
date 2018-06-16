/**
* @file 	fileHandler.cpp
* @brief 	Responsável por manipular os arquivos CSV.
* @brief	Contém a implementaçao das funçoes.
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		16/06/2018
*/

#include "fileHandler.h"

void readCSVFile(ifstream &file, int line) {
	std::string dummy;
	for (int i = 0; i < line; i++) {
		getline(file, dummy, '\n');
	}
	getline(file, dummy, ';');
}

void resetStreamCursor(ifstream &file) {
	file.clear();
	file.seekg(0, file.beg);
}