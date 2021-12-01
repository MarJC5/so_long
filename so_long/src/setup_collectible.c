/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:26 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/01 09:45:53 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_coins(t_view *view)
{
	int	i;

	i = -1;
	view->map->coin->count = 0;
	while ((view->map->map)[++i])
		if (view->map->map[i] == 'C')
			view->map->coin->count += 1;
}

void	is_coins_taken(int position, t_view *view)
{
	if (view->map->map[position] == 'C' && view->map->coin->count > 0)
	{
		view->player->coins += 1;
		view->map->coin->count -= 1;
		printf("\n\033[1;33mYou've found some coins.\033[0m\n\n");
		coins_sound();
	}
	if (view->map->coin->count == 0)
		open_door(view);
}

void	open_door(t_view *view)
{
	int	pos_x;
	int	pos_y;

	pos_x = view->player->pos->x;
	pos_y = view->player->pos->y;
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'E');
	set_static_items(view, "./img/xpm/exit/E.1.xpm", 'E');
	init_tile("./img/xpm/tiles/1.1.xpm", pos_x, pos_y, view);
}

void	exit_door(t_view *view, int next_tile)
{
	if (next_tile == 'E' && view->map->coin->count == 0)
	{
		mlx_clear_window(view->mlx, view->win);
		printf("\n\033[1;32mWell done!\033[0m\n\n");
		esc_win(view);
	}
}
