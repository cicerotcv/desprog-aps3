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
    // casos particulares
    if (n == 0 || m == 0) {
        length[n][m] = 0;
        return length[n][m];  // return evita processamento desnecessário
    }

    if (a[n - 1] == b[m - 1]) {
        length[n][m] = 1 + mlcs_w(a, n - 1, b, m - 1, length);
        return length[n][m];
    }

    int l1 = mlcs_w(a, n - 1, b, m, length);
    int l2 = mlcs_w(a, n, b, m - 1, length);

    return l1 > l2 ? l1 : l2;
}

int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    for (int row_index = 0; row_index <= n; row_index++) {
        for (int column_index = 0; column_index <= m; column_index++) {
            length[row_index][column_index] = -1;
        }
    }

    return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) { return 2; }
