#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int		my_strchr(char const *str, char c)
{
	int i = 0;

	while (str[i]) {
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char*	strcon(char *s1, char const *s2, int *i)
{
	char *tmp;
	int len;
	int k = 0;

	len = my_strlen(s1) + my_strlen(s2 + *i);
	tmp = malloc(sizeof(char) * len + 1);
	tmp[len] = '\0';
	for (int j = 0; s1[j]; j++)
		tmp[k++] = s1[j];
	for (; s2[*i] != '\0' && s2[*i] != '\n'; *i += 1)
		tmp[k++] = s2[*i];
	free(s1);
	*i = (s2[*i] == '\0') ? 0 : *i + 1;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char static buffer[READ_SIZE + 1];
	int len;
	char *tmp;
	int static i = 0;

	tmp = malloc(sizeof(char) * 1);
	tmp[0] = '\0';
	if (i != 0) {
		if (my_strchr(buffer + i, '\n'))
			return (strcon(tmp, buffer, &i));
		tmp = strcon(tmp, buffer, &i);
	}
	while ((len = read(fd, buffer, READ_SIZE)) != 0) {
		buffer[len] = '\0';
		if (my_strchr(buffer, '\n'))
			return (strcon(tmp, buffer, &i));
		else
			tmp = strcon(tmp, buffer, &i);
	}
	return (NULL);
}
