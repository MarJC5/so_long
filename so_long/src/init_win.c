/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 01:01:41 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_pos(t_view *view)
{
	set_static_items(view, "./img/xpm/player/walk-right/P.1.0.xpm", 'P');
	set_player_pos(view);
	return (1);
}

int	init_tile_map(t_view *view)
{
	ft_putendl_fd(view->map->map, 1);
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'G');
	set_static_items(view, "./img/xpm/tiles/1.0.xpm", '1');
	init_player_pos(view);
	return (1);
}

int	init_struct(t_view *view)
{
	view->map = malloc(sizeof(t_map));
	view->map->coin = malloc(sizeof(t_coin));
	view->player = malloc(sizeof(t_player));
	view->player->pos = malloc(sizeof(t_pos));
	return (1);
}

int	init_win(int size_x, int size_y, char **map)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		return (0);
	init_struct(view);
	view->x = size_x;
	view->y = size_y;
	view->map->map = *map;
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx,
			view->x * TILE_SIZE, view->y * TILE_SIZE, "Indiana Jean");
	init_tile_map(view);
	mlx_loop_hook(view->mlx, render_next_key_event, view);
	mlx_loop(view->mlx);
	return (1);
}
