/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:46:35 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/22 00:05:02 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_pos(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}
