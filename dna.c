#include "dna.h"

#include <stdio.h>

void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    int possible_result;

    if (m == 0 || n == 0) {
        length[n][m] = 0;
    }
    possible_result = length[m][n];
    // caso trivial
    if (possible_result != -1) {
        return length[m][n];
    }

    return mlcs(a, m, b, n);
}

int mlcs(char a[], int n, char b[], int m) {
    if (n > 0 && m > 0) {
        if (a[n - 1] == b[m - 1]) {
            return mlcs(a, n - 1, b, m - 1) + 1;
        }
        int first = mlcs(a, n - 1, b, m);
        int second = mlcs(a, n, b, m - 1);
        return first > second ? first : second;
    }
    return 0;
}

int dlcs(char a[], int n, char b[], int m) { return 2; }
