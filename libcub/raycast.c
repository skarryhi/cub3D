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
	int		h;
	float	min_a;
	float	l_cout;

	if ((c * cos(a - data->plr.dirx)) < 1)
		data->l = (data->r2);
	else
		data->l = (data->r2) / (c * cos(a - data->plr.dirx));
	y = (data->r2 / 2) + (data->l / 2);
	min_a = trgb_def_wall(a);
	l_cout = data->l;
	h = data->l;
	while (l_cout > 0)
	{
		o = trgb_wall(&*data, min_a, h);
		my_mlx_pixel_put(&data->img, i, y, o);
		y--;
		h--;
		l_cout--;
	}
}

float		ray_growth(data_cub *data, float *c, int i, float a)
{
	float	green_x;
	float	green_y;

	data->plr.mx = data->plr.x + *c * cos(a);
	data->plr.my = data->plr.y + *c * sin(a);
	if (data->map[(int)data->plr.my][(int)data->plr.mx] == '2' &&\
		data->map[(int)data->plr.y][(int)data->plr.x] != '2')
	{
		data->plr.count_sp++;
		while (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
		{
			data->plr.mx = data->plr.x + *c * cos(a);
			data->plr.my = data->plr.y + *c * sin(a);
			*c += 0.01;
		}
	}
	if (data->map[(int)data->plr.my][(int)data->plr.mx] == '1' ||\
		data->map[(int)data->plr.my][(int)data->plr.mx] == ' ')
	{
		put_wall(&*data, i, *c, a);
		return (0);
	}
	green_x = SCALE * data->plr.mx + 11;
	green_y = SCALE * data->plr.my + 11;
	my_mlx_pixel_put(&data->img, green_x, green_y, 3342130);
	*c += 0.01;
	return (1);
}

void		put_ray(data_cub *data, int i, float c)
{
	float	a;
	int		c_break;

	a = data->plr.dirx - M_PI / 6;
	data->plr.mx = 0;
	data->plr.my = 0;
	while (i <= data->r1)
	{
		c_break = 1;
		data->plr.count_sp = 0;
		c = 0;
		while (c_break)
			c_break = ray_growth(&*data, &c, i, a);
		if (data->plr.count_sp)
			return_ray(&*data, c, i, a);
		i++;
		a = a + M_PI / (3 * data->r1);
	}
}
