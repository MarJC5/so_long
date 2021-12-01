/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:43:11 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/01 08:09:41 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_char(char **result)
{
	int	i;

	i = -1;
	while ((*result)[++i])
	{
		if ((*result)[i] != 'E' && (*result)[i] != 'P' &&
			(*result)[i] != 'C' && (*result)[i] != '1' &&
			(*result)[i] != '0' && (*result)[i] != '\n' &&
			(*result)[i] != 'M')
			return (0);
	}
	return (1);
}

static int	check_map_validity(char **result)
{
	if (!check_map_char(result))
	{
		printf("Error\nThe map content isn't valid, must be (E,P,C,1,0).\n");
		return (0);
	}
	if (!ft_strchr(*result, 'E'))
		printf("Error\nThe map doesn't have a valid exit (E).\n");
	else if (!ft_strchr(*result, 'P'))
		printf("Error\nThe map doesn't have a valid player position (P).\n");
	else if (!ft_strchr(*result, 'C'))
		printf("Error\nThe map doesn't have a collectible (C).\n");
	else if (!ft_strchr(*result, '1'))
		printf("Error\nThe map doesn't have walls (1).\n");
	else if (!ft_strchr(*result, '0'))
		printf("Error\nThe map doesn't have ground (0).\n");
	else
		return (1);
	return (0);
}

int	check_map_name(char *str)
{
	char	*ext;
	char	*vext;

	vext = ".ber";
	if (!ft_strrchr(str, '.') || ft_words_count(str, '.') < 2)
		return (0);
	ext = ft_strrchr(str, '.');
	if (ft_strnstr(ext, vext, ft_strlen(ext))
		&& ft_strlen(ext) == ft_strlen(vext))
		return (1);
	return (0);
}

void	process_map_file(int fd, char **save)
{
	int		height;
	int		width;
	char	*result;

	width = 0;
	height = 0;
	if (fd == -1)
		printf("Error\nCannot open the file.\n");
	else
	{
		result = get_next_line(fd);
		width = ft_strchr_pos(result, '\n');
		while (result != NULL)
		{
			height++;
			*save = ft_strjoin(*save, result);
			check_map_shape(width, result, save);
			result = get_next_line(fd);
		}
		if (check_map_validity(save) &&
			check_map_walls(ft_strchr(*save, '1'),
				*save, width))
			init_win(width, height, save);
	}
	free_ptr(save);
}
