/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:25:17 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/24 01:02:16 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

/*
* Globals
*/

# define MAP_ARG_NAME_MISSING "Enter a map \033[1;32m*.ber\033[0m as argument"
# define MAP_ARG_NAME_ERROR "Wrong map extension, must be \033[1;32m*.ber\033[0m"
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_TOP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123
# define TILE_SIZE 32

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1000
# endif

/*
* Struct
*/

typedef struct s_pos {
	int			x;
	int			y;
}				t_pos;

typedef struct s_player {
	char	*idle_0;
	char	*idle_1;
	char	*idle_2;
	char	*idle_3;
	char	*idle_4;
	char	*idle_5;
	char	*idle_6;
	char	*idle_7;
	char	*walk_r0;
	char	*walk_r1;
	char	*walk_r2;
	char	*walk_r3;
	char	*walk_r4;
	char	*walk_r5;
	char	*walk_r6;
	char	*walk_r7;
	char	*walk_l0;
	char	*walk_l1;
	char	*walk_l2;
	char	*walk_l3;
	char	*walk_l4;
	char	*walk_l5;
	char	*walk_l6;
	char	*walk_l7;
	t_pos	*pos;
}				t_player;

typedef struct s_coin {
	char		*coin_0;
	char		*coin_1;
	char		*coin_2;
	char		*coin_3;
	char		*coin_4;
	char		*coin_5;
	t_pos		*pos;
}				t_coin;

typedef struct s_map {
	char		*map;
	char		*wall;
	char		*ground;
	char		*exit_open;
	char		*exit_close;
	t_coin		*coin;
}				t_map;

typedef struct s_view {
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_map		*map;
	t_player	*player;
}				t_view;

/*
* Key events
*/

int		render_next_key_event(t_view *view);
int		key_event(int keyvalue, t_view *view);
int		key_right_event(int key, t_view *view);
int		key_left_event(int key, t_view *view);
int		key_up_event(int key, t_view *view);
int		key_down_event(int key, t_view *view);
int		key_esc_win(int key, t_view *view);

/*
* Window
*/

int		init_tile(char *tile, int x, int y, t_view *view);
int		init_win(int size_x, int size_y, char **map);
int		init_player_pos(t_view *view);

/*
* Tile
*/

int		set_static_items(t_view *view, char *tile, int c);
int		set_player_pos(t_view *view);

/*
* Map
*/

int		check_map_name(char *str);
int		process_map_file(int fd, char **save);
char	*get_next_line(int fd);

/*
* Player
*/

int		move_player(t_view *view, char *sprites);

/*
* Utils
*/

int		ft_strchr_pos(const char *str, int c);

/*
* Game
*/

void	so_long(char *map);

#endif
