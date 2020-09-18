/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:29:07 by skarry            #+#    #+#             */
/*   Updated: 2020/09/15 18:29:09 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		get_one_texture(void *mlx, t_pix *n, char *no)
{
	n->img = mlx_xpm_file_to_image(mlx, no, &n->width, &n->height);
	if (n->img == NULL)
		ft_exit("Invalid texture");
	else
		n->addr = mlx_get_data_addr(n->img, &n->bits_per_pixel,\
				&n->line_length, &n->endian);
}

void		get_all_texture(t_data_cub *data, void *mlx, t_txt *txt)
{
	get_one_texture(mlx, &txt->n, data->no);
	get_one_texture(mlx, &txt->s, data->so);
	get_one_texture(mlx, &txt->e, data->we);
	get_one_texture(mlx, &txt->w, data->ea);
	get_one_texture(mlx, &txt->sp, data->s);
}

void		green_ray(t_data_cub *data)
{
	float	green_x;
	float	green_y;

	if (data->plr.map_x * 10 < data->r1 / 2 && data->plr.map_y * 10 < data->r2 / 2)
	{
		green_x = SCALE * data->plr.mx + 11;
		green_y = SCALE * data->plr.my + 11;
		my_mlx_pixel_put(&data->img, green_x, green_y, 3342130);
	}
}
