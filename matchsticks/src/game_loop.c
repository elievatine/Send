#include "struc.h"
#include <stdlib.h>

void	display_map(char **map)
{
	int a = 0;

	while (map[a] != NULL) {
		my_printf(map[a]);
		a++;
	}
}

int number_stick(char **map)
{
	int c = 0;

	for (int a = 0; map[a] != NULL; a++) {
		for (int j = 0; map[a][j] != '\0'; j++) {
			if (map[a][j] == '|')
				c++;
		}
	}
	if (c == 0)
		return (0);
	else
		return (1);
}

int loop_game(uti_t *uti)
{

	while (number_stick != 0) {
		display_map(uti->map);
		my_printf("\nYour Turn: ");
		my_printf("\nLine: ");
		if (input_line(uti) == 0)
			uti->line_p = my_atoi(get_next_line(0));
		my_printf("Matches: ");
		if (input_match(uti) == 0)
			uti->match_p = my_atoi(get_next_line(1));
		my_printf("Player removed ");
		my_printf("%d", uti->match_p);
		my_printf(" match(es) from line ");
		my_printf("%d\n", uti->line_p);
	}
}

int main(int ac, char **av)
{
	uti_t*uti = malloc(sizeof(uti_t));
	uti->line = atoi(av[1]);
	uti->remov = atoi(av[2]);
	uti->map = map_fill(uti);

	loop_game(uti);

}
