/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:58:22 by skarry            #+#    #+#             */
/*   Updated: 2020/09/09 15:58:28 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		place_sprite(data_cub data, float a, float c)
{
	float	length;
	float	def_a;
	float	def_x;
	float	def_y;
	float	w;

	length = 1;
	w = 1;
	def_a = a;
	data.plr.mx = data.plr.x - c * cos(a);
	data.plr.my = data.plr.y - c * sin(a);
	def_x = data.plr.mx;
	def_y = data.plr.my;
	// printf("[%d|%d]", (int)data.plr.my, (int)data.plr.mx);
	// printf("[%f]", c);
	while (data.map[(int)data.plr.my][(int)data.plr.mx] == '2')
	{
		data.plr.mx = data.plr.x - c * cos(a);
		data.plr.my = data.plr.y - c * sin(a);
		a = a - M_PI / (3 * data.r1);
		length += 1;
	}
	while (data.map[(int)def_y][(int)def_x] == '2')
	{
		def_x = data.plr.x - c * cos(def_a);
		def_y = data.plr.y - c * sin(def_a);
		def_a = def_a + M_PI / (3 * data.r1);
		w += 1;
	}
	// printf("[%f|%f]", w, length);
	w += length;
	return (length * 100 / w);
}
void        put_sprite(data_cub *data, int i, float c, float a)
{
	int        o;
	int        y;
	int        h;
	float    l_cout;

	if ((c * cos(a - data->plr.dirx)) < 1)
		data->l = (data->r2);
	else
		data->l = (data->r2) / (c * cos(a - data->plr.dirx));
	y = (data->r2 / 2) + (data->l / 2);
	l_cout = data->l;
	h = data->l;
	while (l_cout > 0)
	{
		o = 3342130;//sprite_wall(&*data, h);
		my_mlx_pixel_put(&data->img, i, y, o);
		y--;
		h--;
		l_cout--;
	}
}

void		return_ray(data_cub *data, float c, int i, float a)
{
	float    dist_fr_wall;
	float    depth;
	float    place;

	dist_fr_wall = 0;
	depth = 0;
	while (data->plr.count_sp)
	{
		data->plr.mx = data->plr.x - dist_fr_wall * cos(a);
		data->plr.my = data->plr.y - dist_fr_wall * sin(a);
		if (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
		{
			data->plr.count_sp--;
			// printf("{%f}", dist_fr_wall);

			while (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
			{
				data->plr.mx = data->plr.x - dist_fr_wall * cos(a);
				data->plr.my = data->plr.y - dist_fr_wall * sin(a);
				dist_fr_wall -= 0.01;
				depth += 0.01;
			}
			place = place_sprite(*data, a, (dist_fr_wall + depth));
			// put_sprite(&*data, i, (c + depth + dist_fr_wall), a);
			i++;
		}
		dist_fr_wall -= 0.01;
		c++;
	}
}