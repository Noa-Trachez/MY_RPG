/*
** EPITECH PROJECT, 2021
** MY_STRNCMP
** File description:
** Returns deference between two ascii value of the first different character
** between both strings and check for n characters
*/

int my_strncmp(char const *str1, char const *str2, int n)
{
    int i = 0;
    for (; str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1; i++);
    return (str1[i] - str2[i]);
}
