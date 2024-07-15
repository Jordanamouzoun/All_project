/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** free.c
*/

#include "trigo.h"

int free_matrix(double **mat, int n)
{
    for (int l = 0; l < n; l++)
        free(mat[l]);
    free(mat);
}
