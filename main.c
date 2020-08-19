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

#include "libcub/cub3d.h"

int		main(int argc, char **argv)
{
	char		**map;
	t_list		*z_map;
	int			i = 0;
	data_cub	data;
	


	errno = 0;
	if (argc > 3 || argc < 2)
		ft_exit("Wrong number of arguments");
	z_map = map_to_lst(argv[1]);
    map_lst_to_mas(z_map, &map);
	data_init(&data);
	map_mas_to_stuct(map, &data, 0);
	data_check(data);

	data.mlx = mlx_init();

	all_paint(&data, &data.img, data.mlx);


	printf("R %d %d\n", data.r1, data.r2);
	printf("NO %s\n", data.no);
	printf("SO %s\n", data.so);
	printf("WE %s\n", data.we);
	printf("EA %s\n", data.ea);
	printf("S %s\n", data.s);
	printf("F %d,%d,%d\n", data.f.r, data.f.g, data.f.b);
	printf("C %d,%d,%d\n", data.c.r, data.c.g, data.c.b);
	while (data.map[i] != NULL)
	{
		printf("MAP [%s]\n", data.map[i]);
		i++;
	}
	mlx_hook(data.win, 2, 0, ft_key, &data);
	mlx_loop(data.mlx);
	return(0);
}