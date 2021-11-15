/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:31 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/14 17:26:26 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keyvalue, t_view *view)
{
	if (keyvalue == KEY_ESC)
		key_esc_win(keyvalue, view);
	else if (keyvalue == KEY_W)
		key_up_event(keyvalue);
	else if (keyvalue == KEY_A)
		key_left_event(keyvalue);
	else if (keyvalue == KEY_S)
		key_down_event(keyvalue);
	else if (keyvalue == KEY_D)
		key_right_event(keyvalue);
	return (keyvalue);
}

int	render_next_key_event(t_view *view)
{
	mlx_hook(view->win, 2, 1L << 0, key_event, &view);
	return (1);
}
