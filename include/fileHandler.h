#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
using std::ifstream;

#include <string>

void readCSVFile(ifstream &file, int line);

void resetStreamCursor(ifstream &file);

#endif