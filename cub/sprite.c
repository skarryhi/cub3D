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

int			finder_lst(t_data_cub data, int y, int x, char c)
{
	t_sprite_list	*counter;

	counter = data.plr.sp;
	while (counter)
	{
		if (counter->x == x && counter->y == y)
		{
			if (c == 'h')
				return (counter->h);
			if (c == 'w')
				return (counter->w);
		}
		else
			counter = counter->next;
	}
	return (0);
}

void		plus_w(t_data_cub *data, int y, int x, int z)
{
	t_sprite_list	*counter;

	counter = data->plr.sp;
	while (counter)
	{
		if (counter->x == x && counter->y == y)
		{
			counter->w = counter->w + 1 + z;
			return ;
		}
		else
			counter = counter->next;
	}
}

void		new_sprite(t_data_cub *data)
{
	t_sprite_list	*counter;

	counter = data->plr.sp;
	if ((sqrt(pow(data->plr.x - data->plr.mx, 2) + \
			pow(data->plr.y - data->plr.my, 2))) < 0.5)
		return ;
	while (counter)
	{
		if (counter->x == (int)data->plr.mx && counter->y == (int)data->plr.my)
			return ;
		if (counter->next == NULL)
			break ;
		counter = counter->next;
	}
	create_lst(&*data, counter);
}

void		put_sprite(t_data_cub *data, int i, int l_y, int l_x)
{
	int		o;
	int		y;
	int		h;
	float	h_cout;

	h = finder_lst(*data, l_y, l_x, 'h');
	if (finder_lst(*data, l_y, l_x, 'w') < h)
	{
		if (i == 0)
			plus_w(&*data, l_y, l_x, finder_lst(*data, l_y, l_x, 'h') / 2);
		else
			plus_w(&*data, l_y, l_x, 0);
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

void		return_ray(t_data_cub *data, float c, int i, float a)
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
			while (data->map[(int)data->plr.my][(int)data->plr.mx] == '2')
			{
				data->plr.mx = data->plr.x + dist_fr_wall * cos(a);
				data->plr.my = data->plr.y + dist_fr_wall * sin(a);
				dist_fr_wall -= 0.01;
				depth += 0.01;
			}
			put_sprite(&*data, i, (int)(data->plr.y + (dist_fr_wall + 0.8)\
				* sin(a)), (int)(data->plr.x + (dist_fr_wall + 0.8) * cos(a)));
		}
		dist_fr_wall -= 0.01;
	}
}
