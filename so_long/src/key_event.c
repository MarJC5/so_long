/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:31 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 10:25:58 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keyvalue, t_view *view)
{
	if (keyvalue == KEY_ESC)
		key_esc_win(keyvalue, view);
	else if (keyvalue == KEY_W || keyvalue == KEY_TOP)
		key_up_event(keyvalue, view);
	else if (keyvalue == KEY_A || keyvalue == KEY_LEFT)
		key_left_event(keyvalue, view);
	else if (keyvalue == KEY_S || keyvalue == KEY_DOWN)
		key_down_event(keyvalue, view);
	else if (keyvalue == KEY_D || keyvalue == KEY_RIGHT)
		key_right_event(keyvalue, view);
	else
		idle_event(view);
	return (keyvalue);
}

int	idle_event(t_view *view)
{
	(void) view;
	return (1);
}

int	render_next_key_event(t_view *view)
{
	mlx_hook(view->win, 2, 1L << 0, key_event, &view);
	return (1);
}
