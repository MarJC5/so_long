/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:46:35 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 09:51:21 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_pos(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_strrchr_pos(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
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
	view->monster = malloc(sizeof(t_monster));
	view->monster->pos = malloc(sizeof(t_monster));
	view->monster->pos->z = 0;
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
	free(view->monster);
	view->monster = NULL;
	free(view->monster->pos);
	view->monster->pos = NULL;
	free(view);
	view = NULL;
}
