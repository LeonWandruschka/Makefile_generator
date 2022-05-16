#ifndef STR_H
#define STR_H

#include "dataTypes.h"


int getStrLen(char *string);
bool_t linkStrToPath(char *path, char *pathToProject, char *relativePathToFile);
bool_t appendToStr(char *existingString, char *stringToAdd);
bool_t compareStr(char* const string1, char* const string2);


#endif //STR_H
