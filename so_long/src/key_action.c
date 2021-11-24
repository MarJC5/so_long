/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:15 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 17:08:21 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc_win(int key, t_view *view)
{
	free(view);
	exit(0);
	return (key);
}

int	key_right_event(int key, t_view *view)
{
	init_tile("./img/xpm/tiles/1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	detect_tile_info(view, key);
	view->player->pos->x += (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-right/P.1.1.xpm");
	return (key);
}

int	key_left_event(int key, t_view *view)
{
	init_tile("./img/xpm/tiles/1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	detect_tile_info(view, key);
	view->player->pos->x -= (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-left/P.1.1.xpm");
	return (key);
}

int	key_up_event(int key, t_view *view)
{
	init_tile("./img/xpm/tiles/1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	detect_tile_info(view, key);
	view->player->pos->y -= (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-left/P.1.1.xpm");
	return (key);
}

int	key_down_event(int key, t_view *view)
{
	init_tile("./img/xpm/tiles/1.1.xpm", view->player->pos->x, view->player->pos->y, view);
	detect_tile_info(view, key);
	view->player->pos->y += (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-right/P.1.1.xpm");
	return (key);
}
