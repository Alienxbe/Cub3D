/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:43:50 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 14:31:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "raycast.h"

void	raycast_update(t_game *game)
{
	size_t	i;
	float	angle;

	angle = game->player.view_angle - (PLAYER_FOV / 2);
	i = -1;
	while (++i < WIN_WIDTH)
	{
		game->rays[i].dir = (t_fpoint){cos(angle), sin(angle)};
		game->rays[i].angle = angle;
		game->rays[i].corr_angle = cos(angle - game->player.view_angle);
		raycast(game, &game->rays[i]);
		angle += game->ray_angle_step;
	}
}