/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen
*/

#include <unistd.h>

int		my_strlein(char *c)
{
	int i = 0;
	int nb = 0;

	while (c[i] != '\0'){
	++c;
	++nb;
	}
	return (nb);
}
