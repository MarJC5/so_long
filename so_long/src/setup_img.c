/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:14:45 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/26 09:57:47 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tile(char *path, int x, int y, t_view *view)
{
	int		w;
	int		h;
	char	*img;

	img = mlx_xpm_file_to_image(view->mlx, path, &w, &h);
	mlx_put_image_to_window(view->mlx, view->win, img, x, y);
}

void	set_static_items(t_view *view, char *tile, int c)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (view->y > ++y)
	{
		while ((view->map->map)[++i] && view->x > ++x)
		{
			if ((view->map->map)[i] == c || c == 'G')
				init_tile(tile, x * TILE_SIZE, y * TILE_SIZE, view);
		}
		x = -1;
	}
}
