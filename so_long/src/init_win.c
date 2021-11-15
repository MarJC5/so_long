/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:29:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/14 17:07:38 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_win(int size_x, int size_y)
{
	t_view	view;

	view.mlx = mlx_init();
	view.win = mlx_new_window(view.mlx, size_x, size_y, "moshi");
	mlx_loop_hook(view.mlx, render_next_key_event, &view);
	mlx_loop(view.mlx);
	return (1);
}
