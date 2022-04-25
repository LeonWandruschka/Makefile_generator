#ifndef STR_H
#define STR_H

#include <stdio.h>

#include "dataTypes.h"


int getStrLen(char *string);
bool_t linkStrToPath(char *path, char *pathToProject, char *relativePathToFile);
bool_t addToStr(char *existingString, char *stringToAdd);



#endif //STR_H
