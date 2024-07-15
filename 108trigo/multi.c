/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** compute.c
*/

#include "trigo.h"

double **array_to_matrix(char **argv, int *n, int argc)
{
    double ni = sqrt(argc - 2);
    double **mat = NULL;
    int a = 2;

    if (ni != (int)ni)
        exit(84);
    *n = ni;
    mat = malloc(*n * sizeof(double *));
    for (int l = 0; l < *n; l++) {
        mat[l] = malloc(*n * sizeof(double));
        for (int c = 0; c < *n; c++) {
            mat[l][c] = atof(argv[a]);
            a++;
        }
    }
    return mat;
}

double compute_multi(ma_t *pt, double **mat1, double **mat2)
{
    double r = 0;

    for (int a = 0; a < pt->n; a++) {
        r += mat1[pt->l][a] * mat2[a][pt->c];
    }
    return r;
}

double **multi_matrix(double **mat1, double **mat2, int n)
{
    double **result = malloc(n * sizeof(double *));
    ma_t *pt = malloc(sizeof(ma_t));

    pt->c = 0;
    pt->l = 0;
    pt->n = n;
    for (int a = 0; a < n; a++)
        result[a] = malloc(n * sizeof(double));
    for (pt->l = 0; pt->l < n; pt->l++) {
        for (pt->c = 0; pt->c < n; pt->c++) {
            result[pt->l][pt->c] = compute_multi(pt, mat1, mat2);
        }
    }
    return result;
}

double **matrix_ident(int n)
{
    double **mat = malloc(n * sizeof(double *));

    for (int l = 0; l < n; l++) {
        mat[l] = malloc(n * sizeof(double));
        for (int c = 0; c < n; c++) {
            if (c == l) {
                mat[l][c] = 1;
            } else
                mat[l][c] = 0;
        }
    }
    return mat;
}

double **add_matrix(double **mat1, double **mat2, int n)
{
    double **matr = malloc(n * sizeof(double *));

    for (int l = 0; l < n; l++) {
        matr[l] = malloc(n * sizeof(double));
        for (int c = 0; c < n; c++)
            matr[l][c] = mat1[l][c] + mat2[l][c];
    }
    return matr;
}
