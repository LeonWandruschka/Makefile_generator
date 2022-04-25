#ifndef FILES_H
#define FILES_H

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "dataTypes.h"

// function
void writeToCsvFile(char *filepath, userdata_t *data);
void readFromFile(char *filepath, char *data, int lines);

#endif //FILES_H