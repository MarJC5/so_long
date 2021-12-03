/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:20:31 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 09:54:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_monster_right(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->monster->pos->z;
	next_pos = prev_pos + 1;
	next_tile = view->map->map[view->monster->pos->z + 1];
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x += TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.0.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}

void	move_monster_left(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->monster->pos->z;
	next_pos = prev_pos - 1;
	next_tile = view->map->map[view->monster->pos->z - 1];
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x -= TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.1.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}

void	move_monster_up(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->monster->pos->z;
	next_pos = prev_pos - (view->x + 1);
	next_tile = view->map->map[view->monster->pos->z - (view->x + 1)];
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x -= TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.1.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}

void	move_monster_down(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->monster->pos->z;
	next_pos = prev_pos + (view->x + 1);
	next_tile = view->map->map[view->monster->pos->z + (view->x + 1)];
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x -= TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.0.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}
