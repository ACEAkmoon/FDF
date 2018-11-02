/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrushin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:16:56 by akrushin          #+#    #+#             */
/*   Updated: 2018/10/23 18:16:58 by akrushin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include <minilibx/mlx.h>

# define ERROR(x) if (x) ft_error("");

# define WIN_W 800
# define WIN_H 800

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				widht;
	int				height;
	int				**arr;
	unsigned long	color;
	int				lines;
	int				arrcount;
}					t_map;

void				ft_drawer(t_map *map);
void				ft_error(char *err_str);
void				ft_display_controls(void);
int					ft_reader(t_map *map, char *av);
int					ft_key_hook(int key_code, t_map *map);

#endif
