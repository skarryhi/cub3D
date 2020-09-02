/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:55:34 by skarry            #+#    #+#             */
/*   Updated: 2020/08/17 18:55:38 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		        create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void            my_mlx_pixel_put(pix *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			put_sq2(int i, pix *img, int x, int y)
{
	int x2 = SCALE;
	int	y2 = SCALE;

	while (y2)
	{
		while (x2)
		{
			my_mlx_pixel_put(&*img, (10 + (x * SCALE) + x2), (10 + (y * SCALE) + y2), i);
			x2--;
		}
		x2 = SCALE;
		y2--;
	}
}
void			put_plr(int i, pix *img, float x, float y)
{
	int x2 = SCALE / 2;
	int	y2 = SCALE / 2;

	while (y2)
	{
		while (x2)
		{
			my_mlx_pixel_put(&*img, (10 + (x * SCALE) + x2), (10 + (y * SCALE) + y2), i);
			x2--;
		}
		x2 = SCALE / 2;
		y2--;
	}
}

void			put_sq1(data_cub data, pix *img, int x, int y)
{
	while (data.map[y])
	{
		while (data.map[y][x] )
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

void				put_floor_ceiling(data_cub *data, int x, int y)
{
	while (y < (data->r2 / 2))
	{
		while (x < data->r1)
		{
			my_mlx_pixel_put(&data->img, x, y, create_trgb(0, data->c.r, data->c.g, data->c.b));
			x++;
		}
		x = 0;
		y++;
	}
	while (y < data->r2)
	{
		while (x < data->r1)
		{
			my_mlx_pixel_put(&data->img, x, y, create_trgb(0, data->f.r, data->f.g, data->f.b));
			x++;
		}
		x = 0;
		y++;
	}
}

void				put_map(data_cub *data, pix *img)
{
	put_floor_ceiling(&*data, 0, 0);
	put_ray(&*data, 0, 0);
	put_sq1(*data, &*img, 0, 0);
	put_plr(create_trgb(0, 139, 0, 0), &*img, data->plr.x, data->plr.y);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void			all_paint(data_cub *data, pix *img, void *mlx)
{
	data->win = mlx_new_window(mlx, data->r1, data->r2, "cub3D");
	img->img = mlx_new_image(mlx, data->r1, data->r2);
	// img = mlx_xpm_file_to_image(mlx, data->ea, &data->img.img_width, &data->img.img_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								 &img->endian);
	put_map(&*data, &*img);
	mlx_put_image_to_window(mlx, data->win, img->img, 0, 0);
}
