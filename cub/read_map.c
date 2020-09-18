/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:53:59 by skarry            #+#    #+#             */
/*   Updated: 2020/08/05 18:54:01 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_mas_to_stuct(char **map, t_data_cub *data, int y)
{
	while (map[y])
	{
		if (map[y][0] == 'R')
			r_type(map[y] + 2, &data->r1, &data->r2);
		else if (ft_strncmp(map[y], "NO", 2) == 0 ||\
				ft_strncmp(map[y], "SO", 2) == 0 ||\
				ft_strncmp(map[y], "WE", 2) == 0 ||\
				ft_strncmp(map[y], "EA", 2) == 0)
			cardinal_type(map[y], &*data);
		else if (map[y][0] == 'S')
			check_ex_str(&data->s, map[y] + 2);
		else if (map[y][0] == 'F')
			colour_type(map[y] + 2, &data->f);
		else if (map[y][0] == 'C')
			colour_type(map[y] + 2, &data->c);
		else if (findmap(map[y]))
			y = map_type(map, y, &*data);
		else if (check_empty_s(map[y]))
			ft_exit("Invalid map");
		if (map[y])
			y++;
	}
}

int		map_lst_to_mas(t_list *z_map, char ***map)
{
	int		size;
	int		i;

	size = ft_lstsize(z_map);
	*map = (char**)malloc(sizeof(char*) * (size + 1));
	map[0][size] = NULL;
	i = 0;
	while (size != i)
	{
		(*map)[i] = z_map->content;
		i++;
		z_map = z_map->next;
	}
	return (0);
}

t_list	*map_to_lst(const char *s)
{
	t_list	*i_map;
	t_list	*z_map;
	char	*line;
	int		fd;

	fd = open(s, O_RDONLY);
	check_errno();
	z_map = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		i_map = ft_lstnew(line);
		ft_lstadd_back(&z_map, i_map);
	}
	i_map = ft_lstnew(line);
	ft_lstadd_back(&z_map, i_map);
	close(fd);
	return (z_map);
}
