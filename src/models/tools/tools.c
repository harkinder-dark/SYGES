#include "tools.h"


bool createPerson(plink_t **head, char *fullName, ph_t *phone)
{
    pers_t *newPerson;

    if (!fullName || !phone)
        return false;
    
    newPerson = malloc(sizeof(pers_t));
    if (!newPerson)
        return false;

    newPerson->id = idGenerator();
    newPerson->full_name = fullName;
    newPerson->phone = phone;

    return personSave(head, newPerson);
}


bool personSave(plink_t **head, pers_t *person)
{
    if (!person)
        return false;
    
    plink_t *cur, *new;
    cur = *head;
    new->person = person;
    new->next = NULL;

    if (!head || !(*head))
    {
        new = *head;
        return true;
    } else {
        for (int i = 0; cur->next != NULL; i++)
        {
            if (strcmp(person->phone, cur->person->phone) == 0)
                return false;

            cur =cur->next;
        }
        cur->next = new;
        return true;
    }
    return false;
}


char *litteralPerson(pers_t *person, char *phone)
{
    /**
     * nous avons essayez de creer inconsciement un dictionnaire python
     * {'key': 'val'}
    */
    return strcat(
        "id:",
        strcat(
            person->id,
            strcat(
                " ",
                strcat(
                    "fullname:",
                    strcat(
                        person->full_name,
                        strcat(
                            " ",
                            phone
                        )
                    )
                )
            )
        )
    );
}

/**
 * phoned - creer un numero
 * @indic: indicatif
 * @number: le numero
 * return phone type
*/
ph_t *phoned(char *indic, numeric number)
{
    ph_t *phone = malloc(sizeof(ph_t));
    phone->indic = indic;
    phone->number = number;
    return phone;
}

/**
 * litteralPhone - renvoie une chainne litteral
 * @phone: phone number
 * return string
*/
char *litteralPhone(ph_t *phone)
{
    return strcat(
        "phone:",
        strcat(
           phone->indic,
           toString(phone->number)
        )
    );
}
