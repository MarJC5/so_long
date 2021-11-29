/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_audio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:39:17 by jmartin           #+#    #+#             */
/*   Updated: 2021/11/30 00:18:19 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	theme_sound(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "0.2", "sound/cave_theme.wav", NULL);
}

void	miss_shot_sound(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "0.2", "sound/click.wav", NULL);
}

void	shot_sound(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "0.2", "sound/shot.wav", NULL);
}

void	coins_sound(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "0.2", "sound/coins.wav", NULL);
}

void	door_sound(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "0.2", "sound/door.wav", NULL);
}
