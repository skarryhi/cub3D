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

int			trgb_wall(data_cub data, float a)
{
	int	o;

	if (a < 0)
		a -= M_PI;
	a = fabs(a);
	o = create_trgb(0, 128, 128, 128);
	while (a > 2 * M_PI)
		a -= 2 * M_PI;

	if (data.map[(int)data.plr.my][(int)(data.plr.mx - 0.02)] == '0' &&\
		data.map[(int)data.plr.my][(int)(data.plr.mx + 0.02)] == '1' &&\
		data.map[(int)(data.plr.my - 0.02)][(int)data.plr.mx] == '1' &&\
		data.map[(int)(data.plr.my + 0.02)][(int)data.plr.mx] == '1')
		o = create_trgb(0, 0, 128, 128);//blue
	else if (data.map[(int)data.plr.my][(int)(data.plr.mx - 0.02)] == '1' &&\
		data.map[(int)data.plr.my][(int)(data.plr.mx + 0.02)] == '1' &&\
		data.map[(int)(data.plr.my - 0.02)][(int)data.plr.mx] == '0' &&\
		data.map[(int)(data.plr.my + 0.02)][(int)data.plr.mx] == '1')
		o = create_trgb(0, 255, 215, 0);//gold
	else if (data.map[(int)data.plr.my][(int)(data.plr.mx - 0.02)] == '1' &&\
		data.map[(int)data.plr.my][(int)(data.plr.mx + 0.02)] == '0' &&\
		data.map[(int)(data.plr.my - 0.02)][(int)data.plr.mx] == '1' &&\
		data.map[(int)(data.plr.my + 0.02)][(int)data.plr.mx] == '1')
		o = create_trgb(0, 255, 140, 0);//orange
	else if (data.map[(int)data.plr.my][(int)(data.plr.mx - 0.02)] == '1' &&\
		data.map[(int)data.plr.my][(int)(data.plr.mx + 0.02)] == '1' &&\
		data.map[(int)(data.plr.my - 0.02)][(int)data.plr.mx] == '1' &&\
		data.map[(int)(data.plr.my + 0.02)][(int)data.plr.mx] == '0')
		o = create_trgb(0, 238, 130, 238);//pink


	else if (a < M_PI_2)
	{
		o = create_trgb(0, 0, 128, 128);//blue
	}
	else if (a > M_PI_2 && a < M_PI)
	{
		o = create_trgb(0, 255, 140, 0);//orange
	}
	else if (a > M_PI && a < 3 * M_PI / 2)
	{
		o = create_trgb(0, 255, 140, 0);//orange
	}
	else if (a > 3 * M_PI_2)
	{
		o = create_trgb(0, 0, 128, 128);//blue
	}
	return (o);
}

void		put_wall(data_cub *data, int i, float c, float a)
{
	int o;
	float l;
	int y;

	o = trgb_wall(*data, a);
	if ((c * cos(a - data->plr.dirx)) < 1)
		l = (data->r2);
	else
		l = (data->r2) / (c * cos(a - data->plr.dirx));
	y = (data->r2 / 2) + (l / 2);
	while (l > 0)
	{
		my_mlx_pixel_put(&data->img, i, y, o);
		y--;
		l--;
	}
}

void		put_ray(data_cub *data, float x, float y)
{
	float c = 0;
	int i ;
	float  a;
	int o;

	o = create_trgb(0, 50, 255, 50);
	a = data->plr.dirx - M_PI / 6;
	i = 0;
	while(i <= data->r1)
	{
		while (c < 1000) 
		{
			x = data->plr.x + c * cos(a);
			y = data->plr.y + c * sin(a);
			if (data->map[(int)y][(int)x] == '1' || data->map[(int)y][(int)x] == ' ')
			{
				data->plr.mx = x;
				data->plr.my = y;
				put_wall(&*data, i, c, a);
				break;
			}
			x = SCALE * x + 11;
			y = SCALE * y + 11;
			my_mlx_pixel_put(&data->img, x, y, o);
			c += 0.01;
		}
		c = 0;
		i++;
		a = a + M_PI / (3 * data->r1);
	}
}