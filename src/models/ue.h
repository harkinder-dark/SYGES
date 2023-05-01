/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#ifndef UE_H
#define UE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "const.h"

/**
 * struct ue - models ue
 * @level: niveau LMD
 * @name: code de l'ue
 * @weight: coefficient
*/
struct ue {
    char *__pk;
    char *level;
    char *name;
    int weight;
};

typedef struct ue ue_t;

struct uelinked
{
    ue_t *data;
    struct uelinked *next;
};

typedef struct uelinked uelink;

#endif
