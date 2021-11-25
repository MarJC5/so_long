/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:31 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/25 11:07:26 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int key, t_view *view)
{
	int	position;

	position = view->map->map[view->player->pos->z];
	init_tile("./img/xpm/tiles/1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	if (key == KEY_ESC)
		esc_win(view);
	else if (key == KEY_W || key == KEY_TOP)
		key_up_event(position, view);
	else if (key == KEY_A || key == KEY_LEFT)
		key_left_event(position, view);
	else if (key == KEY_S || key == KEY_DOWN)
		key_down_event(position, view);
	else if (key == KEY_D || key == KEY_RIGHT)
		key_right_event(position, view);
	return (key);
}

int	render_next_key_event(t_view *view)
{
	mlx_hook(view->win, 2, 1L << 0, key_event, view);
	return (1);
}
