/*
** EPITECH PROJECT, 2021
** INCLUDE/INPUT
** File description:
** Includes "input" functions
*/

#ifndef INPUT_H
    #define INPUT_H

int my_getnbr(char const *str);
char *my_strdup(char const *src);
int my_strncmp(char const *str1, char const *str2, int n);
int my_memset(void *str, int c, int n);
int my_memcpy(void *dest, const void *src, int len);
char *int_to_str(unsigned long nb);
char *my_strappend(char *str, char *fill, int free_str);
int my_strlen(char const *str);
char **my_tabdup(const char **world);
char *my_strconcat(char *dest, char *src);

#endif/*INPUT_H*/
