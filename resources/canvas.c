/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrushin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:19:07 by akrushin          #+#    #+#             */
/*   Updated: 2018/10/23 18:19:09 by akrushin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_alloc_lines(int fd, t_map *map, char *av)
{
	char	*tmp_str;
	int		ret;
	int		i;

	i = 0;
	tmp_str = NULL;
	while ((ret = get_next_line(fd, &tmp_str)) > 0)
	{
		map->lines++;
		free(tmp_str);
	}
	ERROR(ret == -1);
	if (!(map->arr = (int**)malloc(sizeof(int*) * map->lines)))
	{
		while (i < map->lines)
			free(map->arr[i]);
		free(map->arr);
		ft_error("");
	}
	close(fd);
	ERROR((fd = open(av, O_RDONLY)) < 0);
}

static void	ft_convert_arr(t_map *map, char *tmp_str, int index)
{
	int		i;
	char	**tmp_arr;

	i = 0;
	tmp_arr = ft_strsplit(tmp_str, ' ');
	while (i < map->arrcount)
	{
		map->arr[index][i] = ft_atoi(tmp_arr[i]);
		free(tmp_arr[i++]);
	}
	free(tmp_arr);
}

int			ft_reader(t_map *map, char *av)
{
	char	*tmp_str;
	int		arrcount;
	int		ret;
	int		fd;
	int		i;

	i = 0;
	ERROR((fd = open(av, O_RDONLY)) < 0);
	ret = get_next_line(fd, &tmp_str);
	ERROR(ret == -1 || ret == 0);
	arrcount = ft_arrcount(tmp_str, ' ');
	free(tmp_str);
	close(fd);
	ERROR((fd = open(av, O_RDONLY)) < 0);
	ft_alloc_lines(fd, map, av);
	while ((ret = get_next_line(fd, &tmp_str)) > 0)
	{
		ERROR((map->arrcount = ft_arrcount(tmp_str, ' ')) != arrcount);
		ERROR(!(map->arr[i] = (int*)malloc(sizeof(int) * map->arrcount)));
		ft_convert_arr(map, tmp_str, i++);
		free(tmp_str);
	}
	ERROR(ret == -1);
	return (0);
}
