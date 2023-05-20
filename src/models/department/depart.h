#ifndef depart_h
#define depart_h

#include "../faculty/fac.h"

typedef struct dep dp_t;
typedef struct dlink dlink_t;
typedef struct dptable dptable_t;

struct dep {
    char *id;
    char *name;
    fac_t *fac;
    char *speciality;
};

struct dlink {
    char *key;
    dp_t *depart;
    struct dlink *next;
};

struct dptable {
    dlink_t *departments;
    struct dptable *next;
};

size_t dp_count(dptable_t **db, char *key);
void dp_show(dptable_t **db, char *key, char *id);
bool dp_add(dptable_t **db, char *key, dp_t *dp);
bool dp_update(dptable_t **db, char *key, dp_t *modified,char *id);

#endif
