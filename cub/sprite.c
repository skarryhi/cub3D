/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:58:22 by skarry            #+#    #+#             */
/*   Updated: 2020/09/09 15:58:28 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		new_sprite(data_cub *data)
{
	sprite_list	*sp;
	sprite_list	*counter;

	counter = data->plr.sp;
	while (counter)
	{
		if (counter->x == (int)data->plr.mx && counter->y == (int)data->plr.my)
		{
			if (counter->w < counter->h)
				counter->w++;
			printf("[%d%d]%f", counter->x, counter->y, counter->w);
			return ;
		}
		if (counter->next == NULL)
			break ;
		counter = counter->next;
	}
	sp = (sprite_list *)malloc(sizeof(sprite_list));
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

// void		put_sprite(data_cub *data, int i, float c, float a)
// {
// 	int		o;
// 	int		y;
// 	int		h;
// 	float	l_cout;

// 	if ((c * cos(a - data->plr.dirx)) < 1)
// 		data->l = (data->r2);
// 	else
// 		data->l = (data->r2) / (c * cos(a - data->plr.dirx));
// 	y = (data->r2 / 2) + (data->l / 2);
// 	l_cout = data->l;
// 	h = data->l;
// 	while (l_cout > 0)
// 	{
// 		o = 3342130;//sprite_wall(&*data, h);
// 		my_mlx_pixel_put(&data->img, i, y, o);
// 		y--;
// 		h--;
// 		l_cout--;
// 	}
// }

// void		return_ray(data_cub *data, float c, int i, float a)
// {
// 	float	dist_fr_wall;
// 	float	depth;
// 	float	place;

// 	dist_fr_wall = c;
// 	depth = 0.01;
// 	while (data->plr.count_sp > 0)
// 	{
// 		data->plr.mx = data->plr.x + dist_fr_wall * cos(a);
// 		data->plr.my = data->plr.y + dist_fr_wall * sin(a);
// 		if (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
// 		{
// 			data->plr.count_sp--;
// 			place = sqrt(pow(data->plr.x - (int)(data->plr.mx), 2) +\
// 					pow(data->plr.y - (int)(data->plr.my), 2));
// 			put_sprite(&*data, i, place, a);
// 			while (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
// 			{
// 				data->plr.mx = data->plr.x + dist_fr_wall * cos(a);
// 				data->plr.my = data->plr.y + dist_fr_wall * sin(a);
// 				dist_fr_wall -= 0.01;
// 				depth += 0.01;
// 			}
// 			i++;
// 		}
// 		dist_fr_wall -= 0.01;
// 	}
// }