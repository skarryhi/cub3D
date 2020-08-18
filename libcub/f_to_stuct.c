/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_stuct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:32 by skarry            #+#    #+#             */
/*   Updated: 2020/08/16 15:17:35 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_empty_s(char *s)
{
	while (*s)
	{
		if (*s != '\n')
			return (1);
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

int		r_type(char *s, int *r1, int *r2)
{
	if (*r1 == -1 && *r2 == -1)
	{
	*r1 = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	*r2 = ft_atoi(s);
	s++;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		ft_exit("Invalid map");
	}
	else
		ft_exit("Invalid map");
	if (*r1 <= -1 || *r2 <= -1)
		ft_exit("Invalid map");
	return (0);
}

int		colour_type(char *s, colour *l)
{
	if (l->r == -1 && l->g == -1 && l->b == -1)
	{
	l->r = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	s++;
	l->g = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	s++;
	l->b = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
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

int		size_x(char **s)
{
	int	max = 0;
	int x = 0;
	int	y = 0;

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
	return (max);
}

char	*ft_record(char *s, int x)
{
	char	*re;
	int		i;

	i = 0;
	re = (char *)malloc(x + 1);
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

int		map_type(char **s, int y, data_cub *data)
{
	int	i;
	int	j;
	int x;

	i = 0;
	j = y;
	x = size_x(s);
	while (s[j++])
		i++;
	data->map = (char**)malloc(sizeof(char*) * (i + 1));
	data->map[i] = NULL;
	i = 0;
	while (s[y])
	{
		data->map[i] = s[y];
		if (ft_strlen(data->map[i]) < (size_t)x)
			data->map[i] = ft_record(data->map[i], x);
		y++;
		i++;
	}
	check_valid_map(&*data);
	return (y);
}