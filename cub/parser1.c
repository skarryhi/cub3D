/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:32 by skarry            #+#    #+#             */
/*   Updated: 2020/10/13 11:43:16 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		r_type(char *s, int *r1, int *r2)
{
	if (*r1 == -1 && *r2 == -1)
	{
		while (*s == ' ')
			s++;
		*r1 = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		while (*s == ' ')
			s++;
		*r2 = ft_atoi(s++);
		while (ft_isdigit(*s))
			s++;
		if (*s)
			ft_exit("Invalid map");
	}
	else
		ft_exit("Invalid map");
	if (*r1 < 10 || *r2 < 10)
		ft_exit("Very small resolution");
	if (*r1 > 2560 || *r2 > 1440)
	{
		*r1 = 2560;
		*r2 = 1440;
	}
	return (0);
}

char	*colour_type_check(char *s, int *r, int f)
{
	while (*s == ' ')
		s++;
	if (ft_isdigit(*s))
		*r = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (f)
		if (*s == ',')
			s++;
	return (s);
}

int		colour_type(char *s, t_colour *l)
{
	if (l->r == -1 && l->g == -1 && l->b == -1)
	{
		s = colour_type_check(s, &l->r, 1);
		s = colour_type_check(s, &l->g, 1);
		s = colour_type_check(s, &l->b, 0);
		if (*s)
			ft_exit("Invalid map");
	}
	else
		ft_exit("Invalid map");
	if (l->r < 0 || l->r > 255 || l->g < 0 || l->g > 255 || \
		l->b < 0 || l->b > 255)
		ft_exit("Invalid map");
	return (0);
}

int		size_x(t_data_cub *data, char **s)
{
	int	max;
	int x;
	int	y;

	max = 0;
	x = 0;
	y = 0;
	while (s[y])
	{
		while (s[y][x])
		{
			x++;
			if (x > max)
				max = x;
		}
		x = 0;
		y++;
	}
	data->plr.map_y = y;
	return (max);
}

char	*ft_record(char *s, int x)
{
	char	*re;
	int		i;

	i = 0;
	if (!(re = (char *)malloc(x + 1)))
		ft_exit("Error of malloc");
	re[x] = 0;
	while (s[i])
	{
		re[i] = s[i];
		i++;
	}
	while (i < x)
	{
		re[i] = ' ';
		i++;
	}
	free(s);
	return (re);
}
