/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** trigo.c
*/

#include "trigo.h"

double **expo(double **mat, int n)
{
    double **matr = add_matrix(matrix_ident(n), mat, n);

    for (double i = 2; i < 50; i++)
        matr = add_matrix(matr, multi_facto(mat, i, n), n);
    return matr;
}

double **sin_matrix(double **mat, int n)
{
    double **matr = mat;

    for (double i = 1; i < 50; i++)
        matr = add_matrix(matr, coef_matrix(multi_facto(mat, 2.0 * i + 1.0, n), pow(-1, i), n), n);
    return matr;
}

double **cos_matrix(double **mat, int n)
{
    double **matr = matrix_ident(n);

    for (double i = 1; i < 50; i++)
        matr = add_matrix(matr, coef_matrix(multi_facto(mat, 2.0 * i, n), pow(-1, i), n), n);
    return matr;
}

double **cosh_matrix(double **mat, int n)
{
    double **matr = matrix_ident(n);

    for (double i = 1; i < 50; i++)
        matr = add_matrix(matr, multi_facto(mat, 2.0 * i, n), n);
    return matr;
}

double **sinh_matrix(double **mat, int n)
{
    double **matr = mat;

    for (double i = 1; i < 50; i++)
        matr = add_matrix(matr, multi_facto(mat, 2.0 * i + 1.0, n), n);
    return matr;
}
