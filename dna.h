#ifndef DNA_H
#define DNA_H
#include <stdio.h>

#define MAX_SIZE 1024

void load_string(FILE *file, int *p, char *s, int t);

int mlcs(char a[], int n, char b[], int m);

int dlcs(char a[], int n, char b[], int m);

#endif
