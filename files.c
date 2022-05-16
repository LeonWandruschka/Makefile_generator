// Include std libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Include own libraries
#include "files.h"
#include "str.h"

// Write to file
void writeToFile(char *filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath, "w");
    fprintf(fp,"%s",data);
    fclose(fp);
}

// Append to file
void appendToFile(const char * const filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath, "a");
    fprintf(fp,"%s", data);
    fclose(fp);
}

// Read line from file
void readFromFile(char *filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath,"r");
    fgets(data,50,fp);
    fclose(fp);
}

// Read specific line from file
void readLineFromFile(char *filepath, char *data, int line)
{
    FILE *fp;
    fp = fopen(filepath,"r");
    for (int i = 0; i < line; i++)
    {
        fgets(data,50,fp);
    }
    data[getStrLen(data)-1] = '\0';
    fclose(fp);
}