/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:25:17 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 09:51:12 by jmartin          ###   ########.fr       */
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
# define KEY_F 3
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
	int			z;
}				t_pos;

typedef struct s_player {
	int		steps;
	int		coins;
	t_pos	*pos;
}				t_player;

typedef struct s_monster{
	t_pos	*pos;
}				t_monster;

typedef struct s_coin {
	char		*img;
	int			count;
}				t_coin;

typedef struct s_map {
	char		*map;
	t_coin		*coin;
}				t_map;

typedef struct s_view {
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_map		*map;
	t_player	*player;
	t_monster	*monster;
}				t_view;

/*
* Key events
*/

void	key_right_event(t_view *view);
void	key_left_event(t_view *view);
void	key_up_event(t_view *view);
void	key_down_event(t_view *view);
void	key_fire_event(t_view *view);
int		key_esc_win(int key, t_view *view);
int		render_next_key_event(t_view *view);
int		esc_win(t_view *view);

/*
* Tile
*/

void	init_tile(char *tile, int x, int y, t_view *view);
void	set_static_items(t_view *view, char *tile, int c);

/*
* Map
*/
void	process_map_file(int fd, char **save);
void	open_door(t_view *view);
void	exit_door(t_view *view, int next_tile);
char	*get_next_line(int fd);
int		check_map_name(char *str);

void	monster_cases(t_view *view, char *map, int monster_pos);
void	init_monster_pos(t_view *view);
void	set_monster_pos(t_view *view);
void	move_monster_right(t_view *view);
void	move_monster_left(t_view *view);
void	move_monster_up(t_view *view);
void	move_monster_down(t_view *view);
void	kill_monster_pos(t_view *view);

void	set_player_pos(t_view *view);

void	check_map_shape(int width, char *line, char **save);
int		check_map_walls(char **map, int width);
void	check_map_walls_border(char **map, char *line, int width);

/*
* Utils
*/

void	counter_event(t_view *view);
void	count_coins(t_view *view);
void	is_coins_taken(int position, t_view *view);

void	init_struct(t_view *view);
void	free_ptr(char **ptr);
void	free_view_struct(t_view *view);
int		ft_strchr_pos(const char *str, int c);

/*
* Audio
*/

void	theme_sound(void);
void	door_sound(void);
void	miss_shot_sound(void);
void	shot_sound(void);
void	coins_sound(void);

/*
* Game
*/

void	so_long(char *map);
int		init_win(int size_x, int size_y, char **map);

#endif
