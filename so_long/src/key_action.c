/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:15 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/29 17:24:22 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_monster(t_view *view, int next_tile)
{
	if (next_tile == 'M')
	{
		printf("\n\033[1;31mYou got eaten by a snake!\033[0m\n\n");
		esc_win(view);
	}
}

void	key_right_event(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos + 1;
	next_tile = view->map->map[view->player->pos->z + 1];
	exit_door(view, view->map->map[next_pos]);
	if (next_tile != '1' && next_tile != 'E')
	{
		is_monster(view, next_tile);
		is_coins_taken(next_pos, view);
		view->player->steps += 1;
		view->map->map[prev_pos] = '0';
		view->map->map[next_pos] = 'P';
		view->player->pos->x += TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
}

void	key_left_event(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos - 1;
	next_tile = view->map->map[view->player->pos->z - 1];
	exit_door(view, view->map->map[next_pos]);
	if (next_tile != '1' && next_tile != 'E' && next_tile != 'M')
	{
		is_monster(view, next_tile);
		is_coins_taken(next_pos, view);
		view->player->steps += 1;
		view->map->map[prev_pos] = '0';
		view->map->map[next_pos] = 'P';
		view->player->pos->x -= TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
}

void	key_up_event(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos - (view->x + 1);
	next_tile = view->map->map[view->player->pos->z - (view->x + 1)];
	exit_door(view, view->map->map[next_pos]);
	if (next_tile != '1' && next_tile != 'E')
	{
		is_monster(view, next_tile);
		is_coins_taken(next_pos, view);
		view->player->steps += 1;
		view->map->map[prev_pos] = '0';
		view->map->map[next_pos] = 'P';
		view->player->pos->y -= TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-left/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
}

void	key_down_event(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->player->pos->z;
	next_pos = prev_pos + (view->x + 1);
	next_tile = view->map->map[view->player->pos->z + (view->x + 1)];
	exit_door(view, view->map->map[next_pos]);
	if (next_tile != '1' && next_tile != 'E')
	{
		is_monster(view, next_tile);
		is_coins_taken(next_pos, view);
		view->player->steps += 1;
		view->map->map[prev_pos] = '0';
		view->map->map[next_pos] = 'P';
		view->player->pos->y += TILE_SIZE;
		set_player_pos(view);
	}
	init_tile("./img/xpm/player/walk-right/P.1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
}
