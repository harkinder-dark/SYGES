/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "ue.h"


void ueAllView(uelink **head)
{
    int i;
    if (head == NULL || *head == NULL)
        return;
    
    for (i = 0; (*head)->next != NULL; i++)
    {
        printf("Code        :\n", (*head)->data->name);
        printf("Niveau      :\n", (*head)->data->level);
        printf("coefficient :\n", (*head)->data->weight);
        
        (*head) = (*head)->next;
    }
}

void ueSingleView(char *pk, uelink **head)
{
    int i, res = 0;
    if (head == NULL || *head == NULL)
        return;
    
    for (i = 0; (*head)->next != NULL; i++)
    {
        if (strcmp(pk, (*head)->data->__pk) == 0)
        {
            printf("Code        :\n", (*head)->data->name);
            printf("Niveau      :\n", (*head)->data->level);
            printf("coefficient :\n", (*head)->data->weight);

            return; 
        }
        
        (*head) = (*head)->next;
    }

    if (res == 0)
        printf("FREE !!!");
}


bool ueAdd(ue_t *entry, uelink **head)
{
    uelink *new;

    if (entry == NULL)
    {
        printf("ENTRY FAILS !!!");
        return false;
    }

    if (ueFind(entry, head) != NULL)
    {
        printf("ENRTY EXISTS !!!");
        return false;
    }

    entry->__pk = uekeyGenerator(entry);
    new = malloc(sizeof(uelink));
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


bool stdUpdate(char *pk, ue_t *modify, uelink **head)
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
        if (strcmp(modify->contact, (*head)->data->contact) == 0  && strcmp((*head)->data->_pk, pk) != 0)
        {
            printf("MODIFICATION FAIL !!!");
            return false;
        }

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
            // save(entry)
            printf("MODIFICATION SUCESSFULL !!!");
            return true;
        }
        (*head) = (*head)->next;
    }

    return false;
}