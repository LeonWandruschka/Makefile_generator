#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Librarys
#include "dataTypes.h"
#include "files.h"
#include "str.h"

// set array to \0
void initUserdata(userdata_t *data)
{
    for (char i = 1; i < getStrLen(data->mFileName)-1; i++)
        data->mFileName[i] = '\0';
}

// Get data from user
void userQuery(userdata_t *data)
{
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
        appendToFile("temp",libName);
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


// Set path to work with specific files
bool_t setPath(char *path)
{
    char relativePathToFile[] = "file.data";    // Set relative path to file
    char pathToProject[] = "";                  // Set path to project
    
    // Link the two given Path
    linkStrToPath(path, pathToProject, relativePathToFile);
    if (getStrLen(relativePathToFile) + getStrLen(pathToProject) != getStrLen(path))
        return false;
    return true;
}

/*<-- MAIN -->*/
int main(int argc, char const *argv[])
{
    // Initialize Buffer for path to file
    char path[80] = {'\0'}; // Initialize string with \0

    // Variable for userdata(Own datatype in dataTypes.h)
    userdata_t userdata;

    // Buffer for String where current user data will be stored
    char userBuffer[255] = {'\0'};
    // To create --> Memory allocation

    // Initalize userdata with \0
    initUserdata(&userdata);

    // Create and check path
    setPath(path);

    // Get data from User
    userQuery(&userdata);

    // Write userdata to csv File
    // writeToFile(path, &userdata);

    // return 0
    return 0;
}
