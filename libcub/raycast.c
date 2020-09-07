/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:37:06 by skarry            #+#    #+#             */
/*   Updated: 2020/08/31 12:37:09 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			trgb_def_wall(float a)
{
	if (a < 0)
		a -= M_PI;
	a = fabs(a);
	while (a > 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}

void		put_wall(data_cub *data, int i, float c, float a)
{
	int		o;
	int		y;
	float	min_a;
	float	l_cout;

	if ((c * cos(a - data->plr.dirx)) < 1)
		data->l = (data->r2);
	else
		data->l = (data->r2) / (c * cos(a - data->plr.dirx));
	y = (data->r2 / 2) + (data->l / 2);
	min_a = trgb_def_wall(a);
	l_cout = data->l;
	while (l_cout > 0)
	{
		o = trgb_wall(&*data, min_a, y);
		my_mlx_pixel_put(&data->img, i, y, o);
		y--;
		l_cout--;
	}
}

float		ray_growth(data_cub *data, float c, int i, float a)
{
	data->plr.mx = data->plr.x + c * cos(a);
	data->plr.my = data->plr.y + c * sin(a);
	if (data->map[(int)data->plr.my][(int)data->plr.mx] == '1' ||\
		data->map[(int)data->plr.my][(int)data->plr.mx] == ' ')
	{
		put_wall(&*data, i, c, a);
		return (1000);
	}
	data->plr.mx = SCALE * data->plr.mx + 11;
	data->plr.my = SCALE * data->plr.my + 11;
	my_mlx_pixel_put(&data->img, data->plr.mx, data->plr.my, create_trgb(0, 50, 255, 50));
	c += 0.01;
	return (c);
}

void		put_ray(data_cub *data, int i, float c)
{
	float	a;

	a = data->plr.dirx - M_PI / 6;
	data->plr.mx = 0;
	data->plr.my = 0;
	while(i <= data->r1)
	{
		c = 0;
		while (c < 1000) 
			c = ray_growth(&*data, c, i, a);
		i++;
		a = a + M_PI / (3 * data->r1);
	}
}