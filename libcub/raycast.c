/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:37:06 by skarry            #+#    #+#             */
/*   Updated: 2020/08/31 12:37:09 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_ray(data_cub *data, float x, float y)
{
	float c = 0;  
	float anglray;

	anglray = data->plr.dirx;
	while (c < 60) 
	{
		x = data->plr.x + c * cos(anglray);
		y = data->plr.y + c * sin(anglray);
		if (data->map[(int)y][(int)x] == '1') 
			break;
		x = SCALE * x + 11;
		y = SCALE * y + 11;
		my_mlx_pixel_put(&data->img, x, y, create_trgb(0, 50, 255, 50));
		
		c += 0.0005;
	}
}