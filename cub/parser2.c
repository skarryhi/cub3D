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

int			check_by_y(char **m, int y, int x)
{
	while (m[y])
	{
		if (m[y][x] != '1' && m[y][x] != ' ')
			ft_exit("Invalid map");
		y++;
	}
	return (y);
}

int			check_by_x(char **m, int y, int x)
{
	while (m[y][x])
	{
		if (m[y][x] != '1' && m[y][x] != ' ')
			ft_exit("Invalid map");
		x++;
	}
	return (x);
}

void		check_side(char **m, int y, int x)
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

void		check_all_null(char **m, int y, int x)
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
			x++;
		}
		x = 1;
		y++;
	}
	check_by_x(m, y, 1);
}

void		check_valid_map(t_data_cub *data)
{
	check_all_sim(data->map, 0, 0);
	check_one_plr(&*data, 0, 0);
	data->plr.my = check_by_y(data->map, 0, 0);
	data->plr.mx = check_by_x(data->map, 0, 0);
	check_all_null(data->map, 1, 1);
}
