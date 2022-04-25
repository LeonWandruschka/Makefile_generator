#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Librarys
#include "dataTypes.h"
#include "files.h"
#include "str.h"


void initUserdata(userdata_t *data)
{
    for (char i = 1; i < getStrLen(data->name)-1; i++)
        data->name[i] = '\0';
    for (char i = 0; i < getStrLen(data->age)-1; i++)
        data->age[i] = '\0';
    for (char i = 0; i < getStrLen(data->birthday)-1; i++)
        data->birthday[i] = '\0';
    for (char i = 0; i < getStrLen(data->birthmonth)-1; i++)
        data->birthmonth[i] = '\0';
    for (char i = 0; i < getStrLen(data->birthyear)-1; i++)
        data->birthyear[i] = '\0';

}

// User query for datainput
void userQuery(userdata_t *data)
{
    printf("Please enter your Name: ");
    scanf("%s",data->name);
    printf("Please enter your age: ");
    scanf("%s, ",data->age);
    printf("Please enter the Day you are born(1-31): ");
    scanf("%s, ",data->birthday);
    printf("Please enter the Month you are born(1-12): ");
    scanf("%s, ",data->birthmonth);
    printf("Please enter the Month you are born(1920-2022): ");
    scanf("%s",data->birthyear);
}

// Set path to work with specific files
bool_t setPath(char *path)
{
    char relativePathToFile[] = "PFAD";             // Set relative path to file
    char pathToProject[] = "PFAD";                  // Set path to project
    // Link the two give Path to each other
    linkStrToPath(path, pathToProject, relativePathToFile);
    if (getStrLen(relativePathToFile) + getStrLen(pathToProject) != getStrLen(path))
        return false;
    return true;
}

/*<-- MAIN -->*/
int main(int argc, char const *argv[])
{
    char path[80] = {'\0'}; // Initialize string with \0

    userdata_t userdaten;

    char userBuffer[255] = {'\0'};

    initUserdata(&userdaten);


    // Create and check path
    setPath(path);

    // Get data from User
    userQuery(&userdaten);

    // Write userdata to csv File
    writeToCsvFile(path, &userdaten);

    // return 0
    return 0;
}
