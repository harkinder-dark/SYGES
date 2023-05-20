#include "fac.h"

/**
 * faculty_count - nombre de faculte dans une université
 * @db: tables de hash des facultés
 * @key: identifiant d'une université
 * return unsigned integer
*/
size_t faculty_count(ftable_t **db, char *key)
{
    int j;
    ftable_t *cur;
    /* si la base de données est vide*/
    if (!db || !(*db))
        return 0;

    cur = *db;
    /* on parjcours la table de hashage*/
    for (int i = 0; cur->next != NULL; i++)
    {
        /* on parcours la liste des facultés dont
        l'identifiant de l'université es key*/
        if (strcmp(cur->faculties->key, key) == 0)
        {
            flink_t *head;
            head = cur->faculties;
            for (j = 0; head->next != NULL; j++)
                head = head->next;
            return j;
        }
        cur = cur->next;
    }
    return 0;
}

/**
 * shortPrintFac - affichage
 * @fac: faculty
*/
void shortPrintFac(fac_t *fac)
{
    printf("\
        Name    : %s\n\
        Domaine : %s\n\
        ",
        fac->name,
        fac->domain
    );
}

/**
 * faculty_show - affichage
 * @db: table de hashage des faculté
 * @key: identifiant unique de l'université
 * @id: identifiant d'une université ou null
*/
void faculty_show(ftable_t **db, char *key, char *id)
{
    ftable_t *cur;
    if (!db || !(*db))
        return;
    
    cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->faculties->key, key) == 0)
        {
            flink_t *head = cur->faculties;
            if (id)
            {
                for (int j = 0; head->next != NULL; j++)
                {
                    if (strcmp(head->faculty->id, id) == 0)
                    {
                        shortPrintFac(head->faculty);
                        return;
                    }
                    head = head->next;
                }
                return;
            } else {
                for (int j = 0; head->next != NULL; j++)
                { 
                    shortPrintFac(head->faculty);
                    head = head->next;
                }
                return;
            }
        }
        cur = cur->next;
    }
}

/**
 * faculty_add - ajout d'une faculty
 * @db: list des fac de cette université
 * @key: identifiant de l'université
 * @fac: la faculté a ajouter
 * return true or false
*/
bool faculty_add(ftable_t **db, char *key, fac_t *fac)
{
    ftable_t *new;
    int i;
    /*
    si la nouvelle entree est vide ou que la key est vide
    */
    if (!fac || !key)
        return false;
    
    new = malloc(sizeof(ftable_t));
    if (new == NULL)
        return false;

    fac->id = idGenerator();
    new->faculties->faculty = fac;
    new->faculties->key = key;
    new->faculties->next = NULL;

    if (!db || !(*db))
    {
        *db = new;
        new->next = NULL;
        return true;
    } else {

        ftable_t *cur = *db;
        for (i = 0; cur->next != NULL; i++)
        {
            /*on recherche la key de l'université ou nous devons 
            ajouter la faculté*/
            if (strcmp(cur->faculties->key, key) == 0)
            {
                flink_t *head = cur->faculties;
                for (int j = 0; head->next != NULL; j++)
                    head = head->next;
                /* ajout a la fin de la liste des faculté de son université*/
                head->next = new->faculties;
                new->next = NULL;
                return true;
            }
            cur = cur->next;
        }

        /*
        si la key n'existe pas alors son université 
        n'a pas encore de faculté enregistrer*/
        /*
        ajout au debut de la base*/
        new->next = *db;
        *db = new;
        return true;
    }
    return false;
}

/**
 * faculty_update - mis a jour
 * @db: base de donnees des faculty
 * @key: identifiant d'une université
 * @modified: les modifications
 * @id: identifiant de la faculté a modifier
 * return true or false
*/
bool faculty_update(ftable_t **db, char *key, fac_t *modified, char *id)
{
    ftable_t *cur;
    if (!modified)
        return false;
    
    if (!db || !(*db))
        return faculty_add(db, key, modified);
    
    cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->faculties->key, key) == 0)
        {
            flink_t *head;
            head = cur->faculties;
            
            for (int j = 0; head->next != NULL; j++)
            {
                if (strcmp(head->faculty->id, id) == 0)
                {
                    head->faculty->domain = modified->domain;
                    head->faculty->name = modified->name;
                    return true;
                }
                head = head->next;
            }
        }
        cur = cur->next;
    }
    return false;
}
