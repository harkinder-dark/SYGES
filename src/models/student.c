/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "student.h"

/**
 * stdAllView - show All student
 * head : std_t array, end with null
*/
void stdAllView(std_t **head)
{
    /**
     * en supposant que head est un tableau de std_t dont l'elment final est null
     * ex: head = {..., ..., NULL}
    */
    int i;
    if (head == NULL || (*head) == NULL)
        return;

    for (i = 0; (*head) = (*head) + i, (*head) != NULL; i++)
    {
        printf("\nFirst Name    : %s\n", (*head)->first_name);
        printf("Last Name       : %s\n", (*head)->last_name);
        printf("Birthday        : %s\n", (*head)->birthday);
        printf("Nationality     : %s\n", (*head)->nationality);
        printf("Emergency       : %s\n", (*head)->emergency);
        printf("Contact         : %s %ld\n", (*head)->contact->indic, (*head)->contact->number);
        printf("Last Diploma    : %s\n\n", (*head)->last_diploma);
    }
}

/**
 * stdSingleView - show specific student
 * pk : primary key for student
 * head : std_t array, end with null
*/
void stdSingleView(char *pk, std_t **head)
{
    int i, res = 0;
    if (pk == NULL)
        return;
    for (i = 0; (*head) = (*head) + i, (*head) != NULL; i++)
    {
        if ((*head)->_pk == pk)
        {
            res = 1;
            printf("\nFirst Name    : %s\n", (*head)->first_name);
            printf("Last Name       : %s\n", (*head)->last_name);
            printf("Birthday        : %s\n", (*head)->birthday);
            printf("Nationality     : %s\n", (*head)->nationality);
            printf("Emergency       : %s\n", (*head)->emergency);
            printf("Contact         : %s %ld\n", (*head)->contact->indic, (*head)->contact->number);
            printf("Last Diploma    : %s\n\n", (*head)->last_diploma);

            break;
        }
    }
    if (res == 0)
        printf("NO STUDENT !!!");
}


void stdAdd(std_t *entry, std_t **head)
{
    /**
     * les entrees viendront d'un espace graphique
    */
    if (stdFind(entry) == NULL)
    {
        entry->_pk = keyGenerator();


    }else {
        printf("ENRTY EXISTS !!!");
    }
        
}

char *keyGenerator()
{
    
}