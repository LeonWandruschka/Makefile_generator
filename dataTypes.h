#ifndef DATATYPES_H
#define DATATYPES_H

enum
{
    FAILURE_char = '0',
    SUCCESS_char = '1'
};

enum
{
    FAILURE = 0,
    SUCCESS = 1
};

typedef enum
{
    false = 0,
    true = 1
}bool_t;

typedef struct
{
    char name[50];
    char age[120];
    char birthday[3];
    char birthmonth[10];
    char birthyear[4];
}userdata_t;

#endif //DATATYPES_H