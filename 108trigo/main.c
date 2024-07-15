/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** main.c
*/

#include "trigo.h"

double **mat;
int main(int argc, char **argv)
{
    int n = 0;

    is_fun(argv[1], argc);
    is_nmbr(argv);
    is_perfect_square(argc - 2);
    mat = array_to_matrix(argv, &n, argc);
    if (strcmp(argv[1], "SIN") == 0)
        mat = sin_matrix(mat, n);
    if (strcmp(argv[1], "COS") == 0)
        mat = cos_matrix(mat, n);
    if (strcmp(argv[1], "SINH") == 0)
        mat = sinh_matrix(mat, n);
    if (strcmp(argv[1], "COSH") == 0)
        mat = cosh_matrix(mat, n);
    if (strcmp(argv[1], "EXP") == 0)
        mat = expo(mat, n);
    for (int l = 0; l < n; l++) {
        for (int c = 0; c < n - 1; c++)
            printf("%.2f\t", mat[l][c]);
        printf("%.2f\n", mat[l][n - 1]);
    }
    free_matrix(mat, n);
}
