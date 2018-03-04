/*
 ** EPITECH PROJECT, 2018
 ** my_world.c
 ** File description:
 ** my_world
 */

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"
#include "my_struct.h"

float convert_deg_rad(float float_angle)
{
	float pi = 3.14159265;
	float rad;

	rad = (float_angle / 180) * pi;
	return (rad);
}

void world_event(sfEvent event, sfRenderWindow *window)
{
	sfVector2f mouse;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
			sfRenderWindow_close(window);
		if (event.type == sfEvtMouseButtonPressed) {
			mouse.x = event.mouseButton.x;
			mouse.y = event.mouseButton.y;
			if (mouse.x > 555 && mouse.x < 1246
			    && mouse.y > 203 && mouse.y < 762) {
				my_put_nbr(mouse.x);
				my_put_nbr(mouse.y);
			} else
				my_putstr("outside");
		}
	}
}

int main(void)
{
	sfVideoMode video_mode = {1920, 1080, 32};
	sfRenderWindow  *window;
	sfEvent event;
	sfMusic* music;
	int x = MAP_X;
	int y = MAP_Y;
	int **map_3d = create_map_3d(x, y);
	sfVector2f **map_2d = create_2d_map(map_3d);

	window = sfRenderWindow_create(video_mode,
			"my_world",
			sfDefaultStyle,
			NULL);
	if (!window)
		return (84);
	draw_2d_map(window, map_2d);
	while (sfRenderWindow_isOpen(window)) {
		world_event(event, window);
	//	click_event(event, window);
	sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
}
