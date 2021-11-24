/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:15 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 00:28:42 by jmartin          ###   ########.fr       */
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
	view->player->pos->x += (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-right/P.1.1.xpm");
	ft_putnbr_fd(view->player->pos->x, 1);
	ft_putendl_fd(" - RIGHT", 1);
	return (key);
}

int	key_left_event(int key, t_view *view)
{
	view->player->pos->x -= (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-left/P.1.1.xpm");
	ft_putnbr_fd(view->player->pos->x, 1);
	ft_putendl_fd(" - LEFT", 1);
	return (key);
}

int	key_up_event(int key, t_view *view)
{
	view->player->pos->y -= (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-left/P.1.1.xpm");
	ft_putnbr_fd(view->player->pos->y, 1);
	ft_putendl_fd(" - UP", 1);
	return (key);
}

int	key_down_event(int key, t_view *view)
{
	view->player->pos->y += (1 * TILE_SIZE);
	move_player(view, "./img/xpm/player/walk-right/P.1.1.xpm");
	ft_putnbr_fd(view->player->pos->y, 1);
	ft_putendl_fd(" - DOWN", 1);
	return (key);
}
