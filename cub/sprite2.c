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

void		cleaning_lst(data_cub *data)
{
	void	*nxt;

	while (data->plr.sp)
	{
		nxt = data->plr.sp->next;
		free (data->plr.sp);
		data->plr.sp = nxt;
	}
}

int			pix_for_sp(pix *s, float h, float w)
{
	int		x1;
	int		y1;

	x1 = s->width / 100 * w;
	y1 = s->height / 100 * h;
	return (getpixelcolor(&*s, x1, y1));
}