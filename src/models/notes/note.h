#ifndef notes_h
#define notes_h

#include "../active/active.h"

typedef struct notes no_t;
typedef struct nlinked nlink_t;

struct notes {
    char *id;
    ac_t *active;
    double *notes;
};

struct nlinked {
    no_t *notes;
    struct nlinked *next;
};


#endif
