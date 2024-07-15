/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** trigo.h
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifndef MY_H
    #define MY_H
typedef struct ma {
    int l;
    int c;
    int n;
} ma_t;
double **array_to_matrix(char **argv, int *n, int argc);
double compute_multi(ma_t *pt, double **mat1, double **mat2);
double **multi_matrix(double **mat1, double **mat2, int n);
double **pow_matrix(double **mat, int p, int n);
double factoriel(int nb);
int free_matrix(double **mat, int n);
double **coef_matrix(double **mat, double coef, int n);
double **multi_facto(double **mat, int pos, int n);
double **matrix_ident(int n);
double **add_matrix(double **mat1, double **mat2, int n);
double **add_coef(double **mat, double coef, int n);
double **expo(double **mat, int n);
double **sin_matrix(double **mat, int n);
double **cos_matrix(double **mat, int n);
double **cosh_matrix(double **mat, int n);
double **sinh_matrix(double **mat, int n);
int is_nmbr(char **av);
void is_fun(char *str, int ac);
void is_perfect_square(int ac);
#endif
