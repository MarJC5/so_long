/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:46:35 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/26 14:36:24 by jmartin          ###   ########.fr       */
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

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	init_struct(t_view *view)
{
	view->map = malloc(sizeof(t_map));
	view->map->coin = malloc(sizeof(t_coin));
	view->player = malloc(sizeof(t_player));
	view->player->pos = malloc(sizeof(t_pos));
	view->player->steps = 0;
	view->player->coins = 0;
}

void	free_view_struct(t_view *view)
{
	free(view->map);
	view->map = NULL;
	free(view->map->coin);
	view->map->map = NULL;
	free(view->player);
	view->player = NULL;
	free(view->player->pos);
	view->player->pos = NULL;
	free(view);
	view = NULL;
}
