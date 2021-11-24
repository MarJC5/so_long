/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:35:22 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 17:30:32 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_player_pos(t_view *view)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (view->y > ++y)
	{
		while ((view->map->map)[++i] && view->x > ++x)
		{
			if ((view->map->map)[i] == 'P')
			{
				view->player->pos->x = x * TILE_SIZE;
				view->player->pos->y = y * TILE_SIZE;
				view->player->pos->z = i;
			}
		}
		x = -1;
	}
	return (1);
}
