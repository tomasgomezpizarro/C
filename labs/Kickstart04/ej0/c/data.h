#ifndef _DATA_H_
#define _DATA_H_

#define NAME_MAXSIZE 30

typedef char name_t [NAME_MAXSIZE];

typedef struct _s_data {
    unsigned int age;
    unsigned int height;
    name_t name;
    char nada[2];
} data_t;


#endif

