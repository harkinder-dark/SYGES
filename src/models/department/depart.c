#include "depart.h"


/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t dp_count(dptable_t **db, char *key)
{
    dptable_t *cur;

    if (!db || !(*db) || !key)
        return 0;
    
    cur = *db;
    int j;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->departments->key, key) == 0)
        {
            dlink_t *head = cur->departments;
            for (j = 0; head->next != NULL; j++)
                head = head->next;
            return j;
        }
        cur = cur->next;
    }
    return 0;
}


void departmentPrint(dp_t *pd)
{
    printf("\
        Name        : %s\n\
        Speciality  : %s\n\
        ",
        pd->name,
        pd->speciality
    );
}


/**
 * show - fonction d'affichage
 * @head: list des universités
 * @univ: soit id soit null
*/
void dp_show(dptable_t **db, char *key, char *id)
{
    dptable_t *cur;
    if (!db || !(*db) || !key)
        return;
    
    cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->departments->key, key) == 0)
        {
            dlink_t *head = cur->departments;
            if (id)
            {
                for (int j = 0; head->next != NULL; j++)
                {
                    if (strcmp(head->depart->id, id) == 0)
                    {
                        departmentPrint(head);
                        return;
                    }
                    head = head->next;
                }
                return;
            } else {
                for (int j = 0; head->next != NULL; j++)
                {
                    departmentPrint(head);
                    head = head->next;
                }
                return;
            }
            return;   
        }
        cur = cur->next;
    }
}

/**
 * add - ajout d'une universite
 * @head: list des universités
 * @univ: la nouvelle université
 * return true or false
*/
bool dp_add(dptable_t **db, char *key, dp_t *dp)
{
    if (!dp || !key)
        return false;

    dptable_t *cur, *new;

    new = malloc(sizeof(dptable_t));
    if (!new)
        return false;

    dp->id = idGenerator();
    new->departments->depart = dp;
    new->departments->key = key;
    new->departments->next = NULL;

    if (!db || !(*db))
    {
        new->next = NULL;
        *db = new;

        return true;
    } else {
        cur = *db;
        for (int i = 0; cur->next != NULL; i++)
        {
            if (strcmp(cur->departments->key, key) == 0)
            {
                dlink_t *head = cur->departments;
                for (int j = 0; head->next != NULL; j++)
                    head = head->next;
                head->next = new->departments;

                return true;
            }
            cur = cur->next;
        }

        // si la clé n'est pas trouver
        new->next = *db;
        *db = new;
        return true;
    }
    return false;
}


/**
 * update - mis a jour
 * @head: list des université
 * @modified: les modifications
 * @id: l'identifiant de l'element a modifier
 * return true or false
*/
bool dp_update(dptable_t **db, char *key, dp_t *modified, char *id)
{
    dptable_t *cur;

    if (!modified || !id || key)
        return false;
    
    if (!db || !(*db))
        return dpadd(db, key, modified);
    
    cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->departments->key, key) == 0)
        {
            dlink_t *head = cur->departments;
            for (int j = 0; head->next != NULL; j++)
            {
                if (strcmp(head->depart->id, id) == 0)
                {
                    head->depart->name = strdup(modified->name);
                    head->depart->speciality = strdup(modified->speciality);
                    return true;
                }
                head = head->next;
            }
        }
        cur = cur->next;
    }
    return false;
}
