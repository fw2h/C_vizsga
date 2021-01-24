#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void reverse(FILE *);
char **read(FILE *,char **, int *);
void write(char **, int);
void memcheck(void *);

#endif