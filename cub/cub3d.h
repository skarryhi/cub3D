/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:52:18 by skarry            #+#    #+#             */
/*   Updated: 2020/08/05 15:52:20 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>

# define SCALE 10

typedef struct  s_pix 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				pix;

typedef struct	s_colour
{
	int			r;
	int			g;
	int			b;
}				colour;

typedef struct		sp_list
{
	int				x;
	int				y;
	float			h;
	float			w;
	float			s;
	struct sp_list	*next;
}					sprite_list;

typedef struct	s_player
{
	float		x;
	float		y;
	float		dirx;
	float		mx;
	float		my;
	sprite_list	*sp;
}				player;

typedef struct	s_text
{
	pix			n;
	pix			s;
	pix			w;
	pix			e;
	pix			sp;
}				txt;

typedef struct		s_cub
{
	int				r1;
	int				r2;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	struct s_colour	f;
	struct s_colour	c;
	char			**map;
	player			plr;
	void			*mlx;
	void			*win;
	pix				img;
	txt				txt;
	float			l;
}					data_cub;


t_list		*map_to_lst(const char *s);
int			map_lst_to_mas(t_list *z_map, char ***map);
void		ft_exit(char *s);
void		check_errno();
int			check_empty_s(char *s);
int			findmap(char *s);
int			r_type(char *s, int *r1, int *r2);
int			colour_type(char *s, colour *l);
void		check_all_sim(char **m, int y, int x);
void		check_one_plr(data_cub *data, int y, int x);
void		map_mas_to_stuct(char **map, data_cub *data, int y);
int			map_type(char **s, int y, data_cub *data);
int			cardinal_type(char *s, data_cub *data);
void		data_init(data_cub *data);
void 		check_ex_str(char **s, char *s2);
void		check_valid_map(data_cub *data);
void		data_check(data_cub data);
int			create_trgb(int t, int r, int g, int b);
int			ft_key(int keycode, data_cub *data);
void		put_map(data_cub *data, pix *img);
void		all_paint(data_cub *data, pix *img, void *mlx);
void		put_ray(data_cub *data, int i, float c);
void		my_mlx_pixel_put(pix *data, int x, int y, int color);
int			trgb_wall(data_cub *data, float a, int y);
int			getpixelcolor(pix *img, int x, int y);
void		get_all_texture(data_cub *data, void *mlx, txt *txt);
int			ft_key_exit(void);
void		return_ray(data_cub *data, float c, int i, float a);
void		new_sprite(data_cub *data);

#endif
