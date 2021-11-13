/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:26:56 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/13 22:07:03 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please enter a map name as argument: ");
		printf("\033[0;33msmall.ber\033[0m or \033[0;32mlarge.ber\033[0m\n");
	}
	else
		printf("%s", argv[1]);
	return (0);
}
