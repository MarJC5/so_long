/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 09:47:19 by jmartin          ###   ########.fr       */
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
	printf("\n\033[1;36mCurrent map:\033[0m\n\n%s\n",
		view->map->map);
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'G');
	set_static_items(view, "./img/xpm/tiles/1.0.xpm", '1');
	set_static_items(view, "./img/xpm/exit/E.0.xpm", 'E');
	set_static_items(view, "./img/xpm/coin/C.0.xpm", 'C');
	init_monster_pos(view);
	init_player_pos(view);
	count_coins(view);
	printf("\n\033[1;34mPlayer stats:\033[0m\n\n");
	counter_event(view);
	view->player->steps += 1;
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
	theme_sound();
	init_tile_map(view);
	mlx_loop_hook(view->mlx, render_next_key_event, view);
	mlx_loop(view->mlx);
	free_view_struct(view);
	return (0);
}
