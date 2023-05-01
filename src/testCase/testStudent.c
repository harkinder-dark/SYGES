#include "../models/syges.h"

stdlink **head;

bool testRealloc()
{
    char *str = malloc(4 * sizeof(char) + 1);
    str = "papa";
    size_t len1 = strlen(str);
    str = _realloc(str, 4);
    str[5] = 'h';
    str[6] = 'o';
    size_t len2 = strlen(str);
    return (len2 > len1) ? true : false;
}

bool testDizaine() { return (7 == dizaine(78)) ? true : false; }

bool testDigits() { return (5 == digits(18759)) ? true : false; }

bool testToStrings()
{
    long long n = 12340007890;
    return (strcmp("12340007890", toString(n)) == 0) ? true : false;
}

bool testLetterAscii()
{
   int c = 122;
   return ('z' == letter_ascii(c)) ? true : false; 
}

bool testAsciiTransform()
{
    char *str = "40954296552959";
    return (strlen(ascii_transform(str)) <= strlen(str)) ? true : false;
}

bool (*tester[])() = { testRealloc, testDizaine, testDigits, testToStrings, testLetterAscii,
                        testAsciiTransform, NULL};

bool testAdd()
{
    std_t *std1, *std2, *std3;

    std1->first_name = "Hydromel Victor";
    std1->last_name = "Vaddely";
    
}



int main()
{
    int i;
    std_t **head = NULL;

    for (i = 0; tester[i] != NULL; i++)
    {
        printf("%s\n", tester[i]() ? "TEST SUCCESS" : "TEST FAIL");
    }
    return 0;
}