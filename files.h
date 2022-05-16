#ifndef FILES_H
#define FILES_H

// INCLUDES
#include "dataTypes.h"

// FUNCTION
void writeToFile(char *filepath, char *data);
void appendToFile(const char * const filepath, char *data);
void readFromFile(char *filepath, char *data);
void readLineFromFile(char *filepath, char *data, int line);

#endif //FILES_H