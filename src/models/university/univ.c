#include "univ.h"


/**
 * univers_count - longueur de la list
 * @db: list des universités
 * return size_t
*/
size_t univers_count(ulink_t **db)
{
    int i;
    ulink_t *cur;

    if (!db | !*db)
        return 0;

    cur = *db;
    for (i = 0; cur->next != NULL; i++);
    return i;
}

/**
 * universityPrint - affichage
 * @univs: list chainee des université
*/
void universityPrint(ulink_t *univs)
{
    printf("\
        School Name : %s\n\
        Adreese     : %s\n\
        Country     : %s\n\
        Since       : %s\n\
        ",
        univs->school->name,
        univs->school->address,
        univs->school->country,
        univs->school->since
    );
}

/**
 * show - fonction d'affichage
 * @db: list chainee des universités
 * @id: soit id soit null
*/
void univers_show(ulink_t **db, char *id)
{
    ulink_t *cur;
    if (!db || !*db)
        return;
    
    cur = *db;
    if (id)
    {
        for (int i = 0; cur->next != NULL; i++)
        {
            if(strcmp(cur->school->id, id) == 0)
            {
                universityPrint(cur);
                return;
            }
            cur = cur->next;
        }
        return;
    } else {
        for (int i = 0; cur->next != NULL; i++)
        {
            universityPrint(cur);
            cur = cur->next;
        }
        return;
    }
}
    

/**
 * add - ajout d'une universite
 * @db: list des universités
 * @univ: la nouvelle université
 * return true or false
*/
bool univers_add(ulink_t **db, univ_t *univ)
{
    ulink_t *new;
    if (!univ)
        return false;

    univ->id = idGenerator();
    new = malloc(sizeof(ulink_t));
    if (!new)
        return false;;
    
    new->school = univ;
    if (!db || !*db)
        new->next = NULL;
    else
        new->next = *db;
    *db = new;
    return true;
}

/**
 * update - mis a jour
 * @db: list des université
 * @modified: les modifications
 * @id: l'identifiant de l'element a modifier
 * return true or false
*/
bool univers_update(ulink_t **db, univ_t *modified, char *id)
{
    ulink_t *cur;
    if (!db | !*db)
        return univers_add(db, modified);
    
    if (!modified || !id)
        return false;
    
    cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->school->id, id) == 0)
        {
            cur->school->name = modified->name;
            cur->school->address = modified->address;
            cur->school->country = modified->country;
            cur->school->since = modified->since;
            return true;
        }
        cur = cur->next;
    }
    return false;
}
