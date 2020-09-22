/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:03:31 by skarry            #+#    #+#             */
/*   Updated: 2020/09/15 17:03:35 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_empty_s(char *s)
{
	while (*s)
	{
		if (*s != '\n')
		{
			free(s);
			return (1);
		}
		s++;
	}
	return (0);
}

int		findmap(char *s)
{
	while (*s)
	{
		if (*s == '1')
			return (1);
		s++;
	}
	return (0);
}

void	data_init(t_data_cub *data)
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

void	data_check(t_data_cub data)
{
	if (data.r1 == -1 || data.r2 == -1\
	|| data.no == NULL || data.so == NULL\
	|| data.we == NULL || data.ea == NULL\
	|| data.s == NULL || data.f.r == -1\
	|| data.f.g == -1 || data.f.b == -1\
	|| data.c.r == -1 || data.c.g == -1\
	|| data.c.b == -1 || !data.map)
		ft_exit("Invalid map");
}

int		cardinal_type(char *s, t_data_cub *data)
{
	while (*s == ' ')
		s++;
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
