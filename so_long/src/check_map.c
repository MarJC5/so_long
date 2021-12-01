/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 07:52:30 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/01 09:15:59 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_walls(char **map, int width)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(*map) - 1;
	while (++i < width)
	{
		if ((*map)[i] != '1' || (*map)[j--] != '1')
		{
			printf("Error\nThe map isn't closed/surrounded by walls.\n");
			return (0);
		}
	}
	return (1);
}

void	check_map_walls_border(char **map, char *line, int width)
{
	int		i;

	i = -1;
	while (++i < width)
	{
		if ((line[0] != '1' || line[width - 1] != '1'))
		{
			printf("Error\nThe map isn't closed/surrounded by walls.\n");
			free_ptr(map);
			exit(0);
		}
	}
}

void	check_map_shape(int width, char *line, char **save)
{
	int	last;

	last = (int)ft_strlen(line) - 1;
	check_map_walls_border(save, line, width);
	if (line[last] != '\n')
		last += 1;
	if (width != last)
	{
		printf("Error\nThe map isn't rectangular.\n");
		free_ptr(save);
		exit(0);
	}
}
