
#include "cub3d.h"

int             ft_key(int keycode, data_cub *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	//A
	if (keycode == 0)
	{
		if (data->map[(int)data->plr.y][(int)(data->plr.x - 1)] != '1')
			data->plr.x -= 1;
		
		put_map(*data, &data->img);
	}
	//d
	if (keycode == 2)
	{
		if (data->map[(int)data->plr.y][(int)(data->plr.x + 1)] != '1')
		data->plr.x += 1;
		put_map(*data, &data->img);
	}
	//w
	if (keycode == 13)
	{
		if (data->map[(int)data->plr.y - 1][(int)(data->plr.x)] != '1')
		data->plr.y -= 1;
		put_map(*data, &data->img);
	}
	//s
	if (keycode == 1)
	{
		if (data->map[(int)data->plr.y + 1][(int)(data->plr.x)] != '1')
		data->plr.y += 1;
		put_map(*data, &data->img);
	}
	printf("%d\n", keycode);
	return (0);
}
