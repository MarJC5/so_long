/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 00:47:11 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tile(char *path, int x, int y, t_view *view)
{
	int		img_width;
	int		img_height;
	void	*tile;

	tile = mlx_xpm_file_to_image(view->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(view->mlx, view->win, tile, x, y);
	return ((unsigned long)tile);
}

int	init_tile_map(t_view *view, char **map)
{
	ft_putendl_fd(*map, 1);
	set_background(view);
	set_items(view, map, "./img/xpm/tiles/1.0.xpm", '1');
	set_items(view, map, "./img/xpm/exit/E.0.xpm", 'E');
	set_items(view, map, "./img/xpm/coin/C.0.xpm", 'C');
	set_items(view, map, "./img/xpm/player/idle/P.0.0.xpm", 'P');
	return (1);
}

int	init_win(int size_x, int size_y, char **map)
{
	t_view	view;

	view.mlx = mlx_init();
	view.x = size_x;
	view.y = size_y;
	view.win = mlx_new_window(view.mlx,
			view.x * TILE_SIZE, view.y * TILE_SIZE, "Indiana Jean");
	init_tile_map(&view, map);
	mlx_loop_hook(view.mlx, render_next_key_event, &view);
	mlx_loop(view.mlx);
	return (1);
}
