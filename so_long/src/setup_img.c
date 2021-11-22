/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:14:45 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 00:20:12 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_background(t_view *view)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (view->y > ++y)
	{
		while (view->x > ++x)
			init_tile("./img/xpm/tiles/1.1.xpm",
				x * TILE_SIZE, y * TILE_SIZE, view);
		x = -1;
	}
	return (1);
}

int	set_items(t_view *view, char **map, char *filepath, int c)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (view->y > ++y)
	{
		while ((*map)[++i] && view->x > ++x)
			if ((*map)[i] == c)
				init_tile(filepath,
				x * TILE_SIZE, y * TILE_SIZE, view);
		x = -1;
	}
	return (1);
}
