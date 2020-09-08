/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:25:34 by skarry            #+#    #+#             */
/*   Updated: 2020/09/08 15:25:40 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void			my_mlx_pixel_put(pix *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			getpixelcolor(pix *img, int x, int y)
{
	if (!img->width || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width))\
		* (img->bits_per_pixel / 8))));
}

void			all_paint(data_cub *data, pix *img, void *mlx)
{
	data->win = mlx_new_window(mlx, data->r1, data->r2, "cub3D");
	img->img = mlx_new_image(mlx, data->r1, data->r2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,\
					&img->line_length, &img->endian);
	get_all_texture(&*data, mlx, &data->txt);

	put_map(&*data, &*img);
	mlx_put_image_to_window(mlx, data->win, img->img, 0, 0);
}

void		get_all_texture(data_cub *data, void *mlx, txt *txt)
{
	txt->n.img = mlx_xpm_file_to_image(mlx, data->no,\
				&txt->n.width, &txt->n.height);
	txt->n.addr = mlx_get_data_addr(txt->n.img, &txt->n.bits_per_pixel,\
				&txt->n.line_length, &txt->n.endian);
	txt->s.img = mlx_xpm_file_to_image(mlx, data->so,\
				&txt->s.width, &txt->s.height);
	txt->s.addr = mlx_get_data_addr(txt->s.img, &txt->s.bits_per_pixel,\
				&txt->s.line_length, &txt->s.endian);
	txt->e.img = mlx_xpm_file_to_image(mlx, data->ea,\
				&txt->e.width, &txt->e.height);
	txt->e.addr = mlx_get_data_addr(txt->e.img, &txt->e.bits_per_pixel,\
				&txt->e.line_length, &txt->e.endian);
	txt->w.img = mlx_xpm_file_to_image(mlx, data->we,\
				&txt->w.width, &txt->w.height);
	txt->w.addr = mlx_get_data_addr(txt->w.img, &txt->w.bits_per_pixel,\
				&txt->w.line_length, &txt->w.endian);
	txt->sp.img = mlx_xpm_file_to_image(mlx, data->s,\
				&txt->sp.width, &txt->sp.height);
	txt->sp.addr = mlx_get_data_addr(txt->sp.img, &txt->sp.bits_per_pixel,\
				&txt->sp.line_length, &txt->sp.endian);
}
