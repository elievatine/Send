/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** putchar>10
*/

#include <unistd.h>

void	my_putchar(char c);

int		my_putstr(char const *str);

void	my_put_nbr(int n)
{
	if (n == -2147483648)
	{
		my_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		my_putchar('-');
	}
	if (n < 10)
		my_putchar(n + '0');
	else
	{
		my_put_nbr(n / 10);
		my_putchar(n % 10 + '0');
	}
}
