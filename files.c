// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// EXTERN INCLUDES
#include "files.h"

// FUNCTIONS
void writeToFile(char *filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath, "a");
    fputs(data,fp);
    fclose(fp);
}

// MAX data LENGTH --> 255 (CHAR ARRAY) 
void readFromFile(char *filepath, char *data, int lines)
{
    FILE *fp;
    fp = fopen(filepath,"r");
    fgets(data,lines,fp);
    fclose(fp);
}