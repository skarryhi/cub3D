/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:58:22 by skarry            #+#    #+#             */
/*   Updated: 2020/10/08 17:44:48 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_list	*finder_lst(t_data_cub data, int y, int x)
{
	t_sprite_list	*pointer;

	pointer = data.plr.sp;
	while (pointer)
	{
		if (pointer->x == x && pointer->y == y)
			return (pointer);
		pointer = pointer->next;
	}
	return (0);
}

t_sprite_list		*record_sprite(t_sprite_list *sp, t_sprite_list *sp2)
{
	t_sprite_list	*sp3;

	if (!sp2)
		{
			if (!(sp3 = (t_sprite_list *)malloc(sizeof(t_sprite_list))))
			ft_exit("Error of malloc");
		}
	else
		sp3 = sp2;
	sp3->x = sp->x;
	sp3->y = sp->y;
	sp3->h = sp->h;
	sp3->s = sp->s;
	sp3->w = sp->w;
	sp3->i_start = sp->i_start;
	sp3->i_mid = sp->i_mid;
	sp3->i_middle = sp->i_middle;
	sp3->i_end = sp->i_end;
	sp3->next = NULL;
	return (sp3);
}

void		sort_sprite(t_data_cub *data)
{
	t_sprite_list	*sp;
	t_sprite_list	*sp_pointer;
	t_sprite_list	*sp_pre_pointer;
	t_sprite_list	*pointer;
	t_sprite_list	*pre_pointer;
	void			*next;

	pointer = data->plr.sp;
	sp_pointer = NULL;
	sp_pre_pointer = NULL;
	sp = record_sprite(pointer, sp_pointer);
	sp_pointer = sp;
	while (data->plr.sp->next)
	{
		pointer = data->plr.sp;
		sp_pointer = record_sprite(pointer, sp_pointer);
		pre_pointer = NULL;
		while (pointer->next)
		{
			if (sp_pointer->s < pointer->next->s)
			{
				next = pointer->next->next;
				sp_pointer = record_sprite(pointer->next, sp_pointer);
				pre_pointer = pointer;
			}
			pointer = pointer->next;
		}
		if (pre_pointer)
		{
			free(pre_pointer->next);
			pre_pointer->next = next;
		}
		else 
		{
			next = data->plr.sp->next;
			free(data->plr.sp);
			data->plr.sp = next;
		}
		if (sp_pre_pointer)
			sp_pre_pointer->next = sp_pointer;
		sp_pre_pointer = sp_pointer;
		sp_pointer = sp_pointer->next;
	}
	sp_pointer = record_sprite(data->plr.sp, sp_pointer);
	free(data->plr.sp);
	if(sp_pre_pointer)
		sp_pre_pointer->next = sp_pointer;
	else
		sp = sp_pointer;
	data->plr.sp = sp;
}

void		new_sprite(t_data_cub *data, double a, int i)
{
	t_sprite_list	*pointer;

	pointer = data->plr.sp;
	if ((sqrt(pow(data->plr.x - 0.5 - (int)data->plr.mx, 2) + \
			pow(data->plr.y - 0.5 - (int)data->plr.my, 2))) < 1.3)
		return ;
	while (pointer)
	{
		if (pointer->x == (int)data->plr.mx && pointer->y == (int)data->plr.my)
			return ;
		if (pointer->next == NULL)
			break ;
		pointer = pointer->next;
	}
	create_lst(&*data, pointer, a, i);
}

void		put_sprite(t_data_cub *data)
{
	int		o;
	int		y;
	int		i;
	float	h_cout;
	t_sprite_list	*sp;

	sp = data->plr.sp;
	while (sp)
	{
		// printf("[%f]\n", sp->s);
		i = sp->i_start;
		if (i < 0)
			i = 0;
		while (i < sp->i_end && i < data->r1)
		{
			if (data->plr.dis[i] > sp->s)
			{
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
			i++;
		}
		sp = sp->next;
	}
}
