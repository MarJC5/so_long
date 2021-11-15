/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:43:11 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/14 18:19:03 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	process_map_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("Cannot open the file.", 2);
	else
	{
		get_next_line(fd);
		return (1);
	}
	if (close(fd) == -1)
		ft_putendl_fd("Error, cannot close the file.", 2);
	return (0);
}