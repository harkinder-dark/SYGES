
#include "standard.h"


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

/**
 * toString - transforme un nombre entier en strings
 * @n: nombre
 * return char *
*/
char *toString(long long n)
{
    char *str;
    int i, j, k;
    long long p;

    /**
     * lorsque n est compris entre 0 et 9
    */
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
    
    /**
     * lorsque n est superieur ou egal a 10 
    */
    for (j = 0; n >= 10; j++)
    {
        /* afin de ne pas perdre la valeur de n*/
        p = n;
        
        /* on trouve l'element le plus a gauche*/
        for (i = 0; p >= 10; i++)
            p = dizaine(p);
        
        /* on le traduit en lettre puis on le stock dans la chaine*/
        str[j] = p + '0';

        /* on ajout autant de zero a droite du nombre p afin de le supprimer de n*/
        for (i; i > 0; i--)
            p *= 10;

        n -= p;

        /** 
         * si le nombre de chiffre que comporte le nombre n ajouter a 1 est inferieur
         * au nombre de chiffre que contient p alors il existe un zero qui a ete
         * eliminer par la soutraction de n-p alors on l'ajoute
         */
        if (digits(n) + 1 < digits(p))
            for (i = 0; i < digits(p) - digits(n) - 1; i++)
                str[++j] = '0';
    }
    /* on ajouter le chiffre le plus a droite */
    str[j] = n + '0';
    str[j + 1] = '\0';

    return str;
}

/**
 * idGenerator - generateur d'identifiant
 * return char *
*/
char *idGenerator() {
    /*
    id = Y:yearM:monthD:day-@-HH:hoursMM:minutesSS:second
    */
   time_t date;

   return strcat(
        "Y:",
        strcat(
            toString(date.tm_year),
            strcat(
                "M:",
                strcat(
                    toString(date.tm_mon),
                    strcat(
                        "D:",
                        strcat(
                            toString(date.tm_mday),
                            strcat(
                                "-@-HH:",
                                strcat(
                                    toString(date.tm_hour),
                                    strcat(
                                        "MM:",
                                        strcat(
                                            toString(date.tm_min),
                                            strcat(
                                                "SS:",
                                                toString(date.tm_sec)
                                            )
                                        )
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
   );
}
