/**
 * File             : student.h
 * Directory        : src/models/student.h
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "const.h"

typedef struct tm date_t;

/**
 * struct contact
 * @indic: indicatif
 * @number: number without indic
*/
struct contact
{
    char *indic;
    long number;
};

typedef struct contact phone_t;

/**
 * struct person
 * @fullname: nom complet
 * @contact: phone
*/
struct person
{
    char *fullname;
    phone_t *contact;
};

typedef struct person pers_t;

/**
 * struct student
 * @_pk: primary key
 * @first_name: first name of student
 * @last_name: last name of student
 * @birthday: birthday of student
 * @nationality: country origin of stuydent
 * @contact: phone numbers
 * @last_diploma: last academy diploma
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


typedef struct student std_t;

/**
 * struct stdlinked
 * @data: les données
 * @next: la donnée suivante
*/
typedef struct stdlinked
{
    std_t * data;
    struct stdlinked *next;
} stdlink;



void stdAllView(stdlink **head);
void stdSingleView(char *pk, stdlink **head);
bool stdAdd(std_t *entry, stdlink **head);
bool stdUpdate(char *pk, std_t *modify, stdlink **head);
bool stdRemove(char *pk, stdlink **head);


std_t *stdFind(std_t *entry, stdlink **head);



char *_realloc(char *ptr, size_t size);
char *stdkeyGenerator(std_t *entry);
char *ascii_transform(char *str);
char *toString(long long n);
size_t digits(long long n);
char letter_ascii(int c);
int dizaine(long long n);

#endif
