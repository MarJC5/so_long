/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:15 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/25 10:17:30 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc_win(int key, t_view *view)
{
	free(view);
	exit(0);
	return (key);
}

int	key_right_event(int swap_pos, t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos + 1;
	next_tile = view->map->map[view->player->pos->z + 1];
	if (next_tile != '1' && next_tile != 'E')
	{
		view->map->map[prev_pos] = view->map->map[next_pos];
		view->map->map[next_pos] = swap_pos;
		view->player->pos->x += TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	is_coins_taken(prev_pos - 1, next_tile,
		"./img/xpm/player/walk-right/P.1.1.xpm", view);
	return (swap_pos);
}

int	key_left_event(int swap_pos, t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos - 1;
	next_tile = view->map->map[view->player->pos->z - 1];
	if (next_tile != '1' && next_tile != 'E')
	{
		view->map->map[prev_pos] = view->map->map[next_pos];
		view->map->map[next_pos] = swap_pos;
		view->player->pos->x -= TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	is_coins_taken(prev_pos + 1, next_tile,
		"./img/xpm/player/walk-left/P.1.1.xpm", view);
	return (swap_pos);
}

int	key_up_event(int swap_pos, t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos - (view->x + 1);
	next_tile = view->map->map[view->player->pos->z - (view->x + 1)];
	if (next_tile != '1' && next_tile != 'E')
	{
		view->map->map[prev_pos] = view->map->map[next_pos];
		view->map->map[next_pos] = swap_pos;
		view->player->pos->y -= TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	is_coins_taken(prev_pos + (view->x + 1), next_tile,
		"./img/xpm/player/walk-left/P.1.1.xpm", view);
	return (swap_pos);
}

int	key_down_event(int swap_pos, t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos + (view->x + 1);
	next_tile = view->map->map[view->player->pos->z + (view->x + 1)];
	if (next_tile != '1' && next_tile != 'E')
	{
		view->map->map[prev_pos] = view->map->map[next_pos];
		view->map->map[next_pos] = swap_pos;
		view->player->pos->y += TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	is_coins_taken(prev_pos - (view->x + 1), next_tile,
		"./img/xpm/player/walk-right/P.1.1.xpm", view);
	return (swap_pos);
}
