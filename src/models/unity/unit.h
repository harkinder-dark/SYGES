#ifndef unit_h
#define unit_h

#include "../student/std.h"

typedef struct unity ue_t;
typedef struct unit elink_t;
typedef struct etab etable_t;

struct unity {
    char *id;
    char *code;
    dp_t *dp;
    int grade;
    char weight;
};

struct unit {
    char *key;
    ue_t *unit;
    struct unit *next;
};

struct etab {
    elink_t *unity;
    struct etab *next;
};


#endif
