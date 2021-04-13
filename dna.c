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

    if (length[n][m] != -1) {
        return length[n][m];
    }

    if (a[n - 1] == b[m - 1]) {
        length[n][m] = 1 + mlcs_w(a, n - 1, b, m - 1, length);
        return length[n][m];
    }

    int l1 = mlcs_w(a, n - 1, b, m, length);
    int l2 = mlcs_w(a, n, b, m - 1, length);

    length[n][m] = l1 > l2 ? l1 : l2;

    return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    for (int row = 0; row <= n; row++) {
        for (int column = 0; column <= m; column++) {
            length[row][column] = -1;
        }
    }

    return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    // inicializa a matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            length[i][j] = -1;
        }
    }

    // recursão escondida
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                length[i][j] = 0;
            }
            if (a[i - 1] == b[j - 1]) {
                length[i][j] = 1 + length[j - 1][j - 1];
            } else {
                int l1 = length[i - 1][j];
                int l2 = length[i][j - 1];
                int max = l1 > l2 ? l1 : l2;
                length[i][j] = max;
            }
        }
    }

    return length[n][m];
}
