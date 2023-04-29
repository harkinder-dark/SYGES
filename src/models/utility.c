/**
 * File             : student.h
 * Directory        : src/models/student.c
 * Author           : Victor Doledji alias Hydromel
 * Collaborators    : ...
*/

#include "student.h"
/*
int decimal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char string[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char decimalChar(size_t n)
{
    int i;

    for (i = 0; i < 10 ; i++)
        if (n == decimal[i])
            return string[i];
    return "";
}

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
        if (strcmp((*head)->contact->indic, entry->contact->indic) == 0 && strcmp(toString((*head)->contact->number), toString(entry->contact->number))== 0)
            return (*head);
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
    j = 0;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < n; j = j + 2)
            dest[i] = (char) atoi(str[j] + str + j + 1));
    }
    dest[j] = '\0';
    return dest;
}

/**
 * dizaine - recupere la dizaine d'un nombre
 * @n: number
 * Return: integer
*/
int dizaine(long long n) { return (n / 10); }

/**
 * digits - nombre de chiffre
 * @n: nombre
 * Return: size_t
*/
size_t digits(long long n)
{
    int i;
    long long p = n;

    for (i = 0; p >= 10; i++)
        p = dizaine(p);
    
    return i + 1;
}

char *toString(long long n)
{
    char *str;
    int i, j, k;
    long long p;

    if (n < 10)
    {
        str = malloc(sizeof(char) + 1);
        *str = n + '0';
        
        *(str + 1) = '\0';
        return str;
    }
    
    str = malloc(digits(n) * sizeof(char) + 1);
    if (str == NULL)
        return NULL;
    
    for (j = 0; n >= 10; j++)
    {
        p = n;

        for (i = 0; p >= 10; i++)
            p = dizaine(p);
        
        str[j] = p + '0';
        for (i; i > 0; i--)
            p *= 10;

        n -= p;
        if (digits(n) + 1 < digits(p))
            for (i = 0; i < digits(p) - digits(n) - 1; i++)
                str[++j] = '0';
    }
    str[j] = n + '0';
    str[j + 1] = '\0';

    return str;
}

/**
 * _realloc - re-allocation dynamique
 * @ptr: chaine entrante
 * @size: taille de la chaine entrante
 * Return: char*
*/
char *_realloc(char *ptr, size_t size)
{
    char *str;
    int i;

    /*on verifie si l'entree n'est pas null*/
    if (ptr == NULL)
    {
        str = malloc(2 * sizeof(char));
        if (str == NULL)
            return NULL;
        
        return str;
    }

    /*on verifie si size n'est pas null*/
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    /*nouvelle allocation*/
    str = malloc((size + 2) * sizeof(char));
    if (str == NULL)
        return NULL;

    /*copie des donnees vers la nouvelle variable*/
    for (i = 0; i < size; i++)
        str[i] = ptr[i];

    return str;
}
