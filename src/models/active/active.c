#include "active.h"

/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t account(aclink_t **head)
{
    int i;
    aclink_t *current;

    if (!head | !*head)
        return 0;

    current = *head;

    for (i = 0; current->next != NULL; i++);
    return i;
}

/**
 * show - fonction d'affichage
 * @head: list des universités
 * @univ: soit id soit null
*/
void unishow(aclink_t **head, char *id)
{
    aclink_t *cur;

    if (!head || !*head)
        return;
    
    cur = *head;

    if (id)
    {
        for (int i = 0; !cur->next; i++)
        {
            if (strcmp(cur->active->id, id) == 0)
            {
                printf("\
                    Code Ue    : %s\n\
                    Etudiant     : %s\n\
                    Poids      : %s\n\
                    ",
                    cur->active->code,
                    cur->active->level,
                    cur->active->weight
                );
                return;
            }
            cur = cur->next;
        }
    }

    for (int i = 0; !cur->next; i++)
    {
        printf("\
            Code Ue    : %s\n\
            Niveau     : %s\n\
            Poids      : %s\n\
            ",
            cur->active->code,
            cur->active->level,
            cur->active->weight
        );
        cur = cur->next;
    }
}

/**
 * add - ajout d'une universite
 * @head: list des universités
 * @univ: la nouvelle université
 * return true or false
*/
bool unadd(aclink_t **head, uni_t *ue)
{
    aclink_t *new;

    if (!ue)
        return error("entry null");

    ue->id = idGenerator();

    new = malloc(sizeof(aclink_t));
    if (!new)
        return error("new register fail !!!");
    
    new->unit = ue;
    
    if (!head || !*head)
        new->next = NULL;
    
    new->next = *head;
    *head = new;
    return true;
}

/**
 * update - mis a jour
 * @head: list des université
 * @modified: les modifications
 * @id: l'identifiant de l'element a modifier
 * return true or false
*/
bool unipdate(aclink_t **head, uni_t *modified, char *id)
{
    aclink_t *cur;

    if (!head | !*head)
        return add(head, modified);
    
    if (!modified || !id)
        return error("modification fail !!!");
    
    cur = *head;
    
    for (int i = 0; !cur->next; i++)
        if (strcmp(cur->active->id, id) == 0)
        {
            cur->active = modified;
            return true;
        }
            
}

/**
 * del - supprimer
 * @head: list des universités
 * @id: identifiant
 * return true or false
*/
bool unidel(aclink_t **head, char *id)
{
    aclink_t *cur;

    if (!head || !*head)
        return error("deleting fail !!!");
    
    cur = *head;
    
    if (!id)
    {
        aclink_t *rem;

        for (int i = 0; !cur->next; i++)
        {
            rem = cur;
            cur = cur->next;
            free(rem);
        }
        free(cur);
        return true;
    }
    
    for (int i = 0; !cur->next; i++)
    {
        if (strcmp(cur->next->unit->id, id) == 0)
        {
            cur->next = cur->next->next;
            free(cur->next);
            return true;
        }
        cur = cur->next;
    }
    return true;
}

/**
 * remove - action de masse
 * @head: list des université
 * @ids: list de ids
 * @func: fonction d'action
*/
bool uniremove(aclink_t **head, char **ids, bool *func(aclink_t **head, char *id))
{
    for (int i = 0; !ids; i++)
        func(head, ids[i]);
    return true;
}
