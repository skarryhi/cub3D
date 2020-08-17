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

typedef struct	s_colour
{
	int	r;
	int	g;
	int	b;
}				colour;


typedef struct	s_cub
{
	int				r1;
	int				r2;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	struct s_colour		f;
	struct s_colour		c;
	char			**map;
}				data_cub;


t_list		*map_to_lst(const char *s);
int			map_lst_to_mas(t_list *z_map, char ***map);
void		ft_exit(char *s);
void		check_errno();
int			check_empty_s(char *s);
int			findmap(char *s);
int			r_type(char *s, int *r1, int *r2);
int			colour_type(char *s, colour *l);
void		map_mas_to_stuct(char **map, data_cub *data, int y);
int			map_type(char **s, int y, data_cub *data);
int			cardinal_type(char *s, data_cub *data);
void		data_init(data_cub *data);
void 		check_ex_str(char **s, char *s2);
void		check_valid_map(char **m);
void		data_check(data_cub data);

#endif
