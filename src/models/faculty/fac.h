#ifndef fac_h
#define fac_h

#include "../university/univ.h"

typedef struct fac fac_t;
typedef struct fahashlink flink_t;
typedef struct factables ftable_t;


struct fac {
    char *id;
    univ_t *univ;
    char *name;
    char *domain;
};

struct fahashlink
{
    char *key;
    fac_t *faculty;
    struct fahashlink *next;
};

struct factables {
    flink_t *faculties;
    struct factables *next;
};


size_t faculty_count(ftable_t **head, char *key);
void shortPrintFac(fac_t *fac);
void faculty_show(ftable_t **head, char *key, char *id);
bool faculty_add(ftable_t **head, char *key, fac_t *fac);
bool faculty_update(ftable_t **db, char *key, fac_t *modified, char *id);

#endif
