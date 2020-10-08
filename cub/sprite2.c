/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:45:15 by skarry            #+#    #+#             */
/*   Updated: 2020/10/08 19:44:10 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		create_lst(t_data_cub *data, t_sprite_list *counter, double a, int i)
{
	t_sprite_list	*sp;

	if (!(sp = (t_sprite_list *)malloc(sizeof(t_sprite_list))))
		ft_exit("Error of malloc");
	sp->x = data->plr.mx;
	sp->y = data->plr.my;
	sp->s = sqrt(pow(data->plr.x - 0.5 - (int)sp->x, 2) +
			pow(data->plr.y - 0.5 - (int)sp->y, 2));
	sp->h = data->r2 / sp->s;
	sp->i_mid = atan2((int)(data->plr.my) + 0.5 - data->plr.y, (int)(data->plr.mx) + 0.5 - data->plr.x);
	a = trgb_def_wall(a);
		sp->i_mid = trgb_def_wall(sp->i_mid);
	sp->i_middle = i - (a - sp->i_mid) / (M_PI / (3 * data->r1));
	sp->i_start = sp->i_middle - sp->h / 2;
	sp->i_end = sp->i_middle + sp->h / 2;
	// printf("%d[%d]%d a:%f mid:%f i:%d fabs:%f\n", sp->i_start,\
	// sp->i_middle, sp->i_end, a, sp->i_mid,i, a - sp->i_mid);
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
