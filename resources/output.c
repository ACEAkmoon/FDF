/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrushin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:21:48 by akrushin          #+#    #+#             */
/*   Updated: 2018/10/23 18:21:50 by akrushin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *err_str)
{
	*err_str ? ft_putendl(err_str) : ft_putendl("error");
	exit(1);
}

void		ft_display_controls(void)
{
	ft_putstr("\
_______________________________\n\
CONTROLS:\n\
Translation:\n\
	Y: Key: UP, DOWN\n\
	X: Key: LEFT, RIGHT\n\
\n\
Height:\n\
	IN: Keypad: Page Up\n\
	OUT: Keypad: Page Down\n\
\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\
\n\
Color:\n\
	IN: Key: C\n\
\n\
Exit:\n\
	IN: Key: Esc\n\
_______________________________\n\
");
}

static void	ft_bresenhem(t_map *map, int x, int y, int *xy)
{
	int x_arr[2];
	int y_arr[2];
	int e[2];

	x_arr[0] = abs(xy[0] - x);
	y_arr[0] = abs(xy[1] - y);
	x_arr[1] = x < xy[0] ? 1 : -1;
	y_arr[1] = y < xy[1] ? 1 : -1;
	e[0] = (x_arr[0] > y_arr[0] ? x_arr[0] : -y_arr[0]) / 2;
	while (x != xy[0] || y != xy[1])
	{
		mlx_pixel_put(map->mlx, map->win, x, y, map->color);
		e[1] = e[0];
		if (e[1] < y_arr[0])
		{
			e[0] += x_arr[0];
			y += y_arr[1];
		}
		if (e[1] > (x_arr[0] * -1))
		{
			e[0] -= y_arr[0];
			x += x_arr[1];
		}
	}
}

static void	ft_print_line(t_map *map, int x, int y)
{
	int x_pos;
	int y_pos;
	int xy[2];

	x_pos = map->pos_x + (x - y);
	y_pos = map->pos_y + map->arr[y / map->height][x / map->widht] \
		* map->pos_z + x + y;
	if (x / map->widht < map->arrcount && y / map->height < map->lines - 1)
	{
		xy[0] = map->pos_x + (x - (y + map->height));
		xy[1] = map->pos_y + map->arr[y / map->height + 1][x / map->widht]
						* map->pos_z + x + (y + map->height);
		ft_bresenhem(map, x_pos, y_pos, xy);
	}
	if (y / map->height < map->lines && x / map->widht < map->arrcount - 1)
	{
		xy[0] = map->pos_x + ((x + map->widht) - y);
		xy[1] = map->pos_y + map->arr[y / map->height][x / map->widht + 1]
						* map->pos_z + (x + map->widht) + y;
		ft_bresenhem(map, x_pos, y_pos, xy);
	}
}

void		ft_drawer(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->widht == 0 ? map->widht++ : map->widht;
	map->height == 0 ? map->height++ : map->height;
	while (x / map->widht < map->arrcount || y / map->height < map->lines - 1)
	{
		if (x / map->widht == map->arrcount)
		{
			x = 0;
			y += map->height;
		}
		ft_print_line(map, x, y);
		x += map->widht;
	}
}
