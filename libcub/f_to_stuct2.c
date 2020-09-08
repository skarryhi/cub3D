/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_stuct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:46:47 by skarry            #+#    #+#             */
/*   Updated: 2020/08/16 18:46:50 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_by_y(char **m, int y, int x)
{
	while (m[y])
	{
		if (m[y][x] != '1' && m[y][x] != ' ')
			ft_exit("Invalid map");
		y ++;
	}
	return (y);
}

int	check_by_x(char **m, int y, int x)
{
	while (m[y][x])
	{
		if (m[y][x] != '1' && m[y][x] != ' ')
			ft_exit("Invalid map");
		x ++;
	}
	return (x);
}

void	check_all_sim(char **m, int y, int x)
{
	int	flag = 0;

	while (m[y])
	{
		while (m[y][x])
		{
			if (m[y][x] == '1')
				flag = 1;
			x ++;
		}
		if (!flag)
			ft_exit("Invalid map");
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] != '1' && m[y][x] != ' ' && m[y][x] != '0'\
				&& m[y][x] != '2' && m[y][x] != 'N'  && m[y][x] != 'S'\
				&& m[y][x] != 'E' && m[y][x] != 'W')
				ft_exit("Invalid map");
			x ++;
		}
		x = 0;
		y ++;
		flag = 0;
	}
}

void	dir_plr(data_cub *data, char c)
{
	if (c == 'N')
		data->plr.dirx = M_PI + M_PI / 2;
	if (c == 'S')
		data->plr.dirx = M_PI / 2;
	if (c == 'E')
		data->plr.dirx = 0;
	if (c == 'W')
		data->plr.dirx = M_PI;
}

void	check_one_plr(data_cub *data, int y, int x)
{
	int	flag = 1;

	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'\
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->plr.x = x;
				data->plr.y = y;
				dir_plr(&*data, data->map[y][x]);
				if (flag)
					flag--;
				else
					ft_exit("Invalid map");
			}
			x ++;
		}
		x = 0;
		y ++;
	}
}

void	check_side(char **m, int y, int x)
{
	int	bal;

	bal = 0;
	if (m[y - 1][x] == '0' || m[y - 1][x] == '2'\
		|| m[y - 1][x] == 'N' || m[y - 1][x] == 'S'\
		|| m[y - 1][x] == 'E' || m[y - 1][x] == 'W' || m[y - 1][x] == '1')
		bal++;
	if (m[y][x - 1] == '0' || m[y][x - 1] == '2'\
		|| m[y][x - 1] == 'N' || m[y][x - 1] == 'S'\
		|| m[y][x - 1] == 'E' || m[y][x - 1] == 'W' || m[y][x - 1] == '1')
		bal++;
	if (m[y][x + 1] == '0' || m[y][x + 1] == '2'\
		|| m[y][x + 1] == 'N' || m[y][x + 1] == 'S'\
		|| m[y][x + 1] == 'E' || m[y][x + 1] == 'W' || m[y][x + 1] == '1')
		bal++;
	if (m[y + 1][x] == '0' || m[y + 1][x] == '2'\
		|| m[y + 1][x] == 'N' || m[y + 1][x] == 'S'\
		|| m[y + 1][x] == 'E' || m[y + 1][x] == 'W' || m[y + 1][x] == '1')
		bal++;
	if (bal != 4)
		ft_exit("Invalid map");
}

void	check_all_null(char **m, int y, int x)
{
	while (m[y + 1])
	{
		while (m[y][x])
		{
			if (!m[y][x + 1])
			{
				if (m[y][x] != '1' && m[y][x] != ' ')
					ft_exit("Invalid map");
			}
			else if (m[y][x] == '0' || m[y][x] == '2'\
				|| m[y][x] == 'N' || m[y][x] == 'S'\
				|| m[y][x] == 'E' || m[y][x] == 'W')
				check_side(m, y, x);
			x ++;
		}
		x = 1;
		y ++;
	}
	check_by_x(m, y, 1);
}

void	check_valid_map(data_cub *data)
{
	check_all_sim(data->map, 0, 0);
	check_one_plr(&*data, 0, 0);
	data->plr.my = check_by_y(data->map, 0, 0);
	data->plr.mx = check_by_x(data->map, 0, 0);
	check_all_null(data->map, 1, 1);
}

void 		check_ex_str(char **s, char *s2)
{
	if (*s == NULL)
		*s = s2;
	else
		ft_exit("Invalid map");
}

int			cardinal_type(char *s, data_cub *data)
{
	if (ft_strncmp(s, "NO", 2) == 0)
		check_ex_str(&data->no, s + 3);
	else if (ft_strncmp(s, "SO", 2) == 0)
		check_ex_str(&data->so, s + 3);
	else if (ft_strncmp(s, "WE", 2) == 0)
		check_ex_str(&data->we, s + 3);
	else if (ft_strncmp(s, "EA", 2) == 0)
		check_ex_str(&data->ea, s + 3);
	return (0);
}

void		data_init(data_cub *data)
{
	data->r1 = -1;
	data->r2 = -1;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->s = NULL;
	data->f.r = -1;
	data->f.g = -1;
	data->f.b = -1;
	data->c.r = -1;
	data->c.g = -1;
	data->c.b = -1;
}

void		data_check(data_cub data)
{
	if (data.r1 == -1 || data.r2 == -1\
	|| data.no == NULL || data.so == NULL\
	|| data.we == NULL || data.ea == NULL\
	|| data.s == NULL || data.f.r == -1\
	|| data.f.g == -1 ||data.f.b == -1\
	|| data.c.r == -1 || data.c.g == -1\
	|| data.c.b == -1)
		ft_exit("Invalid map");
}
