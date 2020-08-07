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

#ifndef LIBCUB_H
# define LIBCUB_H

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>

t_list      *ft_setmap(const char *s);
int        ft_lstsplit(t_list *z_map, char ***map);

#endif
