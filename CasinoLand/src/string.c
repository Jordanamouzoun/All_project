/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** string.c
*/

#include "../include/casino.h"

int add_debut(void *data, char *name, int somme)
{
    record_t **students = (record_t **)data;
    record_t *student = malloc(sizeof(record_t));

    strcpy(student->name, name);
    student->somme = somme;
    student->next = NULL;
    if ((*students) == NULL)
        (*students) = student;
    else {
        student->next = (*students);
        (*students) = student;
    }
}

int link_destroy(record_t *record)
{
    record_t *temp;

    for (; record != NULL;) {
        temp = record->next;
        free(record);
        record = temp;
    }
}

int delete_last(record_t **record)
{
    record_t *temp = (*record);
    record_t *tempo;

    for (; (temp->next)->next != NULL; temp = temp->next);
    tempo = temp->next;
    temp->next = NULL;
    free(tempo);
}

int count(char *str, char c)
{
    int l = 0;

    for (int a = 0; str[a] != 0; a++) {
        if (str[a] == c)
            l++;
    }
    return l;
}

char **str_to_word_array(char *str, char *sep)
{
    char *src = strdup(str);
    int a;
    char **arr = malloc((count(str, sep[0]) + 1) * sizeof(char *));
    char *tok = strtok(src, sep);

    for (a = 0; tok != NULL; a++) {
        arr[a] = strdup(tok);
        tok = strtok(NULL, sep);
    }
    arr[a] = NULL;
    return arr;
}

int free_array(char **arr)
{
    for (int a = 0; arr[a]!= NULL; a++) {
        free(arr[a]);
    }
    free(arr);
}

int load(record_t **record)
{
    int fd;
    int long size;
    struct stat inf;
    int len = 0;
    char *s;
    char **arr;
    char **array;

    stat("include/record.txt", &inf);
    fd = open("include/record.txt", O_RDONLY);
    if (fd == -1)
        exit(84);
    s = malloc((inf.st_size + 1) * sizeof(char));
    size = read(fd, s, inf.st_size);
    s[size] = '\0';
    close(fd);
    arr = str_to_word_array(s, "\n");
    for (int a = 0; arr[a] != NULL; a++) {
        array = str_to_word_array(arr[a], ";");
        add_debut(record, array[0], atoi(array[1]));
        free_array(array);
    }
    record_t *temp = (*record);
    free_array(arr);
    free(s);
    return 0;
}

int adder(char *name, int somme, record_t **record)
{
    record_t *temp = *record;
    int len = 0;

    for (len; temp != NULL; len++, temp = temp->next);
    if (len >= 5)
        delete_last(record);
    add_debut(record, name, somme);
}

int save(record_t *record)
{
    int fd = open("include/record.txt", O_RDWR | O_CREAT | O_TRUNC,
    S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP | S_IWOTH);
    record_t *temp = record;
    char buf[128];
    
    for (; temp != NULL; temp = temp->next) {
        sprintf(buf, "%s;%d\n", temp->name, temp->somme);
        write(fd, buf, strlen(buf));
    }
    link_destroy(record);
    close(fd);
}