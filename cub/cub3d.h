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

typedef struct			s_pix
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_pix;

typedef struct			s_colour
{
	int					r;
	int					g;
	int					b;
}						t_colour;

typedef struct			s_sp_list
{
	int					x;
	int					y;
	int					i;
	int					i2;
	float				h;
	float				w;
	float				s;
	struct s_sp_list	*next;
}						t_sprite_list;

typedef struct			s_player
{
	float				x;
	float				y;
	float				dirx;
	float				mx;
	float				my;
	int					count_sp;
	t_sprite_list		*sp;
}						t_player;

typedef struct			s_text
{
	t_pix				n;
	t_pix				s;
	t_pix				w;
	t_pix				e;
	t_pix				sp;
}						t_txt;

typedef struct			s_cub
{
	int					r1;
	int					r2;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	struct s_colour		f;
	struct s_colour		c;
	char				**map;
	t_player			plr;
	void				*mlx;
	void				*win;
	t_pix				img;
	t_txt				txt;
	float				l;
}						t_data_cub;

t_list					*map_to_lst(const char *s);
int						map_lst_to_mas(t_list *z_map, char ***map);
void					ft_exit(char *s);
void					check_errno();
int						check_empty_s(char *s);
int						findmap(char *s);
int						r_type(char *s, int *r1, int *r2);
int						colour_type(char *s, t_colour *l);
void					check_all_sim(char **m, int y, int x);
void					check_one_plr(t_data_cub *data, int y, int x);
void					map_mas_to_stuct(char **map, t_data_cub *data, int y);
int						map_type(char **s, int y, t_data_cub *data);
int						cardinal_type(char *s, t_data_cub *data);
void					data_init(t_data_cub *data);
void					check_ex_str(char **s, char *s2);
void					check_valid_map(t_data_cub *data);
void					data_check(t_data_cub data);
int						create_trgb(int t, int r, int g, int b);
int						ft_key(int keycode, t_data_cub *data);
void					put_map(t_data_cub *data, t_pix *img);
void					all_paint(t_data_cub *data, t_pix *img, void *mlx);
void					put_ray(t_data_cub *data, int i, float c);
void					my_mlx_pixel_put(t_pix *data, int x, int y, int color);
int						trgb_wall(t_data_cub *data, float a, int y);
int						getpixelcolor(t_pix *img, int x, int y);
void					get_all_texture(t_data_cub *data,\
										void *mlx, t_txt *txt);
void					get_one_texture(void *mlx, t_pix *n, char *no);
int						ft_key_exit(void);
void					return_ray(t_data_cub *data, float c, int i, float a);
void					new_sprite(t_data_cub *data);
void					cleaning_lst(t_data_cub *data);
int						pix_for_sp(t_pix *s, float h, float w);
void					create_lst(t_data_cub *data, t_sprite_list *counter);
void					green_ray(t_data_cub *data);

#endif
