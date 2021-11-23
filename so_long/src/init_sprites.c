/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:15:10 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/23 14:12:13 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map_tiles(t_view *view, int *img_width, int *img_height)
{
	view->map.wall = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/tiles/1.0.xpm", img_width, img_height);
	view->map.ground =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/tiles/1.1.xpm", img_width, img_height);
	view->map.exit_close =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/exit/E.0.xpm", img_width, img_height);
	view->map.exit_open = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/exit/E.1.xpm", img_width, img_height);
	view->map.coin.coin_0 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.0.xpm", img_width, img_height);
	view->map.coin.coin_1 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.1.xpm", img_width, img_height);
	view->map.coin.coin_2 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.2.xpm", img_width, img_height);
	view->map.coin.coin_3 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.3.xpm", img_width, img_height);
	view->map.coin.coin_4 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.4.xpm", img_width, img_height);
	view->map.coin.coin_5 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/coin/C.5.xpm", img_width, img_height);
	return (1);
}

int	init_player_walk(t_view *view, int *img_width, int *img_height)
{
	view->player.walk_0 = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.0.xpm", img_width, img_height);
	view->player.walk_1 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.1.xpm", img_width, img_height);
	view->player.walk_2 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.2.xpm", img_width, img_height);
	view->player.walk_3 = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.3.xpm", img_width, img_height);
	view->player.walk_4 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.4.xpm", img_width, img_height);
	view->player.walk_5 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.5.xpm", img_width, img_height);
	view->player.walk_6 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.6.xpm", img_width, img_height);
	view->player.walk_7 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/walk/P.1.7.xpm", img_width, img_height);
	return (1);
}

int	init_player_idle(t_view *view, int *img_width, int *img_height)
{
	view->player.walk_0 = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.0.xpm", img_width, img_height);
	view->player.walk_1 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.1.xpm", img_width, img_height);
	view->player.walk_2 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.2.xpm", img_width, img_height);
	view->player.walk_3 = mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.3.xpm", img_width, img_height);
	view->player.walk_4 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.4.xpm", img_width, img_height);
	view->player.walk_5 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.5.xpm", img_width, img_height);
	view->player.walk_6 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.6.xpm", img_width, img_height);
	view->player.walk_7 =  mlx_xpm_file_to_image(view->mlx,
			"./img/xpm/player/idle/P.0.7.xpm", img_width, img_height);
	return (1);
}

int	init_sprites(t_view *view, int *img_width, int *img_height)
{
	init_player_walk(view, img_width, img_height);
	init_player_idle(view, img_width, img_height);
	init_map_tiles(view, img_width, img_height);
	return (1);
}
