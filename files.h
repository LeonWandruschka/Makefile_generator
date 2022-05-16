#ifndef FILES_H
#define FILES_H

// INCLUDES
#include "dataTypes.h"

// function
void writeToFile(char *filepath, char *data);
void appendToFile(const char * const filepath, char *data);
void readFromFile(char *filepath, char *data, int lines);

#endif //FILES_H