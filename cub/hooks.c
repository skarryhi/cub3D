/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:50:51 by skarry            #+#    #+#             */
/*   Updated: 2020/09/15 16:50:54 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pushes(t_data_cub *data, float step, float a)
{
	data->plr.x = data->plr.x + step * cos(data->plr.dirx - a);
	data->plr.y = data->plr.y + step * sin(data->plr.dirx - a);
	if (data->map[(int)data->plr.y][(int)data->plr.x] == '1' ||\
		data->map[(int)data->plr.y][(int)data->plr.x] == ' ')
	{
		data->plr.x = data->plr.x - step * cos(data->plr.dirx - a);
		data->plr.y = data->plr.y - step * sin(data->plr.dirx - a);
	}
	put_map(&*data, &data->img);
}

void	pushes_angl(t_data_cub *data, float a)
{
	data->plr.dirx += a;
	put_map(&*data, &data->img);
}

int		ft_key(int keycode, t_data_cub *data)
{
	float	step;

	step = 0.4;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 0)
		pushes(&*data, step, (M_PI / 2));
	if (keycode == 2)
		pushes(&*data, step, -(M_PI / 2));
	if (keycode == 13)
		pushes(&*data, step, 0);
	if (keycode == 1)
		pushes(&*data, -step, 0);
	if (keycode == 124)
		pushes_angl(&*data, M_PI / 16);
	if (keycode == 123)
		pushes_angl(&*data, -(M_PI / 16));
	return (0);
}
