/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:29:56 by skarry            #+#    #+#             */
/*   Updated: 2020/08/16 14:29:59 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *s)
{
	if (s)
	{
		ft_putstr_fd(s, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(0);
}

void	check_errno(void)
{
	if (errno != 0)
	{
		perror("Program stopped");
		exit(errno);
	}
}

int		ft_key_exit(void)
{
	exit(0);
	return (0);
}
