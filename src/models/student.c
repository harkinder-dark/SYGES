/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "student.h"

/**
 * stdAllView - show All student
 * @head: std_t array, end with null
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
 * @pk: primary key for student
 * @head: std_t array, end with null
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

/**
 * stdAdd - fonction d'ajout
 * @entry: etudiant a ajouter
 * @head: liste des etudient deja ajouter
*/
void stdAdd(std_t *entry, std_t **head)
{
    /**
     * les entrees viendront d'un espace graphique
    */
    if (stdFind(entry, head) == NULL)
    {
        entry->_pk = stdkeyGenerator(entry);
        // save(entry)
        printf("ENTRY SUCCESSFULL !!!");
    }else {
        printf("ENRTY EXISTS !!!");
    }
}

/**
 * stdUpdate - fonction de mis a jour
 * @pk: cle primary de l'etudiant a modifier
 * @modify: la nouvelle entree
 * @head: liste des etudiant
*/
void stdUpdate(char *pk, std_t modify, std_t **head)
{
    int i;
    for (i = 0; (*head) = (*head) + i, (*head) != NULL; i++)
    {
        if (modify.contact == (*head)->contact  && strcmp((*head)->_pk, pk) != 0)
        {
            printf("MODIFICATION FAIL !!!");
            return;
        }

        if (strcmp((*head)->_pk, pk) == 0)
        {
            (*head)->first_name = strdup(modify.first_name);
            (*head)->last_name = strdup(modify.last_name);
            (*head)->birthday = strdup(modify.birthday);
            (*head)->contact->indic = strdup(modify.contact->indic); 
            (*head)->contact->number = modify.contact->number;
            (*head)->emergency->fullname = strdup(modify.emergency->fullname); 
            (*head)->emergency->contact->indic = strdup(modify.emergency->contact->indic);
            (*head)->emergency->contact->number = modify.emergency->contact->number;
            (*head)->last_diploma = strdup(modify.last_diploma);
            (*head)->nationality = strdp(modify.nationality);
            // save(entry)
            printf("MODIFICATION SUCESSFULL !!!");
        }
    }
}

/**
 * stdRemove - suppression d'etudiant
 * @pk: cle primaire
 * @head: liste d'etudiant
*/
void stdRemove(char *pk, std_t **head)
{
    int i, j;
    for (i = 0; (*head) = (*head) + i, (*head) != NULL; i++)
    {
        if (strcmp((*head)->_pk, pk) == 0)
        {
            for (j = i; (*head) = (*head) + j, (*head) + 1 != NULL; j++)
                (*head) = (*head) + 1;
            (*head) = NULL;

            printf("STUDENT %s REMOVE SUCCESS !!!", pk);
            return;
        }
    }
    printf("NO STUDENT !!!");
}
