#include "unit.h"

/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t unicount(unilink_t **head)
{
    int i;
    unilink_t *current;

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
void unishow(unilink_t **head, char *id)
{
    unilink_t *cur;

    if (!head || !*head)
        return;
    
    cur = *head;

    if (id)
    {
        for (int i = 0; !cur->next; i++)
        {
            if (strcmp(cur->unit->id, id) == 0)
            {
                printf("\
                    Code Ue    : %s\n\
                    Niveau     : %s\n\
                    Poids      : %s\n\
                    ",
                    cur->unit->code,
                    cur->unit->level,
                    cur->unit->weight
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
            cur->unit->code,
            cur->unit->level,
            cur->unit->weight
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
bool unadd(unilink_t **head, uni_t *ue)
{
    unilink_t *new;

    if (!ue)
        return error("entry null");

    ue->id = idGenerator();

    new = malloc(sizeof(unilink_t));
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
bool unipdate(unilink_t **head, uni_t *modified, char *id)
{
    unilink_t *cur;

    if (!head | !*head)
        return add(head, modified);
    
    if (!modified || !id)
        return error("modification fail !!!");
    
    cur = *head;
    
    for (int i = 0; !cur->next; i++)
        if (strcmp(cur->unit->id, id) == 0)
        {
            cur->unit = modified;
            return true;
        }
            
}

/**
 * del - supprimer
 * @head: list des universités
 * @id: identifiant
 * return true or false
*/
bool unidel(unilink_t **head, char *id)
{
    unilink_t *cur;

    if (!head || !*head)
        return error("deleting fail !!!");
    
    cur = *head;
    
    if (!id)
    {
        unilink_t *rem;

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
bool uniremove(unilink_t **head, char **ids, bool *func(unilink_t **head, char *id))
{
    for (int i = 0; !ids; i++)
        func(head, ids[i]);
    return true;
}
