#include "std.h"


/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t study_count(stable_t **db, char *key)
{
    if (!db || !(*db) || !key)
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
void study_show(stable_t **db, char *key, char *id)
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
bool study_add(stable_t **db, char *key, std_t *study)
{
    if(!study || !key)
        return false;
    
    stable_t *new = malloc(sizeof(stable_t));
    if (!new)
        return false;
    
    study->id = idGenerator();
    new->students->std = study;
    new->students->key = key;
    new->students->next = NULL;

    if (!db || !(*db))
    {
        *db = new;
        new->next = NULL;
        return true;
    } else {
        stable_t *cur = *db;
        for (int i = 0; cur->next != NULL; i++)
        {
            if (strcmp(cur->students->key, key) == 0)
            {
                slink_t *head = cur->students;
                for (int j = 0; head->next; j++)
                    head = head->next;
                head->next = new->students;
                new->next = NULL;
                return true;
            }
            cur = cur->next;
        }
        new->next = *db;
        *db = new;
        return true;
    }
    return false;
}

bool study_update(stable_t **db, char *key, std_t *modified, char *id)
{
    stable_t *cur;

    if (!modified || !key) return false;

    if (!db || !(*db)) return study_add(db, key, modified);

    cur = *db;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->students->key, key) == 0)
        {
            slink_t *head = cur->students;
            for (int j = 0; head->next != NULL; j++)
            {
                if (strcmp(head->std->id, id) == 0)
                {
                    head->std->birthday = modified->birthday;
                    head->std->contact = modified->contact;
                    head->std->diploma = modified->diploma;
                    head->std->emergency = modified->emergency;
                    head->std->first_name = modified->first_name;
                    head->std->grade = modified->grade;
                    head->std->last_name = modified->last_name;
                    head->std->nation = modified->nation;
                    return true;
                }
                head = head->next;
            }
        }
        cur = cur->next;
    }
}
