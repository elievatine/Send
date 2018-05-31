/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
	if (nb < 0 && nb != -2147483648) {
		my_putchar('-');
		nb = -1 * nb;
	}
	if (nb <= 9 && nb != -2147483648) {
		my_putchar(nb + '0');
	}
	else if (nb == -2147483648) {
		write(1, "-2147483648", 11);
	}
	else {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
	return (0);
}
