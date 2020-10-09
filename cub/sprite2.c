/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:45:15 by skarry            #+#    #+#             */
/*   Updated: 2020/10/09 11:19:00 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			new_sprite(t_data_cub *data, float a, int i)
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

void			create_lst(t_data_cub *data,
								t_sprite_list *counter, float a, int i)
{
	t_sprite_list	*sp;

	if (!(sp = (t_sprite_list *)malloc(sizeof(t_sprite_list))))
		ft_exit("Error of malloc");
	sp->x = data->plr.mx;
	sp->y = data->plr.my;
	sp->s = sqrt(pow(data->plr.x - 0.5 - (int)sp->x, 2) +
			pow(data->plr.y - 0.5 - (int)sp->y, 2));
	sp->h = data->r2 / sp->s;
	sp->i_mid = atan2((int)(data->plr.my) + 0.5 - data->plr.y,
								(int)(data->plr.mx) + 0.5 - data->plr.x);
	a = trgb_def_wall(a);
	sp->i_mid = trgb_def_wall(sp->i_mid);
	if (fabs(a - sp->i_mid) > 2)
		a = a - (2 * M_PI);
	sp->i_middle = i - (a - sp->i_mid) / (M_PI / (3 * data->r1));
	sp->i_start = sp->i_middle - sp->h / 2;
	sp->i_end = sp->i_middle + sp->h / 2;
	sp->next = NULL;
	if (data->plr.sp == NULL)
		data->plr.sp = sp;
	else
		counter->next = sp;
}

void			cleaning_lst(t_data_cub *data)
{
	void	*nxt;

	while (data->plr.sp)
	{
		nxt = data->plr.sp->next;
		free(data->plr.sp);
		data->plr.sp = nxt;
	}
	if (data->plr.dis)
		free(data->plr.dis);
}

t_sprite_list	*record_sprite(t_sprite_list *sp, t_sprite_list *sp2)
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

int				pix_for_sp(t_pix *s, float h, float w)
{
	int		x1;
	int		y1;

	x1 = s->width / 100 * w;
	y1 = s->height / 100 * h;
	return (getpixelcolor(&*s, x1, y1));
}
