#ifndef DATATYPES_H
#define DATATYPES_H

typedef enum
{
    false = 0,
    true = 1
}bool_t;

typedef struct
{
    char mFileName[50];
    int numLibs;
    int createClean;    //YES/NO
    int createRebuild;  //YES/NO
}userdata_t;

#endif //DATATYPES_H