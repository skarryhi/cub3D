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

void		put_wall(data_cub *data, int i, int c)
{
	int o;
	int l;
	int y;

	o = create_trgb(0, 255, 140, 0);
	if (c == 0)
		c = 1;
	l = (data->r2) / c;
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
		// a = data->plr.dirx-M_PI/6 + M_PI/3*i/(float)(data->r2/2);
		while (c < 20) 
		{
			x = data->plr.x + c * cos(a);
			y = data->plr.y + c * sin(a);
			if (data->map[(int)y][(int)x] == '1')
			{
				put_wall(&*data, i, c);
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