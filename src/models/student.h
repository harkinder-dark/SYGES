/**
 * File : student.h
 * Directory : src/models/student.h
 * collaborators : ...
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct contact
{
    char * indic;
    long long number;
}

struct person
{
    char *fullname;
    phone_t *contact;
}


/**
 * struct student
 * _pk              : primary key
 * first_name       : first name of student
 * last_name        : last name of student
 * birthday         : birthday of student
 * nationality      : country origin of stuydent
 * contact          : phone numbers
 * last diploma     : last academy diploma
*/
struct student
{
    char *_pk;
    char *first_name;
    char *last_name;
    date_t *birthday;
    char *nationality;
    pers_t *emergency;
    phone_t *contact;
    char *last_diploma;
};

typedef struct person pers_t;
typedef struct tm date_t;
typedef struct contact phone_t;

#endif
