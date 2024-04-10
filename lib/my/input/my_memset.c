/*
** EPITECH PROJECT, 2021
** MY_MEMSET
** File description:
** Copies the char c to the first n characters of the string
*/

int my_memset(void *str, int c, int n)
{
    char *ptr = str;

    for (int i = 0; i < n; i++)
        ptr[i] = c;
    return (0);
}

int my_memcpy(void *dest, const void *src, int len)
{
    char *d = dest;
    const char *s = src;

    for (int i = 0; i < len; i++) {
        *d = *s;
        *d++;
        *s++;
    }
    return 0;
}
