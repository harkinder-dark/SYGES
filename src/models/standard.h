#ifndef std_h
#define std_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define LICENCE     180
#define L1  60
#define L2  60
#define L3  60

#define MASTER      120
#define M1  60
#define M2  60

#define DOCTORAT    180
#define D1  60
#define D2  60
#define D3  60

int dizaine(long long n);
size_t digits(long long n);
char *toString(long long n);
char *idGenerator();

#endif
