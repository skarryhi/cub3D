/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:45:15 by skarry            #+#    #+#             */
/*   Updated: 2020/09/18 10:45:18 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		create_lst(t_data_cub *data, t_sprite_list *counter, int left)
{
	t_sprite_list	*sp;

	if (!(sp = (t_sprite_list *)malloc(sizeof(t_sprite_list))))
		ft_exit("Error of malloc");
	if (!left)
	{
		sp->left = 1;
		sp->i_end = 0;
	}
	else
		sp->left = 0;
	sp->w = 0;
	sp->x = data->plr.mx;
	sp->y = data->plr.my;
	sp->s = sqrt(pow(data->plr.x - 0.5 - (int)sp->x, 2) + pow(data->plr.y - 0.5 - (int)sp->y, 2));
	if (sp->s < 0.8)
		sp->h = (data->r2);
	else
		sp->h = (data->r2) / sp->s;
	sp->next = NULL;
	if (data->plr.sp == NULL)
		data->plr.sp = sp;
	else
		counter->next = sp;
}

void		cleaning_lst(t_data_cub *data)
{
	void	*nxt;

	while (data->plr.sp)
	{
		nxt = data->plr.sp->next;
		free(data->plr.sp);
		data->plr.sp = nxt;
	}
}

int			pix_for_sp(t_pix *s, float h, float w)
{
	int		x1;
	int		y1;

	x1 = s->width / 100 * w;
	y1 = s->height / 100 * h;
	return (getpixelcolor(&*s, x1, y1));
}

void		print_zerro_sp(t_sprite_list *counter, t_data_cub *data)
{
	int		o;
	int		y;
	float	h_cout;

	while (counter->i >= 0)
	{
		y = (data->r2 / 2) + (counter->h / 2);
		h_cout = counter->h;
		while (h_cout > 0)
		{
			printf("[%d|%f]", counter->i, counter->w);
			o = pix_for_sp(&data->txt.sp, (h_cout * 100 / counter->h),\
				(counter->i) * 100 / counter->h);
			// if (o != 0x00fffb)
			// 	my_mlx_pixel_put(&data->img, counter->i, y, o);
			y--;
			h_cout--;
		}
		counter->i--;
	}
}

void		put_zerro_sp(t_data_cub *data)
{
	t_sprite_list	*counter;

	counter = data->plr.sp;
	while (counter)
	{
		if (counter->left == 1)
		{
			print_zerro_sp(counter, &*data);
			// write(1, "tut\n", 4);
		}
		counter = counter->next;
	}
}