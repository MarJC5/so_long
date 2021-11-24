/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:26 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 17:31:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	detect_tile_info(t_view *view, int keyvalue)
{
	ft_putendl_fd("\nOld----", 1);
	ft_putnbr_fd(view->player->pos->z, 1);
	if (keyvalue == KEY_W || keyvalue == KEY_TOP)
		view->player->pos->z -= view->x;
	else if (keyvalue == KEY_A || keyvalue == KEY_LEFT)
		view->player->pos->z -= 1;
	else if (keyvalue == KEY_S || keyvalue == KEY_DOWN)
		view->player->pos->z += view->x;
	else if (keyvalue == KEY_D || keyvalue == KEY_RIGHT)
		view->player->pos->z += 1;
	ft_putendl_fd("\nNew----", 1);
	ft_putnbr_fd(view->player->pos->z, 1);
	return (keyvalue);
}
