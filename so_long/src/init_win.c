/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/26 09:55:04 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_pos(t_view *view)
{
	set_static_items(view, "./img/xpm/player/idle/P.0.0.xpm", 'P');
	set_player_pos(view);
}

static void	init_tile_map(t_view *view)
{
	ft_putendl_fd(view->map->map, 1);
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'G');
	set_static_items(view, "./img/xpm/tiles/1.0.xpm", '1');
	set_static_items(view, "./img/xpm/exit/E.0.xpm", 'E');
	set_static_items(view, "./img/xpm/coin/C.0.xpm", 'C');
	init_player_pos(view);
	count_coins(view);
	counter_event(view);
}

static void	init_struct(t_view *view)
{
	view->map = malloc(sizeof(t_map));
	view->map->coin = malloc(sizeof(t_coin));
	view->player = malloc(sizeof(t_player));
	view->player->pos = malloc(sizeof(t_pos));
	view->player->steps = 0;
	view->player->coins = 0;
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
	return (0);
}
