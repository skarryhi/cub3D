/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:38:08 by skarry            #+#    #+#             */
/*   Updated: 2020/08/05 15:38:11 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub/libcub.h"

int		main(int argc, char **argv)
{
	char	**map;
	t_list	*z_map;
	int		i = 0;

	z_map = ft_setmap(argv[1]);
    ft_lstsplit(z_map, &map);
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return(0);
}