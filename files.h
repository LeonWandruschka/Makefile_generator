#ifndef FILES_H
#define FILES_H

// INCLUDES
#include "dataTypes.h"

// function
void writeToCsvFile(char *filepath, userdata_t *data);
void readFromFile(char *filepath, char *data, int lines);

#endif //FILES_H