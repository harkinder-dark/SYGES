#ifndef active_h
#define active_h

#include "../unity/unit.h"
#include "../student/std.h"

typedef struct active ac_t;
typedef struct actlinked aclink_t;

struct active {
    char *id;
    uni_t *ue;
    std_t *std;
    bool select;
    bool valid;
};

struct actlinked {
    ac_t *active;
    struct actlinked *next;
};

#endif
