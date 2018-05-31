#include "struc.h"
#include <stdlib.h>

int input_line(uti_t *uti)
{
	if (atoi(get_next_line(0)) > uti->line || uti->line_p <= 0) {
		my_putstr("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

int input_match(uti_t *uti)
{
	if (atoi(get_next_line(1)) > uti->remov || uti->match_p <= 0) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(uti->remov);
		my_putstr(" matches per turn\n");
		return (1);
	}
	return (0);
}
