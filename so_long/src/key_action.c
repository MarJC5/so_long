/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:15 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/25 07:54:26 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc_win(int key, t_view *view)
{
	free(view);
	exit(0);
	return (key);
}

int	key_right_event(int key, int swap_pos, t_view *view)
{
	(void) key;
	int next_pos;

	next_pos = view->map->map[view->player->pos->z + 1];
	if ( next_pos != '1' && next_pos != 'E')
	{
		view->map->map[view->player->pos->z] = view->map->map[view->player->pos->z + 1];
		view->map->map[view->player->pos->z + 1] = swap_pos;
		view->player->pos->x += TILE_SIZE;
		set_player_pos(view);
	}
	is_coins_taken(view->player->pos->z - 1, view);
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	return (swap_pos);
}

int	key_left_event(int key, int swap_pos, t_view *view)
{
	(void) key;
	int next_pos;

	next_pos = view->map->map[view->player->pos->z - 1];
	if ( next_pos != '1' && next_pos != 'E')
	{
		view->map->map[view->player->pos->z] = view->map->map[view->player->pos->z - 1];
		view->map->map[view->player->pos->z - 1] = swap_pos;
		view->player->pos->x -= TILE_SIZE;
		set_player_pos(view);
	}
	is_coins_taken(view->player->pos->z + 1, view);
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	return (swap_pos);
}

int	key_up_event(int key, int swap_pos, t_view *view)
{
	(void) key;
	int next_pos;

	next_pos = view->map->map[view->player->pos->z - (view->x + 1)];
	if (next_pos != '1' && next_pos != 'E')
	{
		view->map->map[view->player->pos->z] = view->map->map[view->player->pos->z - (view->x + 1)];
		view->map->map[view->player->pos->z - (view->x + 1)] = swap_pos;
		view->player->pos->y -= TILE_SIZE;
		set_player_pos(view);
	}
	is_coins_taken(view->player->pos->z + (view->x + 1), view);
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	return (swap_pos);
}

int	key_down_event(int key, int swap_pos, t_view *view)
{
	(void) key;
	int next_pos;

	next_pos = view->map->map[view->player->pos->z + (view->x + 1)];
	if ( next_pos != '1' && next_pos != 'E')
	{
		view->map->map[view->player->pos->z] = view->map->map[view->player->pos->z + (view->x + 1)];
		view->map->map[view->player->pos->z + (view->x + 1)] = swap_pos;
		view->player->pos->y += TILE_SIZE;
		set_player_pos(view);
	}
	is_coins_taken(view->player->pos->z - (view->x + 1), view);
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	return (swap_pos);
}
