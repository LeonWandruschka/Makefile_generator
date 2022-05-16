#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "files.h"


// Write to file
void writeToFile(char *filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath, "w");
    fprintf(fp,"%s\n",data);
    fclose(fp);
}

// Append to file
void appendToFile(const char * const filepath, char *data)
{
    FILE *fp;
    fp = fopen(filepath, "a");
    fprintf(fp,"%s\n", data);
    fclose(fp);
}

// Read line from file
void readFromFile(char *filepath, char *data, int lines)
{
    FILE *fp;
    fp = fopen(filepath,"r");
    fscanf(fp,"%s",data);
    fclose(fp);
}
