/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:36:42 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/01 09:45:57 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_monster_pos(t_view *view)
{
	char	*map;
	int		m_pos;

	map = view->map->map;
	m_pos = ft_strchr_pos(view->map->map, 'M');
	if (ft_strchr(view->map->map, 'M'))
	{
		map[m_pos] = 'M';
		set_monster_pos(view);
		set_static_items(view, "./img/xpm/monster/M.0.xpm", 'M');
	}
}

void	kill_monster_pos(t_view *view)
{
	char	*map;

	map = view->map->map;
	set_monster_pos(view);
	set_static_items(view, "./img/xpm/tiles/1.1.xpm", 'M');
	map[view->monster->pos->z] = '0';
	shot_sound();
	printf("\n\033[1;35mYou've killed a snake.\033[0m\n\n");
}

void	monster_cases(t_view *view, char *map, int monster_pos)
{
	int	top;
	int	bottom;
	int	left;
	int	right;

	top = map[monster_pos - (view->x + 1)];
	bottom = map[monster_pos + (view->x + 1)];
	left = map[monster_pos - 1];
	right = map[monster_pos + 1];
	if (right == '0')
		move_monster_right(view);
	else if ((top == '0' && bottom != '0' && right != '0') || top == '0')
		move_monster_up(view);
	else if ((bottom == '0' && top != '0' && left != '0') || bottom == '0')
		move_monster_down(view);
	else if (left != '0' && top != '0' && right != '0')
		move_monster_down(view);
	else if (left == '0')
		move_monster_left(view);
}
