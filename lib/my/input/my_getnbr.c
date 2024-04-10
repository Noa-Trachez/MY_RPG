/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** Get an int from a string
*/

static void compute_sign(char const *str, int *pos, int *sign)
{
    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            *sign *= -1;
        *pos = i + 1;
    }
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int number = 0;
    int pos = 0;

    compute_sign(str, &pos, &sign);
    for (int i = pos; str[i] >= 48 && str[i] <= 57; i++) {
        if (number > (2147483647 - (str[i] - 48)) && sign == 1)
            return (0);
        if (number > (2147483648 - (str[i] - 48 )))
            return (0);
        number = number * 10 + (str[i] - 48);
    }
    return (number * sign);
}
