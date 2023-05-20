#ifndef tools_h
#define tools_h

#include <string.h>
#include "../standard.h"

typedef struct person pers_t;
typedef struct plinked plink_t;

typedef struct phone ph_t;

typedef long long numeric;



struct person {
    char *id;
    char *full_name;
    ph_t *phone;
};

struct plinked {
    pers_t *person;
    struct plinked *next;
};

struct phone {
    char *indic;
    numeric number;
};

bool createPerson(plink_t **head, char *fullName, ph_t *phone);
bool personSave(plink_t **head, pers_t *person);
char *litteralPerson(pers_t *person, char *phone);
ph_t *phoned(char *indic, numeric number);
char *litteralPhone(ph_t *phone);

#endif
