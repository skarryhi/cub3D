/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:55:34 by skarry            #+#    #+#             */
/*   Updated: 2020/10/09 12:48:59 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_sq2(int i, t_pix *img, int x, int y)
{
	int x2;
	int	y2;

	x2 = SCALE;
	y2 = SCALE;
	while (y2 > 1)
	{
		while (x2 > 1)
		{
			my_mlx_pixel_put(&*img, (10 + (x * SCALE) + x2), \
									(10 + (y * SCALE) + y2), i);
			x2--;
		}
		x2 = SCALE;
		y2--;
	}
}

void			put_plr(int i, t_pix *img, float x, float y)
{
	int x2;
	int	y2;

	x2 = SCALE / 2;
	y2 = SCALE / 2;
	while (y2)
	{
		while (x2)
		{
			my_mlx_pixel_put(&*img, (10 + (x * SCALE) + x2), \
									(10 + (y * SCALE) + y2), i);
			x2--;
		}
		x2 = SCALE / 2;
		y2--;
	}
}

void			put_sq1(t_data_cub data, t_pix *img, int x, int y)
{
	while (data.map[y])
	{
		while (data.map[y][x])
		{
			if (data.map[y][x] == '1')
				put_sq2(create_trgb(0, 0, 20, 0), &*img, x, y);
			if (data.map[y][x] == '2')
				put_sq2(create_trgb(0, 0, 100, 0), &*img, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			put_floor_ceiling(t_data_cub *data, int x, int y)
{
	int		c;
	int		f;

	c = create_trgb(0, data->c.r, data->c.g, data->c.b);
	f = create_trgb(0, data->f.r, data->f.g, data->f.b);
	while (y < (data->r2 / 2))
	{
		while (x < data->r1)
		{
			my_mlx_pixel_put(&data->img, x, y, c);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < data->r2)
	{
		while (x < data->r1)
		{
			my_mlx_pixel_put(&data->img, x, y, f);
			x++;
		}
		x = 0;
		y++;
	}
}

void			put_map(t_data_cub *data, t_pix *img)
{
	put_floor_ceiling(&*data, 0, 0);
	put_ray(&*data, 0, 0);
	if (data->plr.sp)
	{
		sort_sprite(data, &data->plr.pt);
		put_sprite(&*data);
	}
	cleaning_lst(&*data);
	if (data->plr.map_x * 10 < data->r1 / 2 &&\
		data->plr.map_y * 10 < data->r2 / 2)
	{
		put_sq1(*data, &*img, 0, 0);
		put_plr(create_trgb(0, 139, 0, 0), &*img, data->plr.x, data->plr.y);
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}
