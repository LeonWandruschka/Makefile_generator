#include <stdio.h>

#include "str.h"


int getStrLength(char *string)
{
    char checked = 0;
    int length = 0;
    while(!checked)
    {
        if(string[length] == '\0')
            break;
        length++;
    }
    return length;
}

// Link the Filepath to the Projectpath
void linkStrToPath(char *path, char *pathToProject, char *relativePathToFile)
{
    int lengthpathToProject = getStrLength(pathToProject);
    int lengthrelativePathToFile = getStrLength(relativePathToFile);
    int index = 0;

    for (int i = 0; i < lengthpathToProject; i++)
    {
        path[i] = pathToProject[i];
    }

    for (int j = lengthpathToProject; j < lengthpathToProject+lengthrelativePathToFile; j++)
    {
        path[j] =  relativePathToFile[index];
        index++;
    }
}

//Link two strings
void linkStr(char *stringOne, char *stringTwo)
{
    int index = 0;

    for (int i = getStrLength(stringOne); i < getStrLength(stringOne) + getStrLength(stringTwo); i++)
    {
        stringOne[i] =  stringTwo[index];
        index++;
    }
}

//Link two strings
void linkStr1(char *stringOne, char *stringTwo)
{
    int lengthStrOne = getStrLength(stringOne);
    int lengthStrTwo = getStrLength(stringTwo);
    int index = 0;

    for (int i = lengthStrOne; i < lengthStrOne + lengthStrTwo; i++)
    {
        stringOne[i] =  stringTwo[index];
        index++;
    }
}