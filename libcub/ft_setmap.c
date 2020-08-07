/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:52:08 by skarry            #+#    #+#             */
/*   Updated: 2020/08/05 15:52:12 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int     ft_maptomas(char ***map)
{

    return (0);
}

t_list     *ft_setmap(const char *s)
{
    t_list  *i_map;
    t_list  *z_map;
    char    *line;
    int     fd;

    fd = open(s, O_RDONLY);
    z_map = NULL;
    line = NULL;
    while (get_next_line(fd, &line))
    {
        i_map = ft_lstnew(line);
        ft_lstadd_back(&z_map, i_map);
        // printf("%s\n", i_map->content);
    }
    i_map = ft_lstnew(line);
    // printf("%s\n", i_map->content);
    ft_lstadd_back(&z_map, i_map);
    close(fd);
    return (z_map);
}
