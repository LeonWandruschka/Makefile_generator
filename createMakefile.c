// Include std libraries
#include <stdio.h>
#include <stdlib.h>

// Include own libraries
#include "files.h"
#include "dataTypes.h"
#include "str.h"

// Create/write to Makefile
void writeMakefile(char *tempfileName, char *makePath, userdata_t *data)
{
    // Cheeck value for onetime use function
    bool_t check = true;

    // Buffer for fieldata
    char buf[50];

    // Short description
    writeToFile(makePath, "#This file was automatically created!\n#For more information go to: https://github.com/LeonWandruschka/Makefile_generator \n \n");

    //<-- MAKEFILE -->//
    appendToFile(makePath, "build: ");
    for (char i = 0; i < 2; i++)
    {
        for (int i = 0; i < data->numLibs; i++)
        {
            readLineFromFile(tempfileName,buf,i+1);
            appendToFile(makePath, buf);
            appendToFile(makePath, ".o ");
        }
        if (check)
        {
            appendToFile(makePath, "\n\tgcc main.c ");
            check = false;
        }
    }
    appendToFile(makePath,"-o ");
    appendToFile(makePath, data->mFileName);
    appendToFile(makePath, "\n\n");
    for (int i = 0; i < data->numLibs; i++)
    {
        readLineFromFile(tempfileName, buf,i+1);
        appendToFile(makePath, buf);
        appendToFile(makePath, ".o:\n\tgcc ");
        appendToFile(makePath, buf);
        appendToFile(makePath, ".c -c\n\n");
    }
    if (data->createClean == true)
    {
        appendToFile(makePath, "clean:\n\trm ");
        appendToFile(makePath, data->mFileName);
        appendToFile(makePath, "\n");
        for (int i = 0; i < data->numLibs; i++)
        {
            readLineFromFile(tempfileName, buf,i+1);
            appendToFile(makePath, "\trm ");
            appendToFile(makePath, buf);
            appendToFile(makePath, ".o\n");
        }   
        appendToFile(makePath, "\n");
    }
    if (data->createRebuild == true)
    {
        appendToFile(makePath, "rebuild: clean build");
    }
}