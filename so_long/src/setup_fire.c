/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:05 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/29 16:15:40 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_fire_event(t_view *view)
{
	int		p_pos;
	char	*map;

	p_pos = view->player->pos->z;
	map = view->map->map;
	if (map[p_pos - 1] == 'M' || map[p_pos - 2] == 'M')
	{
		init_tile("./img/xpm/player/combat/F.1.xpm",
			view->player->pos->x, view->player->pos->y, view);
		kill_monster_pos(view);
	}
	else if (map[p_pos + 1] == 'M' || map[p_pos + 2] == 'M')
	{
		init_tile("./img/xpm/player/combat/F.0.xpm",
			view->player->pos->x, view->player->pos->y, view);
		kill_monster_pos(view);
	}
	else
		init_tile("./img/xpm/player/combat/F.2.xpm",
			view->player->pos->x, view->player->pos->y, view);
}
