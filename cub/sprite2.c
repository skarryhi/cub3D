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

void		create_lst(t_data_cub *data, t_sprite_list *counter)
{
	t_sprite_list	*sp;

	sp = (t_sprite_list *)malloc(sizeof(t_sprite_list));
	sp->w = 0;
	sp->x = data->plr.mx;
	sp->y = data->plr.my;
	sp->s = sqrt(pow(data->plr.x - sp->x, 2) + pow(data->plr.y - sp->y, 2));
	if (sp->s < 1)
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
