/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrushin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:20:44 by akrushin          #+#    #+#             */
/*   Updated: 2018/10/23 18:20:45 by akrushin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		ft_reader(&map, av[1]);
		ft_display_controls();
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, WIN_W, WIN_H, "akrushin");
		map.pos_x = WIN_W * 0.5;
		map.pos_y = 200;
		map.pos_z = -5;
		map.widht = (WIN_W * 0.3) / (map.arrcount - 1);
		map.height = (WIN_H * 0.3) / (map.lines - 1);
		map.color = 0x8A46FF;
		ft_drawer(&map);
		mlx_key_hook(map.win, ft_key_hook, &map);
		mlx_loop(map.mlx);
	}
	ft_error("usage: FDF input_file");
	return (1);
}
