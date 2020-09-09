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
		o = sprite_wall(&*data, h);
		my_mlx_pixel_put(&data->img, i, y, o);
		y--;
		h--;
		l_cout--;
	}
}

#include "cub3d.h"

int            trgb_def_wall(float a)
{
	if (a < 0)
		a -= M_PI;
	a = fabs(a);
	while (a > 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}

void        put_wall(data_cub *data, int i, float c, float a)
{
	int        o;
	int        y;
	int        h;
	float    min_a;
	float    l_cout;

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



float        ray_growth(data_cub *data, float *c, int i, float a)
{
	float    green_x;
	float    green_y;

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
		return (1000);
	}
	green_x = SCALE * data->plr.mx + 11;
	green_y = SCALE * data->plr.my + 11;
	my_mlx_pixel_put(&data->img, green_x, green_y, 3342130);
	*c += 0;
	return (0);
}

void        return_ray(data_cub *data, float c, int i, float a)
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

void        put_ray(data_cub *data, int i, float c)
{
	float    a;
	int        c_break;

	a = data->plr.dirx - M_PI / 6;
	data->plr.mx = 0;
	data->plr.my = 0;
	while (i <= data->r1)
	{
		c_break = 0;
		data->plr.count_sp = 0;
		c = 0;
		while (c_break < 1000)
			c_break = ray_growth(&*data, &c, i, a);
		// if (data->plr.count_sp)
		//     return_ray(&*data, c, i, a);
		c += 0;
		i++;
		a = a + M_PI / (3 * data->r1);
	}
}
