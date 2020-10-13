/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:10:49 by skarry            #+#    #+#             */
/*   Updated: 2020/10/13 11:44:10 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		dir_plr(t_data_cub *data, char c)
{
	if (c == 'N')
		data->plr.dirx = 3 * M_PI / 2;
	if (c == 'S')
		data->plr.dirx = M_PI / 2;
	if (c == 'E')
		data->plr.dirx = 0;
	if (c == 'W')
		data->plr.dirx = M_PI;
}

void		check_one_plr(t_data_cub *data, int y, int x)
{
	int	flag;

	flag = 1;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'\
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->plr.x = x + 0.5;
				data->plr.y = y + 0.5;
				dir_plr(&*data, data->map[y][x]);
				if (flag)
					flag--;
				else
					ft_exit("Invalid map");
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (flag)
		ft_exit("Invalid map");
}

void		check_all_sim(char **m, int y, int x)
{
	int	flag;

	flag = 0;
	while (m[y])
	{
		while (m[y][x])
			if (m[y][x++] == '1')
				flag = 1;
		if ((!flag && m[y + 1]))
			ft_exit("Invalid map");
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] != '1' && m[y][x] != ' ' && m[y][x] != '0'\
				&& m[y][x] != '2' && m[y][x] != 'N' && m[y][x] != 'S'\
				&& m[y][x] != 'E' && m[y][x] != 'W')
				ft_exit("Invalid map");
			x++;
		}
		x = 0;
		y++;
		flag = 0;
	}
}

void		check_ex_str(char **s, char *s2)
{
	while (*s2 == ' ')
		s2++;
	if (*s == NULL)
		*s = s2;
	else
		ft_exit("Invalid map");
}

int			map_type(char **s, int y, t_data_cub *data)
{
	int	i;
	int	j;
	int x;

	i = 0;
	j = y;
	x = size_x(&*data, s);
	data->plr.map_x = x;
	while (s[j++])
		i++;
	if (!(data->map = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_exit("Error of malloc");
	data->map[i] = NULL;
	i = 0;
	while (s[y])
	{
		if (!s[y + 1] && s[y][0])
			ft_exit("Invalid map");
		data->map[i] = s[y++];
		if (ft_strlen(data->map[i]) < (size_t)x)
			data->map[i] = ft_record(data->map[i], x);
		i++;
	}
	check_valid_map(&*data);
	return (y);
}
