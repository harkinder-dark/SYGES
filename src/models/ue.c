/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "ue.h"


/**
 * ueAllView - affichage de tout les eu
 * @head: liste des eu
*/
void ueAllView(uelink **head)
{
    int i;
    if (head == NULL || *head == NULL)
        return;
    
    for (i = 0; (*head)->next != NULL; i++)
    {
        printf("Code        :\n", (*head)->data->code);
        printf("Niveau      :\n", (*head)->data->level);
        printf("coefficient :\n", (*head)->data->weight);
        
        (*head) = (*head)->next;
    }
}

/**
 * ueSingleView - affichage d'une eu
 * @head: liste des ue
*/
void ueSingleView(char *pk, uelink **head)
{
    int i, res = 0;
    if (head == NULL || *head == NULL)
        return;
    
    for (i = 0; (*head)->next != NULL; i++)
    {
        if (strcmp(pk, (*head)->data->code) == 0)
        {
            printf("Code        :\n", (*head)->data->code);
            printf("Niveau      :\n", (*head)->data->level);
            printf("coefficient :\n", (*head)->data->weight);

            return; 
        }
        
        (*head) = (*head)->next;
    }

    if (res == 0)
        printf("FREE !!!");
}

/**
 * ueAdd - ajout d'une nouvelle ue
 * @entry: la nouvelle ue
 * @head: list des eu
 * Return: true or false
*/
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

/**
 * ueUpdate - mis a jour
 * @pk: new code
 * @modify: modified ue
 * @head: list
 * Return: true or false
*/
bool ueUpdate(char *pk, ue_t *modify, uelink **head)
{
    int i;

    if (pk == NULL || modify == NULL)
    {
        printf("MODIFICATION FAIL !!!");
        return false;
    }

    if (head == NULL || *head == NULL)
        return ueAdd(modify, head);

    for (i = 0; (*head)->next != NULL; i++)
    {
        if (strcmp((*head)->data->code, pk) == 0)
        {
            (*head)->data->code = strdup(modify->code);
            (*head)->data->level = strdup(modify->level);
            (*head)->data->weight = modify->weight;

            printf("MODIFICATION SUCESSFULL !!!");
            return true;
        }
        (*head) = (*head)->next;
    }

    return false;
}

/**
 * ueRemove - single remove
 * @pk: code
 * @head: list
 * Return: true or false
*/
bool ueRemove(char *pk, uelink **head)
{
    int i, j;
    uelink *del;
    if (pk == NULL || head == NULL || *head == NULL)
    {
        printf("NO LEARNING UNITY !!!");
        return false;
    }

    for (i = 0; (*head)->next != NULL || strcmp((*head)->next->data->code, pk) == 0 ; i++);

    if ((*head)->next == NULL)
    {
        printf("NO LEARNING UNITY !!!");
        return false;
    }
    
    del = (*head)->next;
    (*head)->next = (*head)->next->next;
    free(del);
    printf("LEARNING UNITY %s REMOVE SUCCESS !!!", pk);
    return true;
}

/**
 * ueAllRemove - all remove
 * @head: list
 * Return: true or false
*/
bool ueAllRemove(uelink **head)
{
    uelink *del;
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
