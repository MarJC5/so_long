/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:26 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/25 07:57:21 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(t_view *view)
{
	int i;

	i = -1;
	view->map->coin->count = 0;
	while ((view->map->map)[++i])
		if (view->map->map[i] == 'C')
			view->map->coin->count += 1;
	return (i);
}

int	is_coins_taken(int position, t_view *view)
{
	if (view->map->map[position] == 'C' && view->map->coin->count > 0)
	{
		view->map->map[position] = '0';
		view->map->coin->count -= 1;
	}
	if (view->map->coin->count == 0)
		open_door(view);
	return (1);
}

int	open_door(t_view *view)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd(view->map->map, 1);
	ft_putchar_fd(view->map->map[view->player->pos->z], 1);
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'E');
	set_static_items(view, "./img/xpm/exit/E.1.xpm", 'E');
	if (view->map->map[view->player->pos->z] == 'E' && view->map->coin->count > 0)
		mlx_clear_window(view->mlx, view->win);
	return (1);
}
