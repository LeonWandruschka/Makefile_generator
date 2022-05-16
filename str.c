// Include own libraries
#include "str.h"

// Get string length
int getStrLen(char *string)
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
bool_t linkStrToPath(char *path, char *pathToProject, char *relativePathToFile)
{
    int lengthpathToProject = getStrLen(pathToProject);
    int lengthrelativePathToFile = getStrLen(relativePathToFile);
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

    if(getStrLen(path) != lengthpathToProject + lengthrelativePathToFile)
        return false;

    return true;
}

//Add a strinng to another one
bool_t appendToStr(char *existingString, char *stringToAdd)
{
    int existingStringlen = getStrLen(existingString);
    int stringToAddlen = getStrLen(stringToAdd);
    int index = 0;

    for (int i = existingStringlen; i < existingStringlen + stringToAddlen; i++)
    {
        existingString[i] =  stringToAdd[index];
        index++;
    }

    if (getStrLen(existingString) != existingStringlen + stringToAddlen)
        return false;   // There was an error adding to the existing string!
        
    return true;
}

// Compare first characteer of two strings
bool_t compareStr(char* const string1,char* const string2)
{
    int lenStr1 = getStrLen(string1);
    int lenStr2 = getStrLen(string2);

    if(lenStr1 == lenStr2)
    {
        if(string1[0] == string2[0])
        {
            return true;    
        }
    }
    return false;
}