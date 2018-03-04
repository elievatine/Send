/*
** EPITECH PROJECT, 2018
** map_create
** File description:
** my_world
*/

#include "my.h"
#include "my_struct.h"
#include <math.h>

sfVector2f project_iso_point(float x, float y, float z)
{
	sfVector2f point_2d;
	sfVector3f point_3d = {x, y, z};
	sfVector2f angle = {x = convert_deg_rad(45), y = convert_deg_rad(35)};

	point_2d.x = cos(angle.x) * point_3d.x -
		cos(angle.x) * point_3d.y + 900;
	point_2d.y = sin(angle.y) * point_3d.y +
		sin(angle.y) * point_3d.x - point_3d.z + 200;
	return (point_2d);
}

int **create_map_3d(int x, int y)
{
	int **map_3d;
	int i = 0;

	map_3d = malloc(sizeof(int*) * y);
	if (!map_3d)
		return (NULL);
	while(i != y) {
		map_3d[i] = malloc(sizeof(int) * x);
		if (map_3d[i] == NULL)
			return (NULL);
		i++;
	}
	map_3d = fill_map_3d(map_3d);
	return (map_3d);
}

sfVector2f **create_2d_map(int **map_3d)
{
	int i = 0;
	int j = 0;
	sfVector2f **map_2d = malloc(sizeof(sfVector2f*) * MAP_Y);

	if (!map_2d)
		return (NULL);
	while (i != MAP_Y) {
		j = 0;
		map_2d[i] = malloc(sizeof(sfVector2f) * MAP_X + 1);
		if (!map_2d[i])
			return (NULL);
		while (j != MAP_X) {
			map_2d[i][j] = project_iso_point(j * 35, i * 35,
							 map_3d[i][j]);
			j += 1;
		}
		i += 1;
	}
	return (map_2d);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex        vertex1 = {.position = *point1, .color = sfWhite };
	sfVertex        vertex2 = {.position = *point2, .color = sfWhite };

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

void draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d)
{
	int i = 0;
	int j = 0;
	struct vertex ver;
	struct position pos;

	while (j <= MAP_Y - 2) {
		i = 0;
		while (i <= MAP_X - 2) {
			ver.vertex1 = create_line(&(map_2d[j][i]),
						  &(map_2d[j][i + 1]));
			ver.vertex2 = create_line(&(map_2d[j][i]),
						  &(map_2d[j + 1][i]));
			sfRenderWindow_drawVertexArray
				(window, ver.vertex1, NULL);
			 sfRenderWindow_drawVertexArray
				(window, ver.vertex2, NULL);
			i += 1;
		}
		j += 1;
	}
}
