/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:30:51 by skarry            #+#    #+#             */
/*   Updated: 2020/09/19 11:30:53 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_head(t_data_cub *data, int fd, int *pad)
{
	unsigned int	filesize;
	unsigned char	header[54];

	*pad = (4 - (data->r1 * 3) % 4) % 4;
	filesize = 54 + (*pad + (data->r1 * 3)) * data->r2;
	ft_memset(header, (unsigned char)0, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)filesize;
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)(data->r1);
	header[19] = (unsigned char)(data->r1 >> 8);
	header[20] = (unsigned char)(data->r1 >> 16);
	header[21] = (unsigned char)(data->r1 >> 24);
	header[22] = (unsigned char)(data->r2);
	header[23] = (unsigned char)(data->r2 >> 8);
	header[24] = (unsigned char)(data->r2 >> 16);
	header[25] = (unsigned char)(data->r2 >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	save(t_data_cub *data)
{
	int				fd;
	int				x;
	int				pad;
	unsigned char	bmppad[3];

	bmppad[0] = (unsigned char)0;
	bmppad[1] = (unsigned char)0;
	bmppad[2] = (unsigned char)0;
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	create_head(data, fd, &pad);
	while (--data->r2 >= 0)
	{
		x = -1;
		while (++x < data->r1)
			write(fd, &((int *)data->img.addr)[data->r2
			* data->r1 + x], 3);
		write(fd, bmppad, pad);
	}
	close(fd);
	exit(0);
}
