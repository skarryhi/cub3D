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

int			finder_lst(data_cub data, int y, int x, char c)
{
	sprite_list	*counter;

	counter = data.plr.sp;
	while (counter)
	{
		if (counter->x == x && counter->y == y)
		{
			// printf("[%d%d]%f", counter->x, counter->y, counter->w);
			if ( c == 'h')
				return (counter->h);
			if ( c == 'w')
				return (counter->w);
		}
		else
			counter = counter->next;
	}
	return (0);
}

void		plus_w(data_cub *data, int y, int x)
{
	sprite_list	*counter;

	counter = data->plr.sp;
	while (counter)
	{
		if (counter->x == x && counter->y == y)
		{
			counter->w++;
			return ;
		}
		else
			counter = counter->next;
	}

}

void		new_sprite(data_cub *data)
{
	sprite_list	*sp;
	sprite_list	*counter;

	counter = data->plr.sp;
	while (counter)
	{
		if (counter->x == (int)data->plr.mx && counter->y == (int)data->plr.my)
		{
			// printf("[%d%d]%f", counter->x, counter->y, counter->w);
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

void		put_sprite(data_cub *data, int i, int l_y, int l_x)
{
	int		o;
	int		y;
	int		h;
	float	h_cout;

	h = finder_lst(*data, l_y, l_x, 'h');
	if (finder_lst(*data, l_y, l_x, 'w') < h)
	{
		plus_w(&*data, l_y, l_x);
		y = (data->r2 / 2) + (h / 2);
		h_cout = h;
		while (h_cout > 0)
		{
			o = pix_for_sp(&data->txt.sp, (h_cout * 100 / h),\
				(finder_lst(*data, l_y, l_x, 'w') * 100 / h));
			if (o != 0x00fffb)
				my_mlx_pixel_put(&data->img, i, y, o);
			y--;
			h -= 0;
			h_cout--;
		}
	}
}

void		return_ray(data_cub *data, float c, int i, float a)
{
	float	dist_fr_wall;
	float	depth;

	dist_fr_wall = c;
	depth = 0.01;
	while (data->plr.count_sp > 0)
	{
		data->plr.mx = data->plr.x + dist_fr_wall * cos(a);
		data->plr.my = data->plr.y + dist_fr_wall * sin(a);
		if (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
		{
			data->plr.count_sp--;
			// if ((int)data->plr.my != (int)data->plr.y && (int)data->plr.mx != (int)data->plr.x)
				put_sprite(&*data, i, (int)data->plr.my, (int)data->plr.mx);
			while (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
			{
				data->plr.mx = data->plr.x + dist_fr_wall * cos(a);
				data->plr.my = data->plr.y + dist_fr_wall * sin(a);
				dist_fr_wall -= 0.01;
				depth += 0.01;
			}
			i += 0;
		}
		dist_fr_wall -= 0.01;
	}
}