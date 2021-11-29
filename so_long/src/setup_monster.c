/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:36:42 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/29 07:54:12 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_monster_up(t_view *view, int prev_pos, int next_pos)
{
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x -= TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.1.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}

static void	move_monster_down(t_view *view, int prev_pos, int next_pos)
{
	view->map->map[prev_pos] = '0';
	view->map->map[next_pos] = 'M';
	view->monster->pos->x += TILE_SIZE;
	set_monster_pos(view);
	init_tile("./img/xpm/monster/M.0.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
}

void	init_monster_move(t_view *view)
{
	int	prev_pos;
	int	next_pos;
	int	next_tile;

	prev_pos = view->monster->pos->z;
	next_pos = prev_pos - 1;
	next_tile = view->map->map[view->monster->pos->z - 1];
	if (next_tile != '1' && next_tile != 'E' && next_tile != 'C')
		move_monster_up(view, prev_pos, next_pos);
	else if (next_tile == '1' && next_tile == 'E' && next_tile == 'C')
		move_monster_down(view, prev_pos, next_pos);
	printf("%s", view->map->map);
}

void	init_monster_pos(t_view *view)
{
	char	*map;
	int		map_coin;

	map = view->map->map;
	map_coin = ft_strchr_pos(view->map->map, 'C');
	if (map[map_coin - 1] != '1' || map[map_coin - 1] != 'E')
		map[map_coin - 1] = 'M';
	else if (map[map_coin + 1] != '1' || map[map_coin + 1] != 'E')
		map[map_coin - 1] = 'M';
	set_monster_pos(view);
	set_static_items(view, "./img/xpm/monster/M.1.xpm", 'M');
}
