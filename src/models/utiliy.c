/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "student.h"

/**
 * stdFind - verifier si l'entree n'existe pas deja dans le base
 * @entry: la nouvelle entree
 * @head: tableau de tous les entree
 * Return: std_t
*/
std_t *stdFind(std_t *entry, std_t **head)
{
    int i;
    for (i = 0; (*head) = (*head) + i, (*head) != NULL; i++)
    {
        if (strcmp((*head)->contact, entry->contact) == 0)
            return (*head);
    }
    return NULL;
}

/**
 * stdkeyGenerator - generateur de cle primaire
 * @entry: etudiant
 * Return : une chaine unique
*/
char *stdkeyGenerator(std_t *entry)
{
    /**
     * le code ascii de contact.number + 
     * le code ascii de  birthday  ex: 07/11/1999
     * enprenant 2 chiffire et si le dernier est seul on le prend ainsi
    */
    char src[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, j;

    char *pk;
    /* je constitue une chaine de format jjmmaaaanumber ou 
    jj = jour du mois
    mm = mois de l'annee
    aaaa = l'annee
    qui a leur tour sont la date de naissace de l'etudiant
    number = le numero telephonique sans l'indicatif
    */
    pk = strcat(toString(entry->birthday->tm_mday), toString(entry->birthday->tm_mon));
    pk = strcat(pk, toString(entry->birthday->tm_year));
    pk = strcat(pk, toString(entry->contact->number));

    return ascii_transform(pk);
}

/**
 * letter_ascii - transforme un int en son code letterascii
 * @c: integer
 * Return: char
*/
char letter_ascii(int c)
{
    return (char) c;
}

/**
 * ascii_transform - transform un string en son correspondant letter_ascii par pair de caractere
 * @str: la chgaine de nombre
 * Return: char *
*/
char *ascii_transform(char *str)
{
    char *dest, src[2];
    int i, j;
    size_t n;

    if (str == NULL)
        return NULL;
    
    n = strlen(str);
    /* la nouvelle chaine fera la moitier de celle entree en parametre*/
    n = ((n & 1) == 0) ? n/2 : n/2 + 1;
    
    dest = malloc(n * sizeof(char) + 1);
    if (dest == NULL)
        return NULL;
    
    /**
     * nous irons de 2 en 2 alors on s'assure de ne pas fais de segmentation fault
     * c'est juste une precaution , la boucle for elle meme y veille deja
    */
    for (i = 0, j = 0; str[i] != '\0'; i = (str[i + 2] != '\0') ? i + 2 : -1, j++)
    {
        if (i = -1) break;
        src[0] = str[i];
        src[1] = (str[i + 1] == '\0') ? '0' : str[i + 1];
        dest[j] = ascii(atoi(src));
    }
    dest[j] = '\0';
    return dest;
}

/**
 * digit - recupere la dizaine d'un nombre
 * @n: number
 * Return: integer
*/
int digit(long n)
{
return (n / 10);
}

char *toString(long n)
{
    long m;
    int i, j = -1;
    size_t size = 2;
    char *str = malloc(size * sizeof(char));
    if (n >= 10)
    {
        while(n >= 10)
        {
            m = n;
            while(m >= 10)
            {
                m = digit(m);
                i++;
            }

            if (j >= size) str = _realloc(str, size);
            str[++j] = m + '0';
            size = strlen(str);

            while(i > 0)
            {
                m = m * 10;
                i--;
            }

            n = n - m;
        }

        if (j >= size) str = _realloc(str, size);
        str[++j] = n + '0';
        size = strlen(str);
    } else {
        str[0] = n + '0';
        str[1] = "";
    }
    return str;
}

char *_realloc(char *ptr, size_t size)
{
    char *str;
    int i;
    if (ptr == NULL)
        return NULL;
    str = malloc((size + 2) * sizeof(char));
    for (i = 0; i < size; i++)
        str[i] = ptr[i];
    return str;
}
