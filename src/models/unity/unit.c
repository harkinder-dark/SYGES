#include "unit.h"

/**
 * count - longueur de la list
 * @head: list des facultés
 * return size_t
*/
size_t unity_count(etable_t **db, char *key)
{
    if (!db || !(*db) || !key) return 0;

    etable_t *cur = *db;
    size_t j;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->unity->key, key) == 0)
        {
            elink_t *head = cur->unity;
            for (j = 0; head->next != NULL; j++)
                head = head->next;
            return j;
        }
        cur = cur->next;
    }
    return 0;
}

void shortUnitPrint(ue_t *unity)
{
    printf("\
        Code            : \n\
        Poids           : \n\
        Grade           : \n\
        Departement     : \n\
    ",
    unity->code,
    unity->weight,
    unity->grade,
    unity->dp
    );
}

/**
 * show - fonction d'affichage
 * @head: list des universités
 * @univ: soit id soit null
*/
void unity_show(etable_t **db, char *key, char *id)
{
    if (!key || !db || !(*db)) return;

    etable_t *cur = *db;
    for (int i = 0; cur->next != NULL; i++)
    {
        if (strcmp(cur->unity->key, key) == 0)
        {
            elink_t *head = cur->unity;
            if (id)
            {
                for (int j = 0; head->next != NULL; j++)
                {
                    if (strcmp(head->unit->id, id) == 0)
                    {
                        shortUnitPrint(head->unit);
                        return;
                    }
                    head = head->next;
                }
                return;
            }

            for (int j = 0; head->next != NULL; j++)
            {
                shortUnitPrint(head->unit);
                head = head->next;
            }
        }
        cur = cur->next;
    }
}

bool unity_add(etable_t *db, char *key, ue_t *ue)
{

}
