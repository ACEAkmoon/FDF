/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrushin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:19:48 by akrushin          #+#    #+#             */
/*   Updated: 2018/10/23 18:19:49 by akrushin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_depht(int key, t_map *map)
{
	if (key == 116)
		map->pos_z--;
	if (key == 121)
		map->pos_z++;
}

static void	ft_zoom(int key, t_map *map)
{
	if (key == 69)
	{
		map->widht *= 2;
		map->height *= 2;
	}
	if (key == 78)
	{
		map->widht *= 0.5;
		map->height *= 0.5;
	}
}

static void	ft_move(int key, t_map *map)
{
	if (key == 123)
		map->pos_x -= 15;
	if (key == 124)
		map->pos_x += 15;
	if (key == 125)
		map->pos_y += 15;
	if (key == 126)
		map->pos_y -= 15;
}

static void	ft_close(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		system("leaks fdf");
		exit(0);
	}
}

int			ft_key_hook(int key, t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	if (key == 8)
		map->color = map->color << 1;
	ft_depht(key, map);
	ft_zoom(key, map);
	ft_move(key, map);
	ft_close(key, map);
	ft_drawer(map);
	return (0);
}
