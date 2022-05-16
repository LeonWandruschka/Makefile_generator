// Include std libraries
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Include own libraries
#include "dataTypes.h"
#include "files.h"
#include "str.h"
#include "createMakefile.h"

// set array to \0
void initUserdata(userdata_t *data)
{
    for (char i = 1; i < getStrLen(data->mFileName)-1; i++)
        data->mFileName[i] = '\0';
}

// Get data from user
void userQuery(char *tempfileName, userdata_t *data)
{
    // Buffer for userinputs
    char libName[50];
    char creationCheck[3];

    // Get the name for the executable from the user
    printf("Executeable name: ");
    scanf(" %s", data->mFileName);

    // Get number of libraries which should be linked
    printf("Enter number of libraries that have to be linked: ");
    scanf(" %d", &data->numLibs);

    // Get the names, from the number of libraries that should be linked
    for (char i = 0; i < data->numLibs; i++)
    {
        printf("Enter library name from %d. library: ",i+1);
        scanf(" %s", libName);
        appendToFile(tempfileName,libName);
        appendToFile(tempfileName, "\n");
    }
    
    // Check if a clean function should be created
    while(1)
    {
        printf("Should a CLEAN function be created?(y/n): ");
        scanf(" %c", creationCheck);
        if(compareStr(creationCheck,"y"))
        {
            data->createClean = 1;
            break;
        }
        else if (compareStr(creationCheck,"n"))
        {
            data->createClean = 0;
            break;
        }
    }
    creationCheck[0] = '\0';
   
   // Check if a rebuild function should be created 
    while(1)
    {
        printf("Should a REBUILD function be created?(y/n): ");
        scanf(" %s",creationCheck);
        if(compareStr(creationCheck,"y"))
        {
            data->createRebuild = 1;
            break;
        }
        else if (compareStr(creationCheck,"n"))
        {
            data->createRebuild = 0;
            break;
        }
    }
}

/*<-- MAIN -->*/
int main(int argc, char const *argv[])
{
    // Name for temporary filee
    char tempfileName[] = "tmp";

    // Makefile name
    char *makePath = "Makefile";

    // Initialize Buffer for path to file
    char path[80] = {'\0'}; // Initialize string with \0

    // Variable for userdata(Own datatype in dataTypes.h)
    userdata_t userdata;

    // Initalize userdata with \0
    initUserdata(&userdata);

    // Get data from User
    userQuery(tempfileName, &userdata);

    // Create/write to Makefile
    writeMakefile(tempfileName, makePath, &userdata);

    // Remove temorary file
    remove(tempfileName);
    
    // return 0
    return 0;
}
