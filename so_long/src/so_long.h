/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:25:17 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/14 18:20:23 by jmartin          ###   ########.fr       */
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
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

/*
* Struct
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_view {
	void		*mlx;
	void		*win;
	//t_player	player;
	//t_enemy		enemy;
}				t_view;

typedef struct s_move {
	int		x;
	int		y;
}				t_move;

typedef struct s_player {
	t_view	*move;
}				t_player;

typedef struct s_enemy {
	t_view	*move;
}				t_enemy;


/*
* Key events
*/

int		render_next_key_event(t_view *view);
int		key_event(int keyvalue, t_view *view);
int		key_right_event(int key);
int		key_left_event(int key);
int		key_up_event(int key);
int		key_down_event(int key);
int		key_esc_win(int key, t_view *view);

/*
* Window
*/

int		init_win(int size_x, int size_y);
void	pixel_put(t_data *data, int x, int y, int color);

/*
* Map
*/

int		check_map_name(char *str);
int		process_map_file(char *path);
char	*get_next_line(int fd);

void	so_long(char *map);

#endif
