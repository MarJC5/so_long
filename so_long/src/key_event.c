/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:58:31 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/29 07:42:50 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter_event(t_view *view)
{
	char	*coins;
	char	*steps;
	char	*full;

	coins = ft_strjoin("Coins: ", ft_itoa(view->player->coins, 10));
	steps = ft_strjoin(" - Steps: ", ft_itoa(view->player->steps, 10));
	full = ft_strjoin(coins, steps);
	ft_putendl_fd(full, 1);
	init_tile("./img/xpm/panel/S.0.xpm",
		(view->x / 2) * TILE_SIZE - 70, 5, view);
	mlx_string_put(view->mlx, view->win,
		(view->x / 2) * TILE_SIZE - 60, 20, 0x00000000, full);
	free_ptr(&coins);
	free_ptr(&steps);
	free_ptr(&full);
}

int	esc_win(t_view *view)
{
	if (view->map->coin->count > 0)
		printf("\n\033[1;31mYou've quit the game!\033[0m\n\n");
	exit(0);
	return (0);
}

int	key_event(int key, t_view *view)
{
	counter_event(view);
	init_tile("./img/xpm/tiles/1.1.xpm",
		view->monster->pos->x, view->monster->pos->y, view);
	init_tile("./img/xpm/tiles/1.1.xpm",
		view->player->pos->x, view->player->pos->y, view);
	init_monster_move(view);
	if (key == KEY_ESC)
		esc_win(view);
	else if (key == KEY_W || key == KEY_TOP)
		key_up_event(view);
	else if (key == KEY_A || key == KEY_LEFT)
		key_left_event(view);
	else if (key == KEY_S || key == KEY_DOWN)
		key_down_event(view);
	else if (key == KEY_D || key == KEY_RIGHT)
		key_right_event(view);
	return (key);
}

int	render_next_key_event(t_view *view)
{
	mlx_hook(view->win, 17, 0L << 0, esc_win, view);
	mlx_hook(view->win, 2, 1L << 0, key_event, view);
	return (0);
}
