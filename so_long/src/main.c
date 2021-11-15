/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:26:56 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/14 18:19:00 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *map)
{
	if (check_map_name(map))
		process_map_file(map);
		//init_win(640, 480);
	else
		ft_putendl_fd(MAP_ARG_NAME_ERROR, 2);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_putendl_fd(MAP_ARG_NAME_MISSING, 2);
	else
		so_long(argv[1]);
	return (0);
}
