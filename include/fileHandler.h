/**
* @file 	fileHandler.h
* @brief 	Responsável por manipular os arquivos CSV.
* @author	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	20/03/2018
* @date		16/06/2018
*/

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
using std::ifstream;

#include <string>


/** 
* @brief Acessa a linha do arquivo especificada no parametro line
* @param &file Contém o stream do arquivo
* @param *l Inteiro que representa a linha a ser acessada
* @return void
*/
void readCSVFile(ifstream &file, int line);

/** 
* @brief Coloca o cursor do stream no início do arquivo
* @param &file Contém o stream do arquivo
* @return void
*/
void resetStreamCursor(ifstream &file);

#endif