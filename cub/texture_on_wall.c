/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_on_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:47:43 by skarry            #+#    #+#             */
/*   Updated: 2020/10/13 11:08:34 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			pix_for_w_e(t_data_cub *data, t_pix *s, float y, char c)
{
	int		x1;
	int		y1;
	float	x;

	x = data->plr.my;
	while (x > 1)
		x--;
	if (c == 'w')
	{
		x = 1 - x;
	}
	x1 = x * s->width;
	y1 = (s->height / 100) * (y * 100 / data->l);
	return (getpixelcolor(&*s, x1, y1));
}

int			pix_for_s_n(t_data_cub *data, t_pix *s, float y, char c)
{
	int		x1;
	int		y1;
	float	x;

	x = data->plr.mx;
	while (x > 1)
		x--;
	if (c == 'n')
		x = 1 - x;
	x1 = x * s->width;
	y1 = (s->height / 100) * (y * 100 / data->l);
	return (getpixelcolor(&*s, x1, y1));
}

int			trgb_wall(t_data_cub *data, float y)
{
	if (data->map[(int)data->plr.my][(int)(data->plr.mx + 0.005)] == '1' &&
		data->map[(int)(data->plr.my - 0.005)][(int)data->plr.mx] == '1' &&
		data->map[(int)(data->plr.my + 0.005)][(int)data->plr.mx] == '1')
		return (pix_for_w_e(&*data, &data->txt.w, y, 'w'));
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.005)] == '1' &&
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.005)] == '1'&&
		data->map[(int)(data->plr.my + 0.005)][(int)data->plr.mx] == '1')
		return (pix_for_s_n(&*data, &data->txt.s, y, 's'));
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.005)] == '1'&&
		data->map[(int)(data->plr.my - 0.005)][(int)data->plr.mx] == '1' &&
		data->map[(int)(data->plr.my + 0.005)][(int)data->plr.mx] == '1')
		return (pix_for_w_e(&*data, &data->txt.e, y, 'e'));
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.005)] == '1' &&
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.005)] == '1' &&
		data->map[(int)(data->plr.my - 0.005)][(int)data->plr.mx] == '1')
		return (pix_for_s_n(&*data, &data->txt.n, y, 'n'));
	return (pix_for_s_n(&*data, &data->txt.n, y, 's'));
}
