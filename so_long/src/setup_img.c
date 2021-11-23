/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:14:45 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 14:20:57 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tile(char *tile, int x, int y, t_view *view)
{
	mlx_put_image_to_window(view->mlx, view->win, tile, x, y);
	return (1);
}

int	set_background(t_view *view, char *tile)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (view->y > ++y)
	{
		while (view->x > ++x)
			init_tile(tile, x * TILE_SIZE, y * TILE_SIZE, view);
		x = -1;
	}
	return (1);
}

int	set_static_items(t_view *view, char *tile, int c)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (view->y > ++y)
	{
		while ((view->map.map)[++i] && view->x > ++x)
			if ((view->map.map)[i] == c)
				init_tile(tile, x * TILE_SIZE, y * TILE_SIZE, view);
		x = -1;
	}
	return (1);
}
