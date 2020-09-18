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

#include "cub/cub3d.h"

int		main(int argc, char **argv)
{
	int			i;
	char		**map;
	t_list		*z_map;
	t_data_cub	data;

	i = 0;
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
	mlx_hook(data.win, 2, 0, ft_key, &data);
	mlx_hook(data.win, 17, 0, ft_key_exit, NULL);
	mlx_loop(data.mlx);
	return (0);
}
