
#include "files.h"


// FUNCTIONS
void writeToCsvFile(char *filepath, userdata_t *data)
{
    FILE *fp;
    fp = fopen(filepath, "a");
    // fputs(data,fp);
    fprintf(fp,"%s, %s, %s, %s, %s\n",data->name,data->age,data->birthday,data->birthmonth,data->birthyear);
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