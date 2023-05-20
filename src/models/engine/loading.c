#include "loading.h"

ulink_t **university;

char *__class__ = {
    "University",
    "Faculty",
    "Department",
    "Student",
    NULL
};

size_t (*count[])(char*) = {
    univers_count,
    faculty_count,
    dp_count,
    sd_count,
};

void (*show[])(void**, char*) = {
    univers_show,
    faculty_show,
    dp_show,
    sd_show,
};

bool (*add[])(void**, void*) = {
    univers_add,
    faculty_add,
    dp_add,
    sd_add,
};

bool (*update[])(void**, void*, char*) = {
    univers_update,
    faculty_update,
    dp_update,
    sd_update,
};
