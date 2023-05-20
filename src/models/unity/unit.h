#ifndef unit_h
#define unit_h

#include "standard.h"

typedef struct unity uni_t;
typedef struct unit unilink_t;

struct unity {
    char *id;
    char *level;
    char *code;
    char weight;
};

struct unit {
    uni_t *unit;
    struct unit *next;
};

size_t unicount(unilink_t **head);
void unishow(unilink_t **head, char *id);
bool unadd(unilink_t **head, uni_t *ue);
bool unipdate(unilink_t **head, uni_t *modified, char *id);
bool unidel(unilink_t **head, char *id);
bool uniremove(unilink_t **head, char **ids, bool *func(unilink_t **head, char *id));

#endif
