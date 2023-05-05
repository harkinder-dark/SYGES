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
void stdAllView(stdlink **head)
{
    int i;
    if (head == NULL || (*head) == NULL)
        return;

    for (i = 0; (*head)->next != NULL; i++)
    {
        printf("\nFirst Name    : %s\n", (*head)->data->first_name);
        printf("Last Name       : %s\n", (*head)->data->last_name);
        printf("Birthday        : %s\n", (*head)->data->birthday); // affichage en utilisant strftime
        printf("Nationality     : %s\n", (*head)->data->nationality);
        printf("Emergency       : %s\n", (*head)->data->emergency);
        printf("Contact         : %s %ld\n", (*head)->data->contact->indic, (*head)->data->contact->number);
        printf("Last Diploma    : %s\n\n", (*head)->data->last_diploma);

        (*head) = (*head)->next;
    }
}

/**
 * stdSingleView - show specific student
 * @pk: primary key for student
 * @head: std_t array, end with null
*/
void stdSingleView(char *pk, stdlink **head)
{
    int i, res = 0;
    if (pk == NULL)
        return;
    
    for (i = 0; (*head)->data != NULL; i++)
    {
        if (strcmp((*head)->data->_pk, pk) == 0)
        {
            res = 1;
            printf("\nFirst Name    : %s\n", (*head)->data->first_name);
            printf("Last Name       : %s\n", (*head)->data->last_name);
            printf("Birthday        : %s\n", (*head)->data->birthday);
            printf("Nationality     : %s\n", (*head)->data->nationality);
            printf("Emergency       : %s\n", (*head)->data->emergency);
            printf("Contact         : %s %ld\n", (*head)->data->contact->indic, (*head)->data->contact->number);
            printf("Last Diploma    : %s\n\n", (*head)->data->last_diploma);

            return;
        }

        (*head) = (*head)->next;
    }

    if (res == 0)
        printf("NO STUDENT !!!");
}

/**
 * stdAdd - fonction d'ajout
 * @entry: etudiant a ajouter
 * @head: liste des etudient deja ajouter
 * Return: true or false
*/
bool stdAdd(std_t *entry, stdlink **head)
{
    stdlink *new;

    if (entry == NULL)
    {
        printf("YOUR NEW ENTRY IS NULL !!!");
        return false;
    }

    if (stdFind(entry, head) != NULL)
    {
        printf("ENRTY EXISTS !!!");
        return false;
    }

    entry->_pk = stdkeyGenerator(entry);
    new = malloc(sizeof(stdlink));
    if (new == NULL)
        return false;
    new->data = entry;

    if (head == NULL || *head == NULL)
        new->next = NULL;
    else
        new->next = *head;
    
    *head = new;
    printf("ENTRY SUCCESSFULL !!!");
    return true; 
}

/**
 * stdUpdate - fonction de mis a jour
 * @pk: cle primary de l'etudiant a modifier
 * @modify: la nouvelle entree
 * @head: liste des etudiant
 * Return: true or false
*/
bool stdUpdate(char *pk, std_t *modify, stdlink **head)
{
    int i;

    if (pk == NULL || modify == NULL)
    {
        printf("MODIFICATION FAIL !!!");
        return false;
    }

    if (head == NULL || *head == NULL)
        return stdAdd(modify, head);

    for (i = 0; (*head)->next != NULL; i++)
    {
        if (strcmp((*head)->data->_pk, pk) == 0)
        {
            (*head)->data->first_name = strdup(modify->first_name);
            (*head)->data->last_name = strdup(modify->last_name);
            (*head)->data->birthday = modify->birthday;
            (*head)->data->contact->indic = strdup(modify->contact->indic); 
            (*head)->data->contact->number = modify->contact->number;
            (*head)->data->emergency->fullname = strdup(modify->emergency->fullname); 
            (*head)->data->emergency->contact->indic = strdup(modify->emergency->contact->indic);
            (*head)->data->emergency->contact->number = modify->emergency->contact->number;
            (*head)->data->last_diploma = strdup(modify->last_diploma);
            (*head)->data->nationality = strdup(modify->nationality);

            printf("MODIFICATION SUCESSFULL !!!");
            return true;
        }
        (*head) = (*head)->next;
    }

    printf("MODIFICATION FAIL !!!");
    return false;
}

/**
 * stdRemove - suppression d'etudiant
 * @pk: cle primaire
 * @head: liste d'etudiant
 * Return: true or false
*/
bool stdRemove(char *pk, stdlink **head)
{
    int i, j;
    stdlink *del;
    if (pk == NULL || head == NULL || *head == NULL)
    {
        printf("NO STUDENT !!!");
        return false;
    }

    for (i = 0; (*head)->next != NULL || strcmp((*head)->next->data->_pk, pk) == 0 ; i++);

    if ((*head)->next == NULL)
    {
        printf("NO STUDENT !!!");
        return false;
    }
    
    del = (*head)->next;
    (*head)->next = (*head)->next->next;
    free(del);
    printf("STUDENT %s REMOVE SUCCESS !!!", pk);
    return true;
}

/**
 * stdAllRemove - all remove
 * @head: list
 * Return: true or false
*/
bool stdAllRemove(stdlink **head)
{
    stdlink *del;
    int i;
    if (head == NULL)
        return true;
    for (i = 0; (*head)->next != NULL; i++)
    {
        del = (*head);
        (*head) = (*head)->next;
        *head = (*head);
        free(del);
    }
    free((*head));
    return true;
}
