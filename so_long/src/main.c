/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:26:56 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/25 09:47:26 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *map)
{
	int			fd;
	static char	*save;

	if (!save)
		save = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (check_map_name(map))
		process_map_file(fd, &save);
	else
		ft_putendl_fd(MAP_ARG_NAME_ERROR, 2);
	free(save);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_putendl_fd(MAP_ARG_NAME_MISSING, 2);
	else
		so_long(argv[1]);
	return (0);
}
