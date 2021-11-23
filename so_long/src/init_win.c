/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 14:20:43 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tile_map(t_view *view)
{
	int	img_width;
	int	img_height;

	ft_putendl_fd(view->map.map, 1);
	init_sprites(view, &img_width, &img_height);
	set_background(view, view->map.ground);
	set_static_items(view, view->map.wall, '1');
	set_static_items(view, view->map.exit_close, 'E');
	set_static_items(view, view->player.walk_0, 'P');
	return (1);
}

int	init_win(int size_x, int size_y, char **map)
{
	t_view	view;

	view.mlx = mlx_init();
	view.x = size_x;
	view.y = size_y;
	view.map.map = *map;
	view.win = mlx_new_window(view.mlx,
			view.x * TILE_SIZE, view.y * TILE_SIZE, "Indiana Jean");
	init_tile_map(&view);
	mlx_loop_hook(view.mlx, render_next_key_event, &view);
	mlx_loop(view.mlx);
	return (1);
}
