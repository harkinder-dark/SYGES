#ifndef univ_h
#define univ_h

#include "../standard.h"

typedef struct univ univ_t;
typedef struct ulink ulink_t;

struct univ {
    char *id;
    char *name;
    char *address;
    char *country;
    time_t *since;
};

struct ulink {
    univ_t *school;
    struct ulink *next;
};

size_t univers_count(ulink_t **db);
void universityPrint(ulink_t *univs);
void univers_show(ulink_t **db, char *id);
bool univers_add(ulink_t **db, univ_t *univ);
bool univers_update(ulink_t **db, univ_t *modified, char *id);

#endif
