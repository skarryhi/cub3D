/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_on_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:47:43 by skarry            #+#    #+#             */
/*   Updated: 2020/09/03 17:47:46 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			pix_for_s_n(data_cub *data, pix *s, int y)
{
	int		x1;
	int		y1;
	float	x;

	x = data->plr.my;
	while (x > 1)
		x--;
	x1 = x * s->width;
	y1 = (s->height / 100) * (y * 100 / data->l);
	return (getpixelcolor(&*s, x1, y1));
}

int			pix_for_w_e(data_cub *data, pix *s, int y)
{
	int		x1;
	int		y1;
	float	x;

	x = data->plr.mx;
	while (x > 1)
		x--;
	x1 = x * s->width;
	y1 = (s->height / 100) * (y * 100 / data->l);
	return (getpixelcolor(&*s, x1, y1));
}

int			trgb_wall(data_cub *data, float a, int y)
{
	if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.02)] != '1' &&\
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.02)] == '1' &&\
		data->map[(int)(data->plr.my - 0.02)][(int)data->plr.mx] == '1' &&\
		data->map[(int)(data->plr.my + 0.02)][(int)data->plr.mx] == '1')
		return (pix_for_s_n(&*data, &data->txt.s, y));//blue/S create_trgb(0, 0, 128, 128)
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.02)] == '1' &&\
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.02)] == '1' &&\
		data->map[(int)(data->plr.my - 0.02)][(int)data->plr.mx] != '1' &&\
		data->map[(int)(data->plr.my + 0.02)][(int)data->plr.mx] == '1')
		return (pix_for_w_e(&*data, &data->txt.e, y));//gold create_trgb(0, 255, 215, 0)
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.02)] == '1' &&\
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.02)] != '1' &&\
		data->map[(int)(data->plr.my - 0.02)][(int)data->plr.mx] == '1' &&\
		data->map[(int)(data->plr.my + 0.02)][(int)data->plr.mx] == '1')
		return (pix_for_s_n(&*data, &data->txt.n, y));//orangem create_trgb(0, 255, 140, 0) N
	else if (data->map[(int)data->plr.my][(int)(data->plr.mx - 0.02)] == '1' &&\
		data->map[(int)data->plr.my][(int)(data->plr.mx + 0.02)] == '1' &&\
		data->map[(int)(data->plr.my - 0.02)][(int)data->plr.mx] == '1' &&\
		data->map[(int)(data->plr.my + 0.02)][(int)data->plr.mx] != '1')
		return (pix_for_w_e(&*data, &data->txt.w, y));//pink create_trgb(0, 238, 130, 238)
	else if (a < M_PI)
		return (pix_for_w_e(&*data, &data->txt.e, y));//gold
	return (pix_for_w_e(&*data, &data->txt.w, y));//pink
}