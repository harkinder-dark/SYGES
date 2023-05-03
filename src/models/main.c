/**
 * File		: university.h
 * Author		: Tountoun Abel AYANOU
 * Created at	: April 24 2023
 * Last update	: Mai 3 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "syges.h"


int main(void)
{

     /* Create a university */
     university_t *created;
     country_t country;
     char *name;
     addr_t *addresse;
     struct tm date;
     linked_university_t *head;

     name = "University of Lome";
     country = 2;
     addresse = (addr_t *)malloc(sizeof(addr_t));
     addresse->country = &country;
     addresse->road = "Bd de l'Aero";
     addresse->city = "Lome";
     date.tm_mday = 20;
     date.tm_year = 120;
     date.tm_mon = 3;

     created = createUniversity(name, addresse, &country, date);
     /*if (created != NULL) {
          printf("University created successfully\n");
          printf("Name: %s\n", created->name);
          printf("Country %s\n", countries[*(created->country)]);
          printf("Creation date: %s\n", asctime(&(created->since)));
     }*/
     head = NULL;
     addUniverisity(created, &head);

     name = "University of Abomey";
     country = 4;
     addresse = (addr_t *)malloc(sizeof(addr_t));
     addresse->country = &country;
     addresse->road = "Bd de l'Independance";
     addresse->city = "Cotonou";
     date.tm_mday = 12;
     date.tm_year = 110;
     date.tm_mon = 7;

     created = createUniversity(name, addresse, &country, date);
     addUniverisity(created, &head);

     created->name = "University of Lyon";
     updateUniversity(created);

     viewAllUniversities(&head);
     char *key;
     key = generateID(created->name, created->country);

     deleteUniversity(key, &head);
     printf("------------------ After deletion ---------------------\n\n");
     viewAllUniversities(&head);

     return (0);
}