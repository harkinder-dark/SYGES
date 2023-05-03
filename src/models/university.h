/**
 * File		: university.h
 * Author		: Tountoun Abel AYANOU
 * Created at	: April 24 2023
 * Last update	: Mai 3 2023
 */

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct university_s university_t;
typedef struct addr_s addr_t;

/**
 * enum country_e - representation of some countries
 */
typedef enum country_e {
	TOGO,
	BENIN,
	GHANA,
	IVORY_COAST,
	SENEGAL,
	NIGERIA,
	ETHIOPIA,
	KENYA,
	UGANDA,
	MOROCCO,
	ANGOLA,
	NIGER,
	MALI,
	BURKINA_FASO,
	CAMEROON,
	LIBERIA,
	CONGO
} country_t;

/**
 * struct addr_s - representation of an address
 * 
 * @country: pointer a country name
 * @city: pointer to a city in that country
 * @road: pointer to the road where to find the address
 */
struct addr_s {
	country_t *country;
	char *city;
	char *road;
};

/**
 * struct university_s - representation of a university
 *
 * @name: pointer to the name of the university
 * @addr: pointer to the address of the university
 * @country: pointer to the country where the university is located
 * @since: the date of creation of the university
 */
struct university_s {
	char *id;
	char *name;
	struct addr_s *addr;
	country_t *country;
	struct tm since;
};

/**
 * struct linked_university_s - representation of a linked list of universities
 * 
 * @univ: a pointer to a university in the linked list
 * @next: a pointer to the next node in the linked list
 */
typedef struct linked_university_s {
	university_t *univ;
	struct linked_university_s *next;
} linked_university_t;

/* Core functions declarations */

university_t *createUniversity(char *name, addr_t *addresse, country_t *country, struct tm creation_date);
int addUniverisity(university_t *univ, linked_university_t **head);
int updateUniversity(university_t *univ);
int deleteUniversity(char *univ_id, linked_university_t **head);
void viewAllUniversities(linked_university_t **head);
void viewUniversity(char *key, linked_university_t **head);

/* Additional functions declarations */

size_t size(linked_university_t **head);
int len(const char *str);
char *generateID(char *name, country_t *country);
university_t *getUniversity(char *key, linked_university_t **head);


#endif