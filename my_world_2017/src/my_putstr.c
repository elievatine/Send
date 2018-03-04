/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** putstr
*/

#include <unistd.h>

void	my_putchar(char c);

void	my_putstr(char *c)
{
	char *i;
	i = c;

	while (*i != '\0'){
	my_putchar(*i);
	i++;
	}
}
