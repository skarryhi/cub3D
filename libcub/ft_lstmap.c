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

#include "libcub.h"

int		ft_lstsplit(t_list *z_map, char ***map)
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
