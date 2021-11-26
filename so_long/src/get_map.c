/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:43:11 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/26 11:05:13 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_validity(char **result)
{
	if (!ft_strchr(*result, 'E'))
		ft_putendl_fd("Error\nThe map doesn't have a valid exit (E).", 2);
	else if (!ft_strchr(*result, 'P'))
		ft_putendl_fd("Error\nThe map doesn't have a valid player position (P).",
			2);
	else if (!ft_strchr(*result, 'C'))
		ft_putendl_fd("Error\nThe map doesn't have a collectible (C).", 2);
	else if (!ft_strchr(*result, '1'))
		ft_putendl_fd("Error\nThe map doesn't have walls (1).", 2);
	else if (!ft_strchr(*result, '0'))
		ft_putendl_fd("Error\nThe map doesn't have ground (0).", 2);
	else
		return (1);
	exit (0);
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
	int			height;
	int			width;
	char		*result;

	width = 0;
	height = 0;
	if (fd == -1)
		ft_putendl_fd("Cannot open the file.", 2);
	else
	{
		result = get_next_line(fd);
		width = ft_strchr_pos(result, '\n');
		while (result != NULL)
		{
			*save = ft_strjoin(*save, result);
			result = get_next_line(fd);
			height++;
		}
		check_map_validity(save);
		init_win(width, height, save);
	}
}
