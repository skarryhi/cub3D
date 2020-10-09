/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:58:22 by skarry            #+#    #+#             */
/*   Updated: 2020/10/09 10:27:50 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			find_big_sprite2(t_pt *pt)
{
	if (pt->sp_pointer->s < pt->pointer->next->s)
	{
		pt->next = pt->pointer->next->next;
		pt->sp_pointer = record_sprite(pt->pointer->next, pt->sp_pointer);
		pt->pre_pointer = pt->pointer;
	}
	pt->pointer = pt->pointer->next;
}

void			find_big_sprite(t_data_cub *data, t_pt *pt)
{
	pt->pointer = data->plr.sp;
	pt->sp_pointer = record_sprite(pt->pointer, pt->sp_pointer);
	pt->pre_pointer = NULL;
	while (pt->pointer->next)
		find_big_sprite2(pt);
	if (pt->pre_pointer)
	{
		free(pt->pre_pointer->next);
		pt->pre_pointer->next = pt->next;
	}
	else
	{
		pt->next = data->plr.sp->next;
		free(data->plr.sp);
		data->plr.sp = pt->next;
	}
	if (pt->sp_pre_pointer)
		pt->sp_pre_pointer->next = pt->sp_pointer;
	pt->sp_pre_pointer = pt->sp_pointer;
	pt->sp_pointer = pt->sp_pointer->next;
}

void			sort_sprite(t_data_cub *data, t_pt *pt)
{
	pt->pointer = data->plr.sp;
	pt->sp_pointer = NULL;
	pt->sp_pre_pointer = NULL;
	pt->sp = record_sprite(pt->pointer, pt->sp_pointer);
	pt->sp_pointer = pt->sp;
	while (data->plr.sp->next)
		find_big_sprite(data, pt);
	pt->sp_pointer = record_sprite(data->plr.sp, pt->sp_pointer);
	free(data->plr.sp);
	if (pt->sp_pre_pointer)
		pt->sp_pre_pointer->next = pt->sp_pointer;
	else
		pt->sp = pt->sp_pointer;
	data->plr.sp = pt->sp;
}

void			put_column(t_data_cub *data, t_sprite_list *sp, int i)
{
	int				o;
	int				y;
	float			h_cout;

	y = (data->r2 / 2) + (sp->h / 2) + data->r2 / 90;
	h_cout = sp->h;
	while (h_cout > 0 && y)
	{
		o = pix_for_sp(&data->txt.sp, (h_cout-- * 100 / sp->h),\
			(i - sp->i_start) * 100 / sp->h);
		if (o != 0x00fffb)
			my_mlx_pixel_put(&data->img, i, y, o);
		y--;
	}
}

void			put_sprite(t_data_cub *data)
{
	int				i;
	t_sprite_list	*sp;

	sp = data->plr.sp;
	while (sp)
	{
		i = sp->i_start;
		if (i < 0)
			i = 0;
		while (i < sp->i_end && i < data->r1)
		{
			if (data->plr.dis[i] > sp->s)
				put_column(data, sp, i);
			i++;
		}
		sp = sp->next;
	}
}
