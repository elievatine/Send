/*
** EPITECH PROJECT, 2018
** map_chages
** File description:
** my_world
*/

#include "my.h"

int **fill_map_3d(int **map_3d)
{
	int x = 0;
	int y = 0;

	while (y != MAP_Y - 1) {
		x = 0;
		while (x != MAP_X - 1) {
			map_3d[y][x] = 0;
			if (x > 3  && x < 6 && y == 2)
				map_3d[y][x] = 20;
			if (x > 7  && x < 12 && y == 10)
				map_3d[y][x] = 10;
			x += 1;
		}
		y += 1;
	}
	return (map_3d);
}


