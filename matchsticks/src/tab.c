#include <stdio.h>
#include "struc.h"

char **map_fill(uti_t *uti)
{
	int max_remove = (uti->line * 2 - 1);
	int space = (max_remove - 1) / 2;
	int size_line = (max_remove + 4);
	uti->map = malloc(sizeof(char*) * (uti->line + 2 + 1));

	if (uti->map == NULL)
		return (84);
	for (int i = 0; i != (uti->line + 2 + 1); i++) {
		uti->map[i] = malloc(sizeof(char) * size_line);
		if (uti->map[i] == NULL)
			return (84);
	}
	uti->map[uti->line + 2] = NULL;
	for (int j = 0; uti->map[j] != NULL; j++) {
		for (int k = 0; k != (size_line - 1); k++) {
			if (j == 0 || j == uti->line + 1 || k == 0  || k == max_remove + 1)
				uti->map[j][k] = '*';
			else if ((k > 0 && k <= space + 1) || (k >= (space + (j * 2 - 1 + 2)) && (k < size_line - 1)))
				uti->map[j][k] = ' ';
			else
				uti->map[j][k] = '|';
			if (k == (size_line - 2))
				uti->map[j][k] = '\n';
		}
		uti->map[j][size_line - 1] = '\0';
		space --;
	}
	return (uti->map);
}
