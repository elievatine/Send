/*
** EPITECH PROJECT, 2017
** atoi
** File description:
** char * -> int
*/

#include <stdio.h>


int	my_get_numlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	get_sign(char *str)
{
	char	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] < '0' || str[i] > '9') {
		if (str[i] == '-' && sign == -1)
			sign = 1;
		if (str[i] == '-' && sign == 1)
			sign = -1;
		i++;
	}
	return (sign);
}

int	power(int num, int pow)
{
	if (pow > 1)
		return (num * power(num, pow - 1));
	if (pow == 1)
		return (num);
	if (pow == 0)
		return (1);
	if (pow < 0)
		return (0);
	return(-1);
}

int	my_atoi(char *str)
{
	int	sign;
	int	i;
	int	numlen;
	int	num;

	sign = get_sign(str);
	i = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	numlen = my_get_numlen(&str[i]);
	num = 0;
	while (numlen > 0) {
		num += ((str[i] - '0') * power(10, numlen));
		numlen--;
		i++;
	}
	num = num * sign / 10;
	return (num);
}

