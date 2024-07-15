/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** compute.c
*/

#include "trigo.h"

double **pow_matrix(double **mat, int p, int n)
{
    double **matr = mat;

    for (int a = 1; a < p; a++)
        matr = multi_matrix(matr, mat, n);
    return matr;
}

double factoriel(int nb)
{
    double rslt = 1;

    for (int a = 0; nb - a != 0; a++)
        rslt = rslt * (nb - a);
    return rslt;
}

double **coef_matrix(double **mat, double coef, int n)
{
    double **matr = malloc(n * sizeof(double *));

    for (int l = 0; l < n; l++) {
        matr[l] = malloc(n * sizeof(double));
        for (int c = 0; c < n; c++)
            matr[l][c] = mat[l][c] * coef;
    }
    return matr;
}

double **multi_facto(double **mat, int pos, int n)
{
    return (coef_matrix(pow_matrix(mat, pos, n), 1.0 / factoriel(pos), n));
}

double **add_coef(double **mat, double coef, int n)
{
    double **matr = malloc(n * sizeof(double *));

    for (int l = 0; l < n; l++) {
        matr[l] = malloc(n * sizeof(double));
        for (int c = 0; c < n; c++)
            matr[l][c] = mat[l][c] + coef;
    }
    return matr;
}
