#ifndef study_h
#define study_h

#include "../department/depart.h"
#include "../tools/tools.h"



typedef struct std std_t;
typedef struct stdlink slink_t;
typedef struct stables stable_t;


struct std {
    char *id;
    char *first_name;
    char *last_name;
    time_t *birthday;
    char *nation;
    pers_t *emergency;
    ph_t *contact;
    char *diploma;
    dp_t *department;
    int grade;
};

struct stdlink {
    char *key;
    std_t *std;
    struct stdlink *next;
};

struct stables {
    slink_t *students;
    struct stables *next;
};


size_t study_count(stable_t **db, char *key);
void shortStudPrint(std_t *study);
void study_show(stable_t **db, char *key, char *id);
bool study_add(stable_t **db, char *key, std_t *study);
bool study_update(stable_t **db, char *key, std_t *modified, char *id);

#endif
