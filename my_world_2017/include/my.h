/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my_world
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#define MAP_X 16
#define MAP_Y 16


int **create_map_3d(int x, int y);
int **fill_map_3d(int **map_3d);
sfVector2f **create_2d_map(int **map_3d);
void draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d);
float convert_deg_rad(float float_angle);
void	my_put_nbr(int n);
void	my_putstr(char *c);
void	my_putchar(char c);
