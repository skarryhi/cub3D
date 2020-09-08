
#include "cub3d.h"

int		ft_key(int keycode, data_cub *data)
{
	float	step = 0.5;

	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 123)
	{
		data->plr.x = data->plr.x + step * cos(data->plr.dirx - M_PI / 2);
		data->plr.y = data->plr.y + step * sin(data->plr.dirx - M_PI / 2);
		if (data->map[(int)data->plr.y][(int)data->plr.x] == '1')
		{
			data->plr.x = data->plr.x - step * cos(data->plr.dirx - M_PI / 2);
			data->plr.y = data->plr.y - step * sin(data->plr.dirx - M_PI / 2);
		}
		put_map(&*data, &data->img);
	}
	if (keycode == 124)
	{
		data->plr.x = data->plr.x + step * cos(data->plr.dirx + M_PI / 2);
		data->plr.y = data->plr.y + step * sin(data->plr.dirx + M_PI / 2);
		if (data->map[(int)data->plr.y][(int)data->plr.x] == '1')
		{
			data->plr.x = data->plr.x - step * cos(data->plr.dirx + M_PI / 2);
			data->plr.y = data->plr.y - step * sin(data->plr.dirx + M_PI / 2);
		}
		put_map(&*data, &data->img);
	}
	if (keycode == 13)
	{
		data->plr.x = data->plr.x + step * cos(data->plr.dirx);
		data->plr.y = data->plr.y + step * sin(data->plr.dirx);
		if (data->map[(int)data->plr.y][(int)data->plr.x] == '1')
		{
			data->plr.x = data->plr.x - step * cos(data->plr.dirx);
			data->plr.y = data->plr.y - step * sin(data->plr.dirx);
		}
		put_map(&*data, &data->img);
	}
	if (keycode == 1)
	{
		data->plr.x = data->plr.x - step * cos(data->plr.dirx);
		data->plr.y = data->plr.y - step * sin(data->plr.dirx);
		if (data->map[(int)data->plr.y][(int)data->plr.x] == '1')
		{
			data->plr.x = data->plr.x + step * cos(data->plr.dirx);
			data->plr.y = data->plr.y + step * sin(data->plr.dirx);
		}
		put_map(&*data, &data->img);
	}
	if (keycode == 2)
		data->plr.dirx += M_PI / 16;
	if (keycode == 0)
		data->plr.dirx -= M_PI / 16;
	put_map(&*data, &data->img);
	printf("%d\n", keycode);
	return (0);
}
