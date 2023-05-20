#include "std.h"


/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t sd_count(stable_t **db, char *key)
{
    if (!db || !key)
    return 0;

    stable_t *cur = *db;
    size_t j;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->students->key, key) == 0)
        {
            slink_t *head =  cur->students;

            for (j = 0; head->next != NULL; j++)
                head = head->next;

            return j;
        }
        cur = cur->next;
    }
    return 0;
}

void shortStudPrint(std_t *study)
{
    char *str;
    strftime(str, 8, "%X", study->birthday);
    printf("\
        First Name      : %s\n\
        Last Name       : %s\n\
        Birthday        : %s\n\
        Country         : %s\n\
        Emergency       : %s\n\
        Phone           : %s\n\
        Dilpome         : %s\n\
        Department      : %s\n\
        Grade           : %s\n\
        ",
        study->first_name,
        study->last_name,
        str,
        study->nation,
        study->emergency->full_name,
        litteralPhone(study->contact),
        study->diploma,
        study->department->name,
        (study->grade == LICENCE) ? "Licence" : ((study->grade == MASTER) ? "Master" : "Doctorat")
    );
}

/**
 * show - fonction d'affichage
 * @head: list des universités
 * @univ: soit id soit null
*/
void sd_show(stable_t **db, char *key, char *id)
{
    if (!key || !db || !(*db))
        return;
    
    stable_t *cur = *db;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->students->key, key) == 0)
        {
            slink_t *head = cur->students;
            if (id)
            {
                for (int j = 0; head->next != NULL; j++)
                {
                    if (strcmp(head->std->id, id) == 0)
                    {
                        shortStudPrint(head->std);
                        return;
                    }
                    head = head->next;
                }
                return;
            }
            for (int j = 0; head->next != NULL; j++)
            {
                shortStudPrint(head->std);
                head = head->next;
            }
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
bool std_add(stable_t **db, char *key, std_t *study)
{
    if(!study || !key)
        return false;
    
    stable_t *new = malloc(sizeof(stable_t));
    if (!new)
        return false;
    
    study->id = idGenerator();
    new->students->std = study;
}

bool stadd(stdlink_t **head, std_t *dp)
{
    stdlink_t *new;

    if (!dp)
        return error("entry null");

    dp->id = idGenerator();

    new = malloc(sizeof(stdlink_t));
    if (!new)
        return error("new register fail !!!");
    
    new->std = dp;
    
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
bool sdupdate(stdlink_t **head, std_t *modified, char *id)
{
    stdlink_t *cur;

    if (!head | !*head)
        return add(head, modified);
    
    if (!modified || !id)
        return error("modification fail !!!");
    
    cur = *head;
    
    for (int i = 0; !cur->next; i++)
        if (strcmp(cur->std->id, id) == 0)
        {
            cur->std = modified;
            return true;
        }
            
}

/**
 * del - supprimer
 * @head: list des universités
 * @id: identifiant
 * return true or false
*/
bool stdel(stdlink_t **head, char *id)
{
    stdlink_t *cur;

    if (!head || !*head)
        return error("deleting fail !!!");
    
    cur = *head;
    
    if (!id)
    {
        stdlink_t *rem;

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
        if (strcmp(cur->next->std->id, id) == 0)
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
bool stdremove(stdlink_t **head, char **ids, bool *func(stdlink_t **head, char *id))
{
    for (int i = 0; !ids; i++)
        func(head, ids[i]);
    return true;
}
