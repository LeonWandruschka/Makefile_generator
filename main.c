#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Librarys
#include "dataTypes.h"
#include "files.h"
#include "str.h"

typedef struct
{
    char name[50];
    char age[120];
    char birthday[2];
    char birthmonth[10];
    char birthyear[4];
}userdata_t;

void initUserdata(userdata_t *data)
{
    for (char i = 1; i < getStrLength(data->name)-1; i++)
        data->name[i] = '\0';
    for (char i = 0; i < getStrLength(data->age)-1; i++)
        data->age[i] = '\0';
    for (char i = 0; i < getStrLength(data->birthday)-1; i++)
        data->birthday[i] = '\0';
    for (char i = 0; i < getStrLength(data->birthmonth)-1; i++)
        data->birthmonth[i] = '\0';
    for (char i = 0; i < getStrLength(data->birthyear)-1; i++)
        data->birthyear[i] = '\0';

}

// User query for datainput
void userQuery(userdata_t *data)
{
    printf("Please enter your Name: ");
    scanf("%s",data->name);
    // printf("Please enter your age: ");
    // scanf("%s, ",data->age);
    // printf("Please enter the Day you are born(1-31): ");
    // scanf("%s, ",data->birthday);
    // printf("Please enter the Month you are born(1-12): ");
    // scanf("%s, ",data->birthmonth);
    // printf("Please enter the Month you are born(1920-2022): ");
    // scanf("%s",data->birthyear);
}

void linkUserdata(char *filedata, userdata_t *data)
{   
    linkStr(filedata,data->name);
    linkStr(filedata,data->age);
    linkStr(filedata,data->birthday);
    linkStr(filedata,data->birthmonth);
    linkStr(filedata,data->birthyear);
    linkStr(filedata,"\n");
}

// Set path to work with specific files
void setPath(char *path)
{

    char relativePathToFile[] = "Pfad";             // Set relative path to file
    char pathToProject[] = "PFAD"; // Set path to project

    // conect the two strings with each other..
    linkStrToPath(path, pathToProject, relativePathToFile);

    if (getStrLength(relativePathToFile) + getStrLength(pathToProject) < getStrLength(path))
    {
        printf("%c\n", FAILURE_char);
    }

    printf("%c\n", SUCCESS_char);
    printf("%d\n", getStrLength(path));
}

/*<-- MAIN -->*/
int main(int argc, char const *argv[])
{
    // char path[80] = {'\0'}; // Initialize string with \0

    userdata_t userdaten;

    char filedata[255] = {'\0'};

    initUserdata(&userdaten);


    // Create and check path
    // setPath(path);

    // printf("%s\n",path);

    userQuery(&userdaten);

    printf("%d\n",getStrLength(userdaten.name));


    // createData(filedata, &userdaten);

    // linkStr(filedata,userdaten.name);

    // printf("Length of linked String:\n");
    // printf("%d\n",getStrLength(filedata));
    // printf("%s\n",filedata);


    linkStr1(filedata,userdaten.name);

    printf("Length of linked String(function2):\n");
    printf("%d\n",getStrLength(filedata));
    printf("%s\n",filedata);

    // writeToFile(path,filedata);



    /*<-- Check Password and Username and Work with it -->*/

    // char username[20];
    // char password[50];

    // printf("%c\n", checkPath);
    // printf("%s\n",path);

    // printf("Please enter username: ");
    // scanf("%s", username);

    // printf("Please enter password: ");
    // scanf("%s", password);

    // printf("End of programm\n");

    return 0;
}



// OUTPUT

/*
/Users/leonwandruschka/Developer/C/Files/userdata.dat
Please enter your Name: Leon
4
FILE:
6
Leon�
*/

/*Please enter your Name: Leon
4
Length of linked String:
4
Leon
*/
