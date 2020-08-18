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

void			put_sq(data_cub data, pix *img, int x, int y)
{
	int	i;
	int x2 = SCALE;
	int	y2 = SCALE;
	

	i = create_trgb(0, data.f.r, data.f.g, data.f.b);
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

void			put_p(data_cub data, pix *img, int x, int y)
{
	int	i;
	int x2 = SCALE;
	int	y2 = SCALE;
	

	i = create_trgb(0, data.c.r, data.c.g, data.c.b);
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

void			put_sp(pix *img, int x, int y)
{
	int	i;
	int x2 = SCALE;
	int	y2 = SCALE;
	

	i = create_trgb(0, 0, 255, 0);
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

void            put_map(data_cub data, pix *img, int x, int y)
{
    while (data.map[y])
	{
        while (data.map[y][x] )
		{
			if (data.map[y][x] == '1')
				put_sq(data, &*img, x, y);
			if (data.map[y][x] == '2')
				put_sp(&*img, x, y);	
			x++;
		}
		x = 0;
		y++;
	}
	put_p(data, &*img, data.plr.x, data.plr.y);
}

void            all_paint(data_cub data, pix *img, void *mlx)
{
	void		*mlx_win;

	mlx_win = mlx_new_window(mlx, data.r1, data.r2, "cub3D");
	img->img = mlx_new_image(mlx, data.r1, data.r2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                 &img->endian);
    put_map(data, &*img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
    
}
